"use strict"

module.exports = {
  up: (queryInterface, Sequelize) => {
    return queryInterface.createTable(
      "ShoppingListItem",
      {
        createdAt: {
          allowNull: false,
          type: Sequelize.DATE,
        },
        updatedAt: {
          allowNull: false,
          type: Sequelize.DATE,
        },
        ItemId: {
          type: Sequelize.INTEGER,
          primaryKey: true,
        },
        ShoppingListId: {
          type: Sequelize.INTEGER,
          primaryKey: true,
        },
      }
    )
  },

  down: (queryInterface, Sequelize) => {
    return queryInterface.dropTable("ProductTags")
  },
}