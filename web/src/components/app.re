[%bs.raw {|require('../assets/stylesheets/app.css')|}];

open DataModel;
open ApiClient;

let str = ReasonReact.string;
let elementArrayOfList = listOfThings =>
  ReasonReact.array(Array.of_list(listOfThings));

type state =
  | Loading
  | Loaded(list(itemType))
  | LoadItemsFailed;

let getItemsFromState = currentState =>
  switch (currentState) {
  | Loading => []
  | Loaded(items) => items
  | LoadItemsFailed => []
  };

type action =
  | NewItem(itemType)
  | LoadItems
  | NewItems(list(itemType))
  | LoadItemsFailed
  | PostItem(itemType);

let component = ReasonReact.reducerComponent("App");

let getItems = currentState =>
  switch (currentState) {
  | Loading => []
  | Loaded(items) => items
  | LoadItemsFailed => []
  };

let make = _children => {
  ...component,
  initialState: () => Loaded([]),
  didMount: ({state, send}) => send(LoadItems),
  reducer: (action, state) =>
    switch (action) {
    | NewItem(newItem) =>
      ReasonReact.Update(Loaded([newItem, ...getItemsFromState(state)]))
    | NewItems(newItems) =>
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
                   | Some(items) => resolve(self.send(NewItems(items)))
                   | None => resolve(self.send(LoadItemsFailed))
                   }
                 )
              |> ignore
            )
        ),
      )
    | LoadItemsFailed => ReasonReact.NoUpdate
    | PostItem(item) => ReasonReact.UpdateWithSideEffects(
      Loading,
      (self => Js.Promise.(
        postItem(item)
        |> then_(result =>{
          Js.log(result);
          resolve(self.send(NewItem(item)))
        }
        )
        |> ignore
      ))
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
            List.mapi(
              (idx, item) =>
                <ItemCard
                  key={string_of_int(idx)}
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
