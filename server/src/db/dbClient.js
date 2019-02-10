const db = require("./models/index")

module.exports = {
	getAllItems: () => {
		return db.Item.findAll()
	},
	saveItem: (item) => {
		return db.Item.create(item)
	}
}