const Sequelize = require('sequelize');
const database = process.env("POSTGRES_DB")
const user = process.env("POSTGRES_USER")
const password = process.env("POSTGRES_PASSWORD")

const sequelize = new Sequelize(database, user, password, {
  host: 'localhost',
  dialect: 'postgres',
  operatorsAliases: false,
  pool: {
    max: 5,
    min: 0,
    acquire: 30000,
    idle: 10000
  },
});