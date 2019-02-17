open DataModel;

let apiAddress = "http://localhost:5000/";

module Decode = {
  let item = itemJson: DataModel.itemType =>
    Json.Decode.{
      name: itemJson |> field("name", string),
      quantity: itemJson |> field("quantity", int),
      id: itemJson |> field("id", int)
    };

  let arrayItems = json => Json.Decode.list(item, json);
};

module Encode = {
  let item = itemToEncode => {
    let payload = Js.Dict.empty();
    Js.Dict.set(payload, "name", Js.Json.string(itemToEncode.name));
    Js.Dict.set(
      payload,
      "quantity",
      Js.Json.string(string_of_int(itemToEncode.quantity)),
    );
    payload;
  };

  let id = idToEncode => {
    let payload = Js.Dict.empty();
    Js.Dict.set(payload, "id", Js.Json.string(string_of_int(idToEncode)));
    payload;  
  }
};

let fetchItems = () =>
  Js.Promise.(
    Fetch.fetch(apiAddress ++ "items/")
    |> then_(Fetch.Response.json)
    |> then_(json => 
      Decode.arrayItems(json) |> (items => Some(items) |> resolve)
    )
    |> catch(_err => {
         Js.log(_err);
         resolve(None);
       })
  );

let postItem = item => {
  let payload = Encode.item(item);
  Js.Promise.(
    Fetch.fetchWithInit(
      apiAddress ++ "items/",
      Fetch.RequestInit.make(
        ~method_=Post,
        ~body=
          Fetch.BodyInit.make(Js.Json.stringify(Js.Json.object_(payload))),
        ~headers=Fetch.HeadersInit.make({"Content-Type": "application/json"}),
        (),
      ),
    )
    |> then_(Fetch.Response.json)
    |> then_(json => Decode.item(json) |> (item => Some(item) |> resolve))
    |> catch(_err => {
         Js.log(_err);
         resolve(None);
       })
  );
};
