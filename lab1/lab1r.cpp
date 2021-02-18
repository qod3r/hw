#include <iostream>
#include <fstream>
#include <cstdlib>
#include "qL.h"

#define NUM_RANGE (double)(rand())/RAND_MAX*(201) - 100
#define SIZE_RANGE (rand() % 10) + 4

using namespace std;

double * ParseFile(int&, int&);
void CreateData();
void Menu(double *, int &, int &);
void Resize();

int main() {
  int size = 0, cap = 0;
  fstream checkfile("array_data");
  double *arr;
  if (checkfile.good()) {
    arr = ParseFile(size, cap);
  } else {
    CreateData();
    arr = ParseFile(size, cap);
  }
  checkfile.close();
  Menu(arr, size, cap);
}

void Menu(double *arr, int &size, int &cap) {
  int menu_choice;
  do {
    cout << "Текущий массив: ";
    qL::Print(arr, cap);
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
        ParseFile(size, cap);
        break;
      // case 3:
      //   AddElem(arr);
      //   break;
      // case 4:
      //   RemoveElem(arr);
      //   break;
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

double * ParseFile(int &size, int &cap) {
  ifstream len("array_data");
  double temp;
  size = 0, cap = 0;
  while (len >> temp) {
    cap++;
  }
  size = cap*2;
  double *arr = new double[size];
  len.close();

  ifstream data_in("array_data");
  for (int i = 0; i < cap; i++) {
    data_in >> arr[i];
  }
  data_in.close();

  return arr;
}

void Resize(double *&arr, int &size) {
  double *buff = new double[size*2];
  delete[] arr;
  arr = buff;
  size *= 2;
}

void Copy(double *&arr, int &size, int &cap) {
  double *temp = new double[size];
  copy(arr, arr+cap, temp);
  delete[] arr;
  arr = temp;
}