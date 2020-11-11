#include <iostream>
#include <cmath>
using namespace std;

void Menu();
void task1();
void task2();
void task3();
//void task4();
//void task5();
//void task6();
//void task7();
//void task8();

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
    cout << " 4 - Задание 5" << endl;
    cout << " 4 - Задание 6" << endl;
    cout << " 4 - Задание 7" << endl;
    cout << " 4 - Задание 8" << endl;
    cout << " 0 - Выйти" << endl;
    cout << " ------------- " << endl;

    cin >> menu_choice;

    switch(menu_choice) {
      case 1:
        task1();
        break;
      case 2:
        task2();
        break;
      case 3:
        task3();
        break;
      //case 4:
      //  task4();
      //  break;
      //case 5:
      //  task5();
      //  break;
      //case 6:
      //  task6();
      //  break;
      //case 7:
      //  task7();
      //  break;
      //case 8:
      //  task8();
      //  break;
      case 0:
        cout << "До связи" << endl;
        break;
      default:
        cout << "Что-то пошло не так, попробуйте снова" << endl;
        break;
    }
  } while(menu_choice);
}

//----------задача 1----------
bool prime(int x) {
  for(int i = 2; i <= sqrt(x); i++) {
    if ((x % i)==0) return 0;
  }
  return 1;
}

void task1() {
  cout << "Задача 1.\n"
          "Написать функцию, определяющую, является ли заданное число простым.\n"
          "Введите a b: ";
  int a, b;
  cin >> a >> b;

  cout << "а) простые числа в диапазоне [" << a << ", " << b << "]:" << endl;
  for (int i = a; i <= b; i++) {
    if (prime(i)) cout << i << ", ";
  }

  cout << endl << "б) дружественные числа в диапазоне [" << a << ", " << b << "]:" << endl;
  for (int i = a; i <= b; i ++) {
    if (prime(i) && prime(i+2)) {
      cout << i << " и " << i+2 << ", ";
    }
  }
}

//----------задача 2----------
int nod(int a, int b) {
  if (a == b) {
      return a;
  }                         //алгоритм евклида
  if (a > b) {
      int t = a;
      a = b;
      b = t;
  }
  return nod(a, b - a);
}

int nok(int a, int b) {
  return a * b / nod(a, b);
}

void task2() {
  cout << "Задача 2.\n"
          "Составить программу нахождения наименьшего общего кратного для трех натуральных чисел.\n"
          "Введите a b c: ";
  int a, b, c;
  cin >> a >> b >> c;
  cout << "НОД(" << a << ", " << b << ", " << c << ") = " << nod(a, nod(b,c)) << endl;
  cout << "НОК(" << a << ", " << b << ", " << c << ") = " << nok(a, nok(b,c));
}

//----------задача 3----------
double hexagon(double a) {
  double S, St;
  St = (a * a * sqrt(3)) / 4; //площадь равностороннего треугольника
  S = 6 * St;               //площадь шестиугольника
  return S;
}
void task3() {
  cout << "Вычислить площадь правильного шестиугольника со стороной a, используя функцию вычисления площади треугольника\n"
          "Введите а: ";
  int input;
  cin >> input;
  double a = (double)input;
  cout << "S = " << hexagon(a);
}