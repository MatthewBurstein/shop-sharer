const dotenv = require("dotenv").config()

module.exports = {
  development: {
    username: process.env.POSTGRES_USER,
    password: process.env.POSTGRES_PASSWORD,
    database: process.env.POSTGERS_DB,
    host: "db",
    dialect: "postgres",
    port: 5432
  },
  // test: {
  //   username: root,
  //   password: null,
  //   database: database_test,
  //   host: 127.0.0.1,
  //   dialect: postgres
  // },
  // production: {
  //   username: root,
  //   password: null,
  //   database: database_production,
  //   host: 127.0.0.1,
  //   dialect: postgres
  // }
}