[%bs.raw {|require('../assets/stylesheets/app.css')|}];

open DataModel;
open ApiClient;

let str = ReasonReact.string;
let elementArrayOfList = listOfThings =>
  ReasonReact.array(Array.of_list(listOfThings));
let removeItemById = (id, items) => {
  List.filter(item => item.id != id, items)
}

type state =
  | Loading
  | Loaded(list(itemType))
  | LoadItemsFailed;

let getItemsFromState = currentState =>
  switch (currentState) {
  | Loaded(items) => items
  | _ => []
  };

type action =
  | AddItem(itemType)
  | LoadItems
  | AddItems(list(itemType))
  | LoadItemsFailed
  | PostItem(itemType)
  | DeleteItem(int)
  | RemoveItem(int);

let component = ReasonReact.reducerComponent("App");

let make = _children => {
  ...component,
  initialState: () => Loaded([]),
  didMount: ({state, send}) => send(LoadItems),
  reducer: (action, state) =>
    switch (action) {
    | AddItem(newItem) =>
      Js.log(state);
      ReasonReact.Update(
        Loaded(List.concat([getItemsFromState(state), [newItem]])),
      );
    | AddItems(newItems) =>
      ReasonReact.Update(
        Loaded(List.concat([newItems, getItemsFromState(state)])),
      )
    | LoadItems =>
      ReasonReact.UpdateWithSideEffects(
        Loading,
        (
          self =>
            Js.Promise.(
              fetchItems()
              |> then_(result => 
                   switch (result) {
                   | Some(items) => resolve(self.send(AddItems(items)))
                   | None => resolve(self.send(LoadItemsFailed))
                   }
                 )
              |> ignore
            )
        ),
      )
    | LoadItemsFailed => ReasonReact.NoUpdate
    | PostItem(item) =>
      ReasonReact.SideEffects(
        (
          self =>
            Js.Promise.(
              postItem(item)
              |> then_(result =>
                   switch (result) {
                   | Some(item) => resolve(self.send(AddItem(item)))
                   | None => resolve(self.send(LoadItemsFailed))
                   }
                 )
              |> ignore
            )
        ),
      )
    | RemoveItem(id) => ReasonReact.Update(Loaded(removeItemById(id, getItemsFromState(state))))
    | DeleteItem(id) => ReasonReact.SideEffects(
        (
          self =>
            Js.Promise.(
              deleteItemById(id)
              |> then_(response => resolve(self.send(RemoveItem(id)))
            )
            |> ignore
        ),
      ) 
    )
    },
  render: ({state, send}) =>
    switch (state) {
    | Loading => <h1> {ReasonReact.string("Loading...")} </h1>
    | LoadItemsFailed => <h1> {ReasonReact.string("Load failed :(")} </h1>
    | Loaded(items) =>
      <div className="App">
        <NewItemForm submit=(newItem => send(PostItem(newItem))) />
        {
          elementArrayOfList(
            List.map(
              item =>
                <ItemCard
                  handleDelete={id => send(DeleteItem(id))}
                  id={item.id}
                  itemName={item.name}
                  quantity={item.quantity}
                />,
              items,
            ),
          )
        }
      </div>
    },
};
