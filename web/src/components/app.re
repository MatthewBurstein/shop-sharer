[%bs.raw {|require('../assets/stylesheets/app.css')|}];

[@bs.module] external logo : string = "./logo.svg";

let str = ReasonReact.string;
let elementArrayOfList = (listOfThings) => ReasonReact.array(Array.of_list(listOfThings))

type item = {
  name: string,
  quantity: int
};

type state = {
  items: list(item)
};

let component = ReasonReact.reducerComponent("App");

let make = (_children) => {
  ...component,
  initialState: () => {
    items: [
      {name: "Baked beans", quantity: 1}, 
      {name: "Toothepaste", quantity: 3}
      ]
  },
  reducer: ((), _) => ReasonReact.NoUpdate,
  render: ({state: {items}}) =>
    <div className="App">
      {elementArrayOfList(List.map((item) => {
        <ItemCard itemName=item.name quantity=item.quantity/>
      }, items))}
    </div>,
};
