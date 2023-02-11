import 'package:flutter/material.dart';
import 'home_controler.dart';
import 'Home_page.dart';

class MyApp extends StatelessWidget {
  const MyApp({super.key});

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      home: HomeControler(child: HomePage()),
    );
  }
}
