const app = require('express')()
const cors = require('cors')
const logger = require('morgan')
const bodyParser = require('body-parser')
const dbClient= require("./src/db/dbClient")

const port = 5000

app.use(cors())

app.use(logger('dev'))

app.use(bodyParser.json());
app.use(bodyParser.urlencoded({ extended: false }));

app.get('/', (req, res) => res.send("Hello world!"))

app.get('/items', (req, res) => {
  dbClient.getAllItems()
  .then(items => Promise.resolve(
    items.map(item => {
      return { item: item.name, quantity: item.quantity }
    })
  ))
  .then(result => {
    console.log(result);
    res.json(result);
  })
})

app.listen(port, () => console.log(`Listening on port ${port}`))