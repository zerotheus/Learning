import 'package:flutter/material.dart';
import 'package:flutter_application_1/home_controler.dart';

// class HomePage extends StatelessWidget {
//   const HomePage({super.key});
//
//   @override
//   Widget build(BuildContext context) {
//     var contador = HomeControler.of(context);
//     return Scaffold(
//         appBar: AppBar(title: Text('Gostei do flutter')),
//         body:
//             Center(child: Text('Hello World do flutter ${contador.contador}')),
//         floatingActionButton: FloatingActionButton(
//             child: Icon(Icons.add),
//             onPressed: () {
//               contador.increment();
//               print('clicou++');
//             }));
//   }
// }

// class HomePage extends StatefulWidget {
//   const HomePage({super.key});
//
//   @override
//   State<HomePage> createState() => _HomePageState();
// }
//
// class _HomePageState extends State<HomePage> {
//   var contador = 0;
//
//   @override
//   Widget build(BuildContext context) {
//     return Scaffold(
//         appBar: AppBar(title: const Text('Gostei do flutter')),
//         body: Center(child: Text('Hello World do flutter ${contador}')),
//         floatingActionButton: FloatingActionButton(
//             child: Icon(Icons.add),
//             onPressed: () {
//               setState(() {
//                 contador++;
//               });
//
//               print('clicou++');
//             }));
//   }
// }

class HomePage extends StatefulWidget {
  const HomePage({super.key});

  @override
  State<HomePage> createState() => _HomePageState();
}

class _HomePageState extends State<HomePage> {
  var contador = 0;

  final inputdeTexto = TextEditingController();

  final lista = <String>[];

  @override
  Widget build(BuildContext context) {
    return Scaffold(
        appBar: AppBar(title: const Text('Gostei do flutter')),
        body: Container(
          constraints: BoxConstraints.expand(),
          decoration: const BoxDecoration(
              image: DecorationImage(
                  image: AssetImage("assets/images/background.jpg"),
                  fit: BoxFit.cover)),
          child: SizedBox(
            height: MediaQuery.of(context).size.height,
            width: MediaQuery.of(context).size.width,
            child: Column(
              children: [
                Row(
                  children: [
                    Expanded(child: TextField(controller: inputdeTexto)),
                    IconButton(
                        onPressed: () {
                          final text = inputdeTexto.text;
                          setState(() {
                            lista.add(text);
                          });
                          inputdeTexto.clear();
                        },
                        icon: const Icon(Icons.add))
                  ],
                ),
                Expanded(
                  child: ListView.builder(
                    itemCount: lista.length,
                    itemBuilder: (context, index) {
                      final item = lista[index];
                      return ListTile(title: Text(item));
                    },
                  ),
                )
              ],
            ),
          ),
        ));
  }
}
