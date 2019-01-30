const app = require('express')()
const cors = require('cors')

const port = 5000

app.use(cors())

app.get('/', (req, res) => res.send("Hello world!"))

app.get('/items', (req, res) => {
  res.json(
    [
      {name: "Baked beans", quantity: 1},
      {name: "Toothepaste", quantity: 3}
    ]
  )
})

app.listen(port, () => console.log(`Listening on port ${port}`))