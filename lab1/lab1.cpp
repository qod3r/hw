#include <iostream>
#include <cstdlib>
#include <fstream>
#define RANDOM_RANGE (rand() % 10) + 1
using namespace std;

void CreateArr();
void CreateData();
void Menu();

int main() {
  Menu();
}

void Menu() {
  int menu_choice;
  do {
    cout << endl << " ------------- " << endl;
    cout << " 1 - Создать файл" << endl;
    cout << " 2 - ранд" << endl;
    // cout << " 3 - Отсортировать шейкером" << endl;
    // cout << " 4 - Задание 4" << endl;
    cout << " 0 - Выйти" << endl;
    cout << " ------------- " << endl;

    cin >> menu_choice;

    switch(menu_choice) {
      case 1:
       CreateData();
       break;
      // case 2:
      //  qrand();
      //  break;
      // case 3:
      //  ExecShakerSort();
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
      cin.get();    
      cin.get();    
    }               
  } while(menu_choice);
}

void CreateData() {
  ofstream data("array_data");
  srand(time(0));

  int elems = RANDOM_RANGE;
  for (int i = 0; i < elems; i++) {
    data << RANDOM_RANGE << " ";
  }
  data.close();
}

void CreateArr() {
  ifstream data("array_data");
  

  int *arr = new int[];
  data.close();
}