let component = ReasonReact.statelessComponent("ItemCard");

let make = (~itemName, ~quantity, _children) => {
  ...component,
  render: _self =>
    <div className="item-card">
      <strong> {ReasonReact.string("Item: ")} </strong>
      {ReasonReact.string(itemName)}
      <br />
      <strong> {ReasonReact.string("Quantity: ")} </strong>
      {ReasonReact.string(string_of_int(quantity))}
    </div>,
};
