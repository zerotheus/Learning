const express = require('express');

const server = express();

server.use(express.json())

server.use((req, res, next) =>{
    console.time('Request')
    console.log(`Metodo ${req.method}; URL ${req.url};`)

    next()

    console.log('Finalizou')
    console.timeEnd('Request')
})

nomes = [];

function checkNomeExists(req,res,next){
    if(!req.body.name){
        return res.status(400).json({error: 'nome requerido'})
    }
    return next();
}

function checkNomeInArray(req, res, next){
    console.log(req.params.index);
    const name = nomes[req.params.index];
    if(!name){
        return res.status(400).json({error: 'nome nao existente'});
    }
    req.name = name;

    return next();
}

server.get('/nomes', (req, res) => {
return res.json(nomes)
});

server.get('/nomes/:index', (req, res) => {
    const {index} = req.params
    
    return res.json(nomes[index])
    });

server.post('/nomes',checkNomeExists, (req, res) => {
    const {name} = req.body;
    nomes.push(name);
    
    return res.json(nomes);
});

server.put('/nomes/:index', checkNomeInArray,checkNomeExists, (req, res) =>{
    const {index} = req.params;
    const {name} = req.body;

    nomes[index] = name;

    return res.json(nomes);
});

server.delete('/nomes/:index', (req, res) =>{
    const {index} = req.params;

    nomes.splice(index, 1);

    return res.send(nomes);
})

server.listen(3000);