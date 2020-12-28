// вариант 3
#include <iostream>
#include <cmath>
using namespace std;
#define MAX_N 20
#include <fstream>
#include <cstdlib>

void Menu();
void Swap(int, int);
void BubbleSort(int [], int);
void ShakerSort(int [], int);
void CreateDatasets();

int main() {
  Menu();
}

void Menu() {
  int menu_choice;
  do {
    cout << endl << " ------------- " << endl;
    cout << " 1 - Создать датасеты" << endl;
    cout << " 2 - Задание 2" << endl;
    cout << " 3 - Задание 3" << endl;
    cout << " 4 - Задание 4" << endl;
    cout << " 0 - Выйти" << endl;
    cout << " ------------- " << endl;

    cin >> menu_choice;

    switch(menu_choice) {
      case 1:
       CreateDatasets();
       break;
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

void Swap(int *xp, int *yp) {
  int temp = *xp;
  *xp = *yp;
  *yp = temp;
}

void BubbleSort(int arr[], int n) {
  for (int i = 0; i < n-1; i++) {
    for (int j = 0; j < n-i-1; j++) {
      if (arr[j] > arr[j+1])
        Swap(&arr[j], &arr[j+1]);
    }
  }
}

void ShakerSort(int arr[], int n) {
  bool swapped = true;
  int start = 0;
  int end = n-1;

  while (swapped) {
    swapped = false;
    for (int i = start; i < end; i++) {
      if (arr[i] > arr[i+1]) {
        Swap(&arr[i], &arr[i+1]);
        swapped = true;
      }
    }

    if (!swapped)
      break;
    swapped = false;
    end--;

    for(int i = end - 1; i >= start; i--) {
      if (arr[i] > arr[i+1]) {
        Swap(&arr[i], &arr[i+1]);
        swapped = true;
      }
    }

    start++;
  }
}

void CreateDatasets() {
  ofstream out_asorted("asorted_set");
  ofstream out_reverse("reverse_set");
  ofstream out_random("random_set");

  srand(time(0));
  //random set
  for (int i = 0; i < 10000; i++) {
    out_random << (rand() % 20001) - 10000 << " ";
  }

}