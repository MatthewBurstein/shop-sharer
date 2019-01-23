[%bs.raw {|require('../assets/stylesheets/app.css')|}];

[@bs.module] external logo : string = "./logo.svg";

open DataModel;
open ApiClient;

let str = ReasonReact.string;
let elementArrayOfList = (listOfThings) => ReasonReact.array(Array.of_list(listOfThings))

type state = {
  items: list(item)
};

type action = 
  | NewItem(item)

let component = ReasonReact.reducerComponent("App");

let make = (_children) => {
  ...component,
  initialState: () => {
    items: [
      {name: "Baked beans", quantity: 1}, 
      {name: "Toothepaste", quantity: 3}
      ]
  },
  didMount: ({state, send}) => {
    fetchItems(send)
  },
  reducer: (action, state) => switch action {
    | NewItem(newItem) => ReasonReact.Update({items:[newItem, ...state.items]})
  },
  render: ({state, send}) => {
    let { items } = state;
    <div className="App">
      <NewItemForm submit=(newItem => send(NewItem(newItem)))/>

      {elementArrayOfList(List.mapi((idx, item) => {
        <ItemCard key=string_of_int(idx) itemName=item.name quantity=item.quantity/>
      }, items))}
    </div>
  }
}
