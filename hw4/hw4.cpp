#include <iostream>
#include <cmath>
#include <clocale>
using namespace std;
//2.23
void task1() {
	cout << "������� 1\n";
}
//2.27
void task2() {
	cout << "������� 2\n";
}

void task3() {
    cout << "������� 3\n";
}

void task4() {
    cout << "������� 4\n";
}

void print_menu() {
	system("cls");
	int menu_item;
	cout << "������� ����� �������\n1) 2.23\n2) 2.27\n3) 2.28\n4) 2.30\n0) �����\n";
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
		case 3:
			task3();
			break;
		case 4:
			task4();
			break;
		default:
			cout << "���-�� ����� �� ���\n";
			M = false;
			break;
		}
		if (menu_choice != 0) { system("pause"); } //��������� ���������� ��� ����������� ���������� ������
	}
}