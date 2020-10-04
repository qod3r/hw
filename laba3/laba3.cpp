#include <iostream>
#include <cmath>
#include <clocale>
using namespace std;

//Примкулов Дмитрий - 11 вариант

void task1() {
	cout << "Задано целое число. Выяснить, входит ли цифра 3 в запись числа, и если входит, то сколько раз.\n"
            "Введите n: ";
	long long n; int k = 0;
    cin >> n;
    while (n) {
        if ((n % 10) == 3) {k++;}
        n /= 10;
    }
    if (k > 0) {cout << "Цифра 3 входит в число " << k << " раз(а)\n";}
    else {cout << "Цифра 3 не входит в число\n";}
}

void task2() {
    cout << "задание 2\n";
}

void print_menu() {
	system("cls");
	int menu_item;
	cout << "Вариант 11:\n1) Задание 1\n2) Задание 2\n3) Задание 3\n4) Задание 4\n0) Выйти\n";
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