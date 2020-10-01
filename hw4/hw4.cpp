#include <iostream>
#include <cmath>
#include <clocale>
using namespace std;

//2.23
void task1() {
	cout << "Целое положительное число M записывается в двоичной системе счисления,\n"
    "разряды (исключая левые нули) переставляются в обратном порядке.\n"
    "Получившееся таким образом двоичное число переводится в десятичное и печатается.\n"
    "Введите М: ";

    unsigned int M;
    int k = 1, bin = 0;
    cin >> M;
    while(M) {
        bin += (M % 2) * k;
        k *= 10;
        M /= 2;
    }
    cout << bin << endl;
    
}

//2.27
void task2() {
	cout << "Задание 2\n";
}

//2.28
void task3() {
    cout << "Задание 3\n";
}

//2.30
void task4() {
    cout << "Задание 4\n";
}

void print_menu() {
	system("cls");
	int menu_item;
	cout << "Введите номер задания\n1) 2.23\n2) 2.27\n3) 2.28\n4) 2.30\n0) Выйти\n";
}

int main() {
	setlocale(LC_CTYPE, "rus"); //добавляем поддержку кириллицы
	int menu_choice;
	bool M = true;

	while (M) {
		print_menu();
		cin >> menu_choice;
		switch (menu_choice) {
		case 0:
			M = false; //конец цикла если юзер выбрал 0
			break;
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
		default:
			cout << "Что-то пошло не так\n";
			M = false;
			break;
		}
		if (menu_choice != 0) { system("pause"); } //остановка выполнения для отображения результата пункта
	}
}