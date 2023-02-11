const express = require('express');

const server = express();

server.use(express.json());

const nomes = [];

server.get('/nomes/:index' , (req, res) =>{
    const {index} = req.params
    console.log(index);
    return res.json(nomes[index]);
});

server.get('/nomes', (req,res) => {
    return res.json(nomes);
})

server.post('/nomes', (req, res)=> {
    const {nome} = req.body;
    nomes.push(nome);
    
    
    return res.json(nomes);
});

server.put('/nomes/:index', (req, res) => {
    const {index} = req.params;
    const {nome} = req.body;

    nomes[index] = nome;
 
    return res.json(nomes)
});

server.delete('/nomes/:index', (req, res) => {
    const {index} = req.params;
    
    nomes.splice(index, 1);
    return res.json({message: "nome deletado"});
})

server.listen(3000);