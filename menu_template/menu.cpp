#include <iostream>
#include <cmath>
#include <clocale>
using namespace std;

void task1() {
	cout << "������� 1 asdasdasd \n";
	//������ �������
}

void task2() {
	cout << "������� 2 asdasdasdad\n";
}




//����� ������ ������� task3, task4....






void print_menu() {
	system("cls");
	int menu_item;
	cout << "1. ������� 1\n2. ������� 2\n3. ������� 3\n4. ������� 4\n5. ������� 5\n0. �����\n";
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