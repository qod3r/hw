#include <iostream>
#include <cstdlib>
#include <fstream>
#include "qL.h"

#define NUM_RANGE (double)(rand())/RAND_MAX*(201) - 100
#define SIZE_RANGE (rand() % 10) + 4

using namespace std;

double * CreateArr();
void CreateData();
void Menu(double *);
void Addition();
void Deletion();
void Reallocate(double *&, double, int, bool);
void AddElem(double *);
void RemoveElem(double *);
void LookFor(double *, double, double, bool);

int fileLen{0};

int main() {
  fstream checkfile("array_data");
  double *arr;
  if (checkfile.good()) {
    arr = CreateArr();
  } else {
    CreateData();
    arr = CreateArr();
  }
  checkfile.close();
  Menu(arr);
}

void Menu(double *arr) {
  int menu_choice;
  do {
    cout << "Текущий массив: ";
    qL::Print(arr, fileLen);
    cout << " ------------- " << endl;
    cout << " 1 - Создать файл" << endl;
    cout << " 2 - Прочесть файл" << endl;
    cout << " 3 - Добавить элемент" << endl;
    cout << " 4 - Удалить элемент" << endl;
    cout << " 0 - Выйти" << endl;
    cout << " ------------- " << endl;

    cin >> menu_choice;

    switch(menu_choice) {
      case 1:
        CreateData();
        break;
      case 2:
        CreateArr();
        break;
      case 3:
        AddElem(arr);
        break;
      case 4:
        RemoveElem(arr);
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
      cin.get();
      cin.get();
    }
  } while(menu_choice);
}

void CreateData() {
  ofstream data_out("array_data");
  srand(time(0));

  int elems = SIZE_RANGE;
  for (int i = 0; i < elems; i++) {
    data_out << NUM_RANGE << " ";
  }
  data_out.close();
  cout << "Файл создан" << endl;
}

double * CreateArr() {
  ifstream len("array_data");
  double temp;
  fileLen = 0;
  while (len >> temp) {
    fileLen++;
  }
  double *arr = new double[fileLen];
  len.close();

  ifstream data_in("array_data");
  for (int i = 0; i < fileLen; i++) {
    data_in >> arr[i];
  }
  data_in.close();

  return arr;
}

void Reallocate(double *&arr, double n, int k, bool isAdd) {
  if (isAdd && (k>=0) && (k<=fileLen)) {
    double *buff = new double[++fileLen];
    buff[k] = n;
    for (int i = 0; i < k; i++) {
      buff[i] = arr[i];
    }
    for (int i = k; i < fileLen; i++) {
      buff[i+1] = arr[i];
    }
    delete[] arr;
    arr = buff;
  } else if (!isAdd && (k>=0) && (k<=fileLen)) {
    double *buff = new double[--fileLen];
    for (int i = 0; i < k; i++) {
      if (k == 0) break;
      buff[i] = arr[i];
    }
    for (int i = k; i <= fileLen; i++) {
      buff[i] = arr[i+1];
    }
    delete[] arr;
    arr = buff;
  } else {
    cout << "Ошибка, индекс вне диапазона";
  }
}

void AddElem(double *arr) {
  int menu_choice;
  do {
    cout << "Текущий массив: ";
    qL::Print(arr, fileLen);
    cout << " ------------- " << endl;
    cout << " Добавление элемента: " << endl;
    cout << " 1 - В конец массива" << endl;
    cout << " 2 - В начало массива" << endl;
    cout << " 3 - На k-ый индекс" << endl;
    cout << " 4 - После первого элемента с указанным значением" << endl;
    cout << " 0 - Выйти" << endl;
    cout << " ------------- " << endl;

    cin >> menu_choice;
    double n, lookVal;
    int k;
    switch(menu_choice) {
      case 1:
        cout << "Введите число для добавления: ";
        cin >> n;
        Reallocate(arr, n, fileLen, true);
        break;
      case 2:
        cout << "Введите число для добавления: ";
        cin >> n;
        Reallocate(arr, n, 0, true);
        break;
      case 3:
        cout << "Введите число и индекс (через пробел): ";
        cin >> n >> k;
        Reallocate(arr, n, k, true);
        break;
      case 4:
        cout << "Введите число и значение для поиска (через пробел): ";
        cin >> n >> lookVal;
        LookFor(arr, n, lookVal, true);
        break;
      case 0:
        break;
      default:
        cout << "Что-то пошло не так, попробуйте снова" << endl;
        break;
    }
    if (menu_choice != 0) {
      cout << endl << "Нажмите Enter чтобы продолжить...";
      cin.get();
      cin.get();
    }
  } while(menu_choice);
}

void RemoveElem(double *arr) {
  int menu_choice;
  do {
    cout << "Текущий массив: ";
    qL::Print(arr, fileLen);
    cout << " ------------- " << endl;
    cout << " Удаление: " << endl;
    cout << " 1 - Последнего элемента " << endl;
    cout << " 2 - Первого элемента " << endl;
    cout << " 3 - На k-ом индексе" << endl;
    cout << " 4 - Всех элементов с указанным значением" << endl;
    cout << " 0 - Выйти" << endl;
    cout << " ------------- " << endl;

    cin >> menu_choice;
    double n=0, lookVal;
    int k;
    switch(menu_choice) {
      case 1:
        Reallocate(arr, n, fileLen, false);
        break;
      case 2:
        Reallocate(arr, n, 0, false);
        break;
      case 3:
        cout << "Введите индекс: ";
        cin >> k;
        Reallocate(arr, n, k, false);
        break;
      case 4:
        cout << "Введите значение для поиска: ";
        cin >> lookVal;
        LookFor(arr, n, lookVal, false);
        break;
      case 0:
        break;
      default:
        cout << "Что-то пошло не так, попробуйте снова" << endl;
        break;
    }
    if (menu_choice != 0) {
      cout << endl << "Нажмите Enter чтобы продолжить...";
      cin.get();
      cin.get();
    }
  } while(menu_choice);  
}

void LookFor(double *arr, double n, double lookVal, bool isAdd) {
  if (isAdd) {
    bool valFound = false;
    for (int i = 0; i <= fileLen; i++) {
      if (arr[i] == lookVal) {
        Reallocate(arr, n, i, true);
        valFound = true;
        break;
      }
    }
    if (!valFound) cout << "Такого значения нет в массиве";
  } 
  else if (!isAdd) {
    bool valFound = false;
    for (int i = 0; i <= fileLen; i++) {
      if (arr[i] == lookVal) {
        Reallocate(arr, n, i, false);
        valFound = true;
      }
    }
    if (!valFound) cout << "Такого значения нет в массиве";
  }
}