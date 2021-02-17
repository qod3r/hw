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