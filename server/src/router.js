const router = require("express").Router()
const dbClient = require("./db/dbClient")

router.route("/items")
  .get((_, res) => {
    dbClient.getAllItems()
      .then(items => Promise.resolve(
        items.map(item => {
          return { id: item.id, name: item.name, quantity: item.quantity }
        })
      ))    
      .then(result => {
        res.json(result)
      })
  })

  .post((req, res) => {
    dbClient.saveItem(req.body)
      .then(item => {
        res.json(item)
      })
  })

  router.route("/items/:itemId")
    .delete((req, res) => {
      dbClient.destroyItem(req.params.itemId)
      .then(() => {
        res.status(204).send()
      })
  })

module.exports = router