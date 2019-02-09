'use strict';

module.exports = {
  up: (queryInterface, Sequelize) => {
      return queryInterface.bulkInsert('Items', [
        {
          name: 'Baked Beans',
          quantity: 1,
          createdAt: new Date(),
          updatedAt: new Date()
        },
        {
          name: 'Toothpaste',
          quantity: 4,
          createdAt: new Date(),
          updatedAt: new Date()
        }
    ], {});
  },

  down: (queryInterface, Sequelize) => {
      return queryInterface.bulkDelete(
        'Items', 
        {[Sequelize.Op.or]: [{name: 'Baked Beans'}, {name: "Toothpaste"}]},
        {}
      );
  }
};
