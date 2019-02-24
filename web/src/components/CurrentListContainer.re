open DataModel;

let component = ReasonReact.statelessComponent("ItemCard");

let elementArrayOfList = listOfThings =>
  ReasonReact.array(Array.of_list(listOfThings));

let make = (~items, ~handleDelete, _children) => {
  ...component,
  render: _self => {
    <div className="current-list-container">  
      {
          elementArrayOfList(
            List.mapi(
              (idx, item) =>
                <ItemCard
                  key={string_of_int(idx)}
                  handleDelete={id => handleDelete(id)}
                  id={item.id}
                  itemName={item.name}
                  quantity={item.quantity}
                />,
              items,
            ),
          )
        }
    </div>;
  },
};
