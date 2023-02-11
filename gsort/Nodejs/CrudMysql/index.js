(async()=>
{
    const database = require('./db');
    const produto = require('./produto');

    await database.sync()

    await produto.create({
        nome: 'primeiro teste',
        datadeCriacao: Date()
    }
    )

    await produto.create({
        nome: 'segundo teste',
        datadeCriacao: Date()
    }
    )

    await produto.create({
        nome: 'terceiro teste',
        datadeCriacao: Date()
    }
    )  

    const alterProd = await produto.findByPk(2);
    alterProd.nome = "novo produto";
    await alterProd.save();

    produto.destroy({where: {id:1}});

    const findProd = await produto.findByPk(3);
    console.log(findProd);

    const findAllProd = await produto.findAll();
    console.log(findAllProd);
})();