open DataModel

module Decode {
  let items = json: DataModel.item => {
    Json.Decode.{
      name: json |> field("name", string),
      quantity: json |> field("quantity", int)
    }
  }
}

let fetchItems = (send) => {
  Js.Promise.(
    Fetch.fetch("http://localhost:5000/items/")
      |> then_(Fetch.Response.json)
      |> then_(json => {
        json
          |> Decode.items
          |> (items => Js.log(items)/*send(App.ItemsFetched(items))*/)
          |> resolve
      })
      |> catch(_err =>
        Js.Promise.resolve(/*send(ItemsFailedToFetch)*/)
      )
      |> ignore
  )
}