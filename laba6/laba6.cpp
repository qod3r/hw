#include <iostream>
#include <ctime>
#include <cstdlib>
#define MAX_N 20
using namespace std;

void Menu();
void Print(double [], int);
int  GetLength();
void FillArr(double [], int);
void CreateArr(double []);
void Task1();
void Task2();
void Task3();
void Task11_1();
void Task11_2();

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
    cout << " 4 - Вар 11-1" << endl;
    cout << " 5 - Вар 11-2" << endl;
    cout << " 0 - Выйти" << endl;
    cout << " ------------- " << endl;

    cin >> menu_choice;

    switch(menu_choice) {
      case 1:
        Task1();
        break;
      case 2:
        Task2();
        break;
      case 3:
        Task3();
        break;
      case 4:
        Task11_1();
        break;
      case 5:
        Task11_2();
        break;
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

void Print(double arr[], int n) {
  cout << "[";
  for (int i = 0; i < n; i++) {
    cout << arr[i] << ", ";
  }
  cout << "\b\b" << "]" << endl;
}

int GetLength() {
  double n;
  do {
    cout << "Введите размер массива: ";
    cin >> n;
    if (n <= 0 || n > MAX_N || (n - (int)n)) {
      cout << "Ошибка, попробуйте снова." << endl;
    }
  } while (n <= 0 || n > MAX_N || (n - (int)n));
  return n;
}

void FillArr(double arr[], int n) {
  srand(time(0));
  for (int i = 0; i < n; i++) {
    arr[i] = (rand() % 201) - 100; //генерация в промежутке [-100, 100]
  }
}

void CreateArr(double arr[]) {
  int n = GetLength();
  FillArr(arr, n);
  cout << "Начальный массив:" << endl;
  Print(arr, n);
}

double MaxElement(double arr[], int n) {
  double tmax = 0;
  for (int i = 0; i < n; i++) {
    if (arr[i] > tmax) {
      tmax = arr[i];
    }
  }
  return tmax;
}

double MinElement(double arr[], int n) {
  double tmin = arr[0];
  for (int i = 0; i < n; i++) {
    if (arr[i] < tmin) {
      tmin = arr[i];
    }
  }
  return tmin;
}

void Task1() {
  cout << "Найти максимальный и минимальный элементы массива" << endl;
  double arr[MAX_N];
  CreateArr(arr);
  int n = sizeof(arr)/sizeof(arr[0]);
  cout << "Максимальный элемент: " << MaxElement(arr, n) << endl;
  cout << "Минимальный элемент: " << MinElement(arr, n) << endl;
}

void Task2() {
  cout << "Переставить местами максимальный и минимальный элементы" << endl;
  double arr[MAX_N];
  CreateArr(arr);
  int n = sizeof(arr)/sizeof(arr[0]);
  

}

void Task3() {}
void Task11_1() {}
void Task11_2() {}