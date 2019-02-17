open DataModel;

type action =
  | EditName(string)
  | EditQuantity(string);

let component = ReasonReact.reducerComponent("NewItemForm");

let make = (~submit, _children) => {
  ...component,
  initialState: () => {name: "", quantity: 0, id: 0},
  reducer: (action, state) =>
    switch (action) {
    | EditName(value) => ReasonReact.Update({...state, name: value})
    | EditQuantity(value) =>
      ReasonReact.Update({...state, quantity: int_of_string(value)})
    },
  render: ({send, state}) => {
    let {name, quantity} = state;
    let submitHelper = event => {
      ReactEvent.Mouse.preventDefault(event);
      submit(state);
    };
    <div className="item-card">
      <form>
        <input
          value=name
          onChange={
            event => send(EditName(ReactEvent.Form.target(event)##value))
          }
        />
        <input
          type_="number"
          value={string_of_int(quantity)}
          onChange={
            event =>
              send(EditQuantity(ReactEvent.Form.target(event)##value))
          }
        />
        <button onClick={event => submitHelper(event)}>
          {ReasonReact.string("Submit")}
        </button>
      </form>
    </div>;
  },
};
