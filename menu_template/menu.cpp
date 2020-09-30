#include <iostream>
#include <cmath>
#include <clocale>
using namespace std;

void task1() {
	cout << "задание 1 asdasdasd \n";
	//первое задание
}

void task2() {
	cout << "задание 2 asdasdasdad\n";
}




//здесь дальше задания task3, task4....






void print_menu() {
	system("cls");
	int menu_item;
	cout << "1. Задание 1\n2. Задание 2\n3. Задание 3\n4. Задание 4\n5. Задание 5\n0. Выход\n";
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