const router = require('express').Router();
const dbClient = require("./db/dbClient")

router.get('/', (req, res) => res.send("Hello world!"))

router.get('/items', (req, res) => {
  dbClient.getAllItems()
  .then(items => Promise.resolve(
    items.map(item => {
      return { name: item.name, quantity: item.quantity }
    })
  ))    
  .then(result => {
    res.json(result);
  })
})

module.exports = router;