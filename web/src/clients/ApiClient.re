open DataModel;

module Decode = {
  let item = itemJson: DataModel.item =>
    Json.Decode.{
      name: itemJson |> field("name", string),
      quantity: itemJson |> field("quantity", int),
    };

  let arrayItems = json => Json.Decode.list(item, json);
};

let fetchItems = () =>
  Js.Promise.(
    Fetch.fetch("http://localhost:5000/items/")
    |> then_(Fetch.Response.json)
    |> then_(json =>
         Decode.arrayItems(json) |> (items => Some(items) |> resolve)
       )
    |> catch(_err => resolve(None))
  );
