import 'package:flutter/material.dart';

class HomeControler extends InheritedNotifier<ValueNotifier<int>> {
  HomeControler({Key? key, required Widget child})
      : super(
          key: key,
          child: child,
          notifier: ValueNotifier(0),
        );

  int get contador => notifier!.value;

  static HomeControler of(BuildContext context) {
    return context.dependOnInheritedWidgetOfExactType<HomeControler>()!;
  }

  increment() {
    notifier!.value++;
  }
}
