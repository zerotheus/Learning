const sequelize = require('sequelize');

const componenteSequelize = new sequelize('dbProduto', 'root', 'Acwr21m16@', 
{
    dialect:'mysql', host:'localhost'
}); 

module.exports = componenteSequelize;