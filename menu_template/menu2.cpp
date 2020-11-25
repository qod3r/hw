#include <iostream>
#include <cmath>
using namespace std;

void Menu();

int main() {
  Menu();
}

void Menu() {
  int menu_choice;
  do {
    cout << endl << " ------------- " << endl;
    cout << " 1 - Задание 1" << endl;
    cout << " 2 - Задание 2" << endl;
    cout << " 3 - Задание 3" << endl;
    cout << " 4 - Задание 4" << endl;
    cout << " 0 - Выйти" << endl;
    cout << " ------------- " << endl;

    cin >> menu_choice;

    switch(menu_choice) {
      //case 1:
      //  task1();
      //  break;
      //case 2:
      //  task2();
      //  break;
      //case 3:
      //  task3();
      //  break;
      //case 4:
      //  task4();
      //  break;
      case 0:
        cout << "Bye" << endl;
        break;
      default:
        cout << "Что-то пошло не так, попробуйте снова" << endl;
        break;
    }
    if (menu_choice != 0) {
      cout << endl << "Нажмите Enter чтобы продолжить...";
      cin.get();    //пауза консоли
      cin.get();    //два раза, т.к cin отделяет только значение ввода
    }               //а enter переходит в первый cin.get
  } while(menu_choice);
}