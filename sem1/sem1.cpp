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
void ExecSort();

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
      case 2:
       ExecSort();
       break;
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
  //reverse set
  for (int i = 10000; i > 0; i--) {
    out_reverse << i << " ";
  }
  //asorted set
  for (int i = 1; i <= 10000; i++) {
    if (i % 100 == 0) {
      out_asorted << (rand() % 10001) << " ";
    } else {
      out_asorted << i << " ";
    }
  }
}

void ExecSort() {
  for (int i = 10; i <= 10000;) {
    ifstream in_asorted("asorted_set");
    ifstream in_reverse("reverse_set");
    ifstream in_random("random_set");
    
    int *arr_asorted = new int[i];
    int *arr_reverse = new int[i];
    int *arr_random = new int[i];

    for (int j = 0; j < i; j++) {
      in_asorted >> arr_asorted[j];
      in_reverse >> arr_reverse[j];
      in_random >> arr_random[j];
    }
    cout << (i-10)/40 << " %\r"; cout.flush();
    in_asorted.close(); in_reverse.close(); in_random.close();

    BubbleSort(arr_asorted, i);
    BubbleSort(arr_reverse, i);
    BubbleSort(arr_random, i);
    
    ofstream out_asorted("asorted", ios::app);
    ofstream out_reverse("reverse", ios::app);
    ofstream out_random("random", ios::app);

    for (int j = 0; j < i; j++) {
      out_asorted << arr_asorted[j] << " ";
      out_reverse << arr_reverse[j] << " ";
      out_random << arr_random[j] << " ";
    }
    out_asorted << endl; out_reverse << endl; out_random << endl;
    out_asorted.close(); out_reverse.close(); out_random.close();

    delete[] arr_asorted;
    delete[] arr_reverse;
    delete[] arr_random;

    if (10000 - i < 50 && i != 10000) {
      i = 10000;
    } else {
      i += 50;
    }
  }
}