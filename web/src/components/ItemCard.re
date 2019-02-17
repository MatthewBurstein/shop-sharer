let component = ReasonReact.statelessComponent("ItemCard");

let make = (~itemName, ~quantity, ~handleDelete, ~id, _children) => {
  ...component,
  render: _self =>{
    let deleteHelper = event => {
      ReactEvent.Mouse.preventDefault(event);
      handleDelete(id)
    };
    <div className="item-card">
      <strong> {ReasonReact.string("Item: ")} </strong>
      {ReasonReact.string(itemName)}
      <br />
      <strong> {ReasonReact.string("Quantity: ")} </strong>
      {ReasonReact.string(string_of_int(quantity))}
      <br />
      <a href="#" onClick={
        _self.handle((event, _) => {deleteHelper(event)})
      }>
        {ReasonReact.string("Delete item")}
      </a>
    </div>}
};
