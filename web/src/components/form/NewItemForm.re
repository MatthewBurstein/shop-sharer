type state = {
    name: string,
    quantity: int
}

type action =
    | EditName(string)
    | EditQuantity(string)

let component = ReasonReact.reducerComponent("NewItemForm");

let make = (_children) => {
    ...component,
    initialState: () => {
        name: "",
        quantity: 0
    },
    reducer: (action, state) => {
        switch(action) {
            | EditName(value) => ReasonReact.Update({...state, name: value})
            | EditQuantity(value) => ReasonReact.Update({...state, quantity: int_of_string(value)})
        }
    },
    render: (self) => {
        let {name, quantity} = self.state;
        <div className="item-card">
            <input 
                value=name
                onChange = {
                    event => self.send(EditName(ReactEvent.Form.target(event)##value))
                }
            />
            <input 
                type_="number" 
                value=string_of_int(quantity) 
                onChange = {
                    event => self.send(EditQuantity(ReactEvent.Form.target(event)##value))
                }
            />
        </div>
    }
}