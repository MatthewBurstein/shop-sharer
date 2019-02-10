const app = require('express')()
const cors = require('cors')
const logger = require('morgan')
const bodyParser = require('body-parser')
const router = require("./src/router")

const port = 5000

app.use(cors())

app.use(logger('dev'))

app.use(bodyParser.json());
app.use(bodyParser.urlencoded({ extended: false }));

app.use(router)

app.listen(port, () => console.log(`Listening on port ${port}`))