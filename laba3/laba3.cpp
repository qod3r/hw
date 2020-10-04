#include <iostream>
#include <cmath>
#include <clocale>
using namespace std;

//��������� ������� - 11 �������

void task1() {
	cout << "������ ����� �����. ��������, ������ �� ����� 3 � ������ �����, � ���� ������, �� ������� ���.\n"
            "������� n: ";
	long long n; int k = 0;
    cin >> n;
    while (n) {
        if ((n % 10) == 3) {k++;}
        n /= 10;
    }
    if (k > 0) {cout << "����� 3 ������ � ����� " << k << " ���(�)\n";}
    else {cout << "����� 3 �� ������ � �����\n";}
}
// ----------������ �������----------
void task2_calcy(double x) {
    double y; const double PI = 3.141592653589793238463;
    y = (x * cos(PI / 4) - x * x)/(1 - 2 * x * cos(PI / 4) + x * x);
    cout << "y = " << y << endl;
}
void task2_calcS(double x) {
    const double PI = 3.141592653589793238463;
    double a = 0.1, b = 0.8, h = 0.05, epsilon = 0.0001;
    double S = 0, t = 1;
    
    for (int i = 1; ((abs(t) >= epsilon) && (x <= b)); i++) {
        t = x * cos((i * PI) / 4);                              //S ������ ����������� ������ ���� ���, �.� ��� i = 2
        S += t;                                                 //������� ������ � 0, ������������� ���� ���� �����(t) ������ � 0
        cout << "S(" << i << ") = " << S << endl;               //� �� ������� ������ ���� ������������
        task2_calcy(x);
        if (x + h <= b) {x += h;}
    } 
}
void task2() {
    double a = 0.1, b = 0.8, x;
    cout << "��������� �������� S, y\n"
            "������� x (� ��������� �� " << a << " �� " << b << "): ";
    cin >> x;
    if ((x >= a) && (x <= b)) {
        task2_calcS(x);
    }    
    else {cout << "x �� ����������� ��������� ���������.\n";}
}
// ----------����� ������� �������----------

void task3() {

}

void print_menu() {
	system("cls");
	int menu_item;
	cout << "������� 11:\n1) ������� 1\n2) ������� 2\n3) ������� 3\n4) ������� 4\n0) �����\n";
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
		default:
			cout << "���-�� ����� �� ���\n";
			M = false;
			break;
		}
		if (menu_choice != 0) { system("pause"); } //��������� ���������� ��� ����������� ���������� ������
	}
}