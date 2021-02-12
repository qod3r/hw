#include <iostream>
#include <cmath>
#include <clocale>
using namespace std;

void task1() {
	cout << "задание 1\n";
	//первое задание
}

void task2() {
	cout << "задание 2\n";
}


void print_menu() {
	system("cls");
	int menu_item;
	cout << "Введите номер задания\n1) \n2) \n3) \n4) \n0) Выйти\n";
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
		default:
			cout << "Что-то пошло не так\n";
			M = false;
			break;
		}
		if (menu_choice != 0) { system("pause"); } //остановка выполнения для отображения результата пункта
	}
}