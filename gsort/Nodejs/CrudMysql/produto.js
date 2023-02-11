const sequelize = require('sequelize');

const database = require('./db');

const produto = database.define('produto', 
{
    Id:{
        type: sequelize.INTEGER,
        autoIncrement: true,
        allowNull: false,
        primaryKey: true
    },
    nome: {
        type: sequelize.STRING,
        allowNull: false,
    },
    datadeCriacao: {
        type: sequelize.DATE,
        allowNull: false,
    }
})

module.exports = produto;