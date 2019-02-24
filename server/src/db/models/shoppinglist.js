"use strict"
module.exports = (sequelize, DataTypes) => {
  const ShoppingList = sequelize.define("ShoppingList", {
    name: DataTypes.STRING
  }, {})

  ShoppingList.associate = models =>  {
    ShoppingList.belongsToMany(models.Item, { through: "ShoppingListItem" })
  }

  return ShoppingList
}