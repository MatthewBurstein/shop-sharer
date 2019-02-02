[%bs.raw {|require('../assets/stylesheets/app.css')|}];

open DataModel;
open ApiClient;

let str = ReasonReact.string;
let elementArrayOfList = (listOfThings) => ReasonReact.array(Array.of_list(listOfThings))

type state =
  | Loading
  | Loaded(list(item))

let getItems = currentState => {
  switch currentState {
    | Loading => []
    | Loaded(items) => items
  }
}

type action = 
  | NewItem(item)
  | LoadItems
  | NewItems(list(item))
  | LoadItemsFailed

let component = ReasonReact.reducerComponent("App");

let getItems = currentState => {
  switch currentState {
    | Loading => []
    | Loaded(items) => items
  }
}

let make = (_children) => {
  ...component,
  initialState: () => { Loaded([]) },
  didMount: ({state, send}) => {
    send(LoadItems)
  },
  reducer: (action, state) => switch action {
    | NewItem(newItem) => ReasonReact.Update(Loaded([newItem, ...getItems(state)]))
    | NewItems(newItems) => ReasonReact.Update(Loaded(List.concat([newItems, getItems(state)])))
    | LoadItems => ReasonReact.UpdateWithSideEffects(
      Loading,
      self => Js.Promise.(
        fetchItems()
        |> then_(result =>
          switch(result) {
            | Some(items) => resolve(self.send(NewItems(items)))
            | None => resolve(self.send(LoadItemsFailed))
          }
        )
        |> ignore
      )
    )
  },
  render: ({state, send}) => {
    switch state {
    | Loading =>  <p>{ReasonReact.string("loading")}</p>
    | Loaded(items) => {
      <div className="App">
        <NewItemForm submit=(newItem => send(NewItem(newItem)))/>
        {elementArrayOfList(List.mapi((idx, item) => {
          <ItemCard key=string_of_int(idx) itemName=item.name quantity=item.quantity/>
        }, items))}
      </div>
    }
  }
}
}
