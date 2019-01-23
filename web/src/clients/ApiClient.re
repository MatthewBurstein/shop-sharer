open DataModel

module Decode {
  let items = json => {

  }
}

let fetchItems = (send) => {
  Js.Promise.(
    Fetch.fetch("https://server:5000")
      |> then_(Fetch.Response.json)
      |> then_(json => {
        Js.log(json);
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