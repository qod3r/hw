#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;

void Menu();
void task1();
void task2();
void task3();
void task4();
void task5();
void task6();
void task7();
void task8();

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
    cout << " 5 - Задание 5" << endl;
    cout << " 6 - Задание 6" << endl;
    cout << " 7 - Задание 7" << endl;
    cout << " 8 - Задание 8" << endl;
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
      case 4:
        task4();
        break;
      case 5:
        task5();
        break;
      case 6:
        task6();
        break;
      case 7:
        task7();
        break;
      case 8:
        task8();
        break;
      case 0:
        cout << "До связи" << endl;
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

//----------задача 1----------
bool prime(int x) {
  for(int i = 2; i <= sqrt(x); i++) {
    if ((x % i)==0) return 0;
  }
  return 1;
}

void task1() {
  cout << "Написать функцию, определяющую, является ли заданное число простым.\n"
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
  cout << "Составить программу нахождения наименьшего общего кратного для трех натуральных чисел.\n"
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
  S = 6 * St;                 //площадь шестиугольника
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

//----------задача 4----------
//вывод
void frac_print (int n, int m) {
  cout << n << "/" << m;
}
//деление
void frac_div(int a, int b, int c, int d) {
  int N, M;
  N = a * d;
  M = b * c;
  frac_print(a, b); cout << " : "; frac_print(c, d); cout << " = ";
  frac_print(N, M); cout << endl;
}
//умножение
void frac_mult(int a, int b, int c, int d) {
  int N, M;
  N = a * c;
  M = b * d;
  frac_print(a, b); cout << " * "; frac_print(c, d); cout << " = ";
  frac_print(N, M); cout << endl;
}
//сложение
void frac_sum(int a, int b, int c, int d) {
  int N, M, t;
  frac_print(a, b); cout << " + "; frac_print(c, d); cout << " = ";
  if (b != d) {
    t = b * d;    //приводим к общему знаменателю
    a *= d;
    c *= b;
    N = a + c;
    M = t;
  } else {
    N = a + c;
    M = b;
  }
  frac_print(N, M); cout << endl;
}

void task4() {
  cout << "Даны две дроби. Составить:\n"
          "1) деление дроби на дробь\n"
          "2) умножение дроби на дробь\n"
          "3) сложение этих дробей\n"
          "Введите a b c d (дроби имеют вид a/b, c/d): ";
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  cout << "1) ";
  frac_div(a, b, c, d);
  cout << "2) ";
  frac_mult(a, b, c, d);
  cout << "3) ";
  frac_sum(a, b, c, d);
}

//----------задача 5----------
int fact(int x) {
  int f = 1;
  for (int i = 2; i <= x; i++) {
    f *= i;
  }
  return f;
}

void task5() {
  cout << "Составить программу вычисления суммы факториалов четных чисел от m до n.\n"
          "Введите m n: ";
  int m, n;
  cin >> m >> n;

  if (m % 2 == 1) m += 1;
  for (int i = m; i <= n; i += 2) {
    cout << i << "! = " << fact(i) << endl;
  }
}

//----------задача 6----------
int digsum(int N) {
  int sum = 0;
  while (N > 0) {
    sum += N % 10;
    N /= 10;
  }
  return sum;
}

int minsum(int *arr, int n) {
  int s = 0, min = arr[0], t = 0;
  for (int i = 0; i < n; i++) {
    s = digsum(arr[i]);
    if (t > s) {
      min = arr[i];
      t = s;
    }
  }
  return min;
}

int maxsum(int *arr, int n) {
  int s = 0, max = 0, t = 0;
  for (int i = 0; i < n; i++) {
    s = digsum(arr[i]);
    if (s > t) {
      max = arr[i];
      t = s;
    }
  }
  return max;
}

void task6() {
  cout << "Последовательно задается n чисел. Найти числа с наименьшей и наибольшей суммой цифр\n"
          "Введите количество чисел: ";
  int n;
  cin >> n;
  int *arr = new int[n];

  cout << "Введите числа через пробел: ";
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  cout << "Число с наименьшей суммой цифр: " << minsum(arr, n) << endl;
  cout << "Число с наибольшей суммой цифр: " << maxsum(arr, n) << endl;

  delete[] arr;
}

//----------задача 7----------
int digcount(int n) {
  int t = 0;
  while (n > 0) {
    t++;
    n /= 10;
  }
  return t;
}

void task7() {
  cout << "Определить, в каком из данных двух чисел больше цифр\n"
          "Введите числа: ";
  int a, b;
  cin >> a >> b;
  
  int ac = digcount(a), bc = digcount(b);
  if (ac > bc) cout << "В первом числе больше цифр (" << ac << ")";
  else if (ac < bc) cout << "Во втором числе больше цифр (" << bc << ")";
  else cout << "В этих числах одинаковое количество цифр.";
}

//----------задача 8----------
void circle() {
  cout << "Введите радиус r: ";
  double r;
  cin >> r;
  cout << "S = " << M_PI * r * r;
}

void rectangle() {
  cout << "Введите стороны a b: ";
  double a, b;
  cin >> a >> b;
  cout << "S = " << a * b;
}

void triangle() {
  cout << "Введите стороны катетов a b: ";
  double a, b;
  cin >> a >> b;
  cout << "S = " << a * b / 2;
}


void task8() {
  int fig_choice;
  do {
    cout << endl << " ------------------------- " << endl;
    cout << " 1 - Круг" << endl;
    cout << " 2 - Прямоугольник" << endl;
    cout << " 3 - Прямоугольный треугольник" << endl;
    cout << " 0 - Выйти" << endl;
    cout << " ------------------------- " << endl;

    cin >> fig_choice;

    switch(fig_choice) {
      case 1:
        circle();
        break;
      case 2:
        rectangle();
        break;
      case 3:
        triangle();
        break;
      case 0:
        break;
      default:
        cout << "Что-то пошло не так, попробуйте снова" << endl;
        break;
    }
    if (fig_choice != 0) {
      cout << endl << "Нажмите Enter чтобы продолжить...";
      cin.get();    //пауза консоли
      cin.get();    //два раза, т.к cin отделяет только значение ввода
    }               //а enter переходит в первый cin.get
  } while(fig_choice);
}