const router = require('express').Router();
const dbClient = require("./db/dbClient")

router.route("/items")
  .get((req, res) => {
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

  .post((req, res) => {
    console.log('in post')
    console.log(req)
    // dbClient.saveItem()
  })

module.exports = router;