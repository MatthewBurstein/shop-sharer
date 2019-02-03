const app = require('express')()
const cors = require('cors')
const logger = require('morgan')
const bodyParser = require('body-parser')

const port = 5000

app.use(cors())

app.use(logger('dev'))

app.use(bodyParser.json());
app.use(bodyParser.urlencoded({ extended: false }));

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