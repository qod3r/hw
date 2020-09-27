#include <iostream>
#include <cmath>
#include <clocale>
#include <string>
using namespace std;


void task1() {
	cout << "���� k-� ������� �����. ����������, ������� ������� � ����� � ������� hh.mm.\n(��������, ���� k = 13257, �� hh.mm = 03.40).\n\n";
	int k, hh, mm;
	cout << "������� k: \n";
	cin >> k;

	hh = k / 3600;
	mm = (k - (hh * 3600))/60;

	cout << hh << "." << mm << endl;
}


//----------------������ ������� �������----------------
double task2_f(double x) {
	if (x > 0) { return x; }
	if ((x >= (-1)) && (x <= 0)) { return 0; }
	if (x < (-1)) { return x * x; }
}

double task2_z(double x) {
	return (7 * x * x * x + 5 * x * x + x);
}

void task2() {
	cout << "��������� y = F(x)+0.75z, ��� z=7x^3+5x^2+x, -2<=x<=4,\nF(x)={x, ���� x>0; 0, ���� -1<=x<=0; x^2, ���� x<-1\n";
	double x, z=0;
	cout << "������� x: ";
	cin >> x;
	if ((x >= (-2)) && (x <= 4)) {
		z = task2_z(x);
		cout << "y=" << task2_f(x) + 0.75 * z << endl;
	}
	else { cout << "x �� �������� ��� ������� ������\n"; }
}
//----------------����� ������� �������----------------







void print_menu() {
	system("cls");
	int menu_item;
	cout << "������� ����� ������� (1-11)\n0. �����\n";
}

int main() {
	setlocale(LC_CTYPE, "rus"); //��������� ��������� ���������
	int menu_choice;
	bool M = true;

	while (M) {
		print_menu();
		cin >> menu_choice;
		switch (menu_choice) {
		case 0:
			M = false; //����� ����� ���� ���� ������ 0
			break;
		case 1:
			task1();
			break;
		case 2:
			task2();
			break;
		default:
			cout << "���-�� ����� �� ���\n";
			M = false;
			break;
		}
		if (menu_choice != 0) { system("pause"); } //��������� ���������� ��� ����������� ���������� ������
	}
}