[%bs.raw {|require('../assets/stylesheets/app.css')|}];

[@bs.module] external logo : string = "./logo.svg";

let str = ReasonReact.string;
let elementArrayOfList = (listOfThings) => ReasonReact.array(Array.of_list(listOfThings))

type item = {
  name: string,
  quantity: int
}

let newItem = ({name, quantity}): item => {name, quantity}

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
  reducer: (action, state) => switch action {
    | NewItem(formState) => ReasonReact.Update({items:[newItem(formState), ...state.items]})
  },
  render: ({state, send}) => {
    let { items } = state;
    <div className="App">
      <NewItemForm submit={formState => send(NewItem(formState))}/>

      {elementArrayOfList(List.map((item) => {
        <ItemCard itemName=item.name quantity=item.quantity/>
      }, items))}
    </div>
  }
};
