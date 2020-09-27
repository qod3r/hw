#include <iostream>
#include <cmath>
#include <clocale>
#include <string>
using namespace std;


void task1() {
	cout << "Идет k-я секунда суток. Определить, сколько времени в часах и минутах hh.mm.\n(Например, если k = 13257, то hh.mm = 03.40).\n\n";
	int k, hh, mm;
	cout << "Введите k: \n";
	cin >> k;

	hh = k / 3600;
	mm = (k - (hh * 3600))/60;

	cout << hh << "." << mm << endl;
}


//----------------начало второго задания----------------
double task2_f(double x) {
	if (x > 0) { return x; }
	if ((x >= (-1)) && (x <= 0)) { return 0; }
	if (x < (-1)) { return x * x; }
}

double task2_z(double x) {
	return (7 * x * x * x + 5 * x * x + x);
}

void task2() {
	cout << "Вычислить y = F(x)+0.75z, где z=7x^3+5x^2+x, -2<=x<=4,\nF(x)={x, если x>0; 0, если -1<=x<=0; x^2, если x<-1\n";
	double x, z=0;
	cout << "Введите x: ";
	cin >> x;
	if ((x >= (-2)) && (x <= 4)) {
		z = task2_z(x);
		cout << "y=" << task2_f(x) + 0.75 * z << endl;
	}
	else { cout << "x не подходит под условия задачи\n"; }
}
//----------------конец второго задания----------------







void print_menu() {
	system("cls");
	int menu_item;
	cout << "Введите номер задания (1-11)\n0. Выйти\n";
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