const db = require("./models/index");

module.exports = {
  getAllItems: function()  {
    return db.Item.findAll()
  }
}