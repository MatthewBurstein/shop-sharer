type state = {
    name: string,
    quantity: int
}

type action =
    | EditName(string)
    | EditQuantity(string)
    | Submit

let component = ReasonReact.reducerComponent("NewItemForm");

let make = (~submit, _children) => {
    ...component,
    initialState: () => {
        name: "",
        quantity: 0
    },
    reducer: (action, state) => {
        switch(action) {
            | EditName(value) => ReasonReact.Update({...state, name: value})
            | EditQuantity(value) => ReasonReact.Update({...state, quantity: int_of_string(value)})
            | Submit => submit(state)
        }
    },
    render: ({state, send}) => {
        let {name, quantity} = state;
        <div className="item-card">
            <form>
                <input 
                    value=name
                    onChange = {
                        event => send(EditName(ReactEvent.Form.target(event)##value))
                    }
                />
                <input 
                    type_="number" 
                    value=string_of_int(quantity) 
                    onChange = {
                        event => send(EditQuantity(ReactEvent.Form.target(event)##value))
                    }
                />
                <button onSubmit={_ => send(Submit)} />
            </ form>
        </div>
    }
}