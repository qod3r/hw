#include <iostream>
#include <cmath>
using namespace std;

void Menu();

int main() {
  Menu();
}

void Menu() {
  int key;
  do {
    cout << " ------------- " << endl;
    cout << " 1 - Задание 1" << endl;
    cout << " 2 - Задание 2" << endl;
    cout << " 3 - Задание 3" << endl;
    cout << " 4 - Задание 4" << endl;
    cout << " 0 - Выйти" << endl;
    cout << " ------------- " << endl;

    cin >> key;

    switch(key) {
      case 1:
        cout << "Задание 1" << endl;
        break;
      case 2:
        cout << "Задание 2" << endl;
        break;
      case 3:
        cout << "Задание 3" << endl;
        break;
      case 4:
        cout << "Задание 4" << endl;
        break;
      case 0:
        cout << "До связи" << endl;
        break;
      default:
        cout << "Что-то пошло не так, попробуйте снова" << endl;
        break;
    }
  } while(key);
}