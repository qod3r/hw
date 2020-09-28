#include <iostream>
#include <cmath>
#include <algorithm>
#include <clocale>
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

void task3() {
	cout << "���� ��������� ax^2+bx+c=0 (a!=0) ����� ������������ �����, ��\n���������� ���������� t ��������� �������� TRUE, � ����������"
		"\n�1 � �2 - �������� ������; ����� ���������� t ��������� FALSE � ������ �� ����� ������� '��� ������������ ������'\n";
	
	double a, b, c, x1, x2, D;
	bool t=false;
	cout << "������� a b c\n";
	cin >> a >> b >> c;

	if (a != 0) {
		D = b*b - 4*a*c;
		if (D >= 0) {
			x1 = (-b + sqrt(D)) / (2 * a);
			x2 = (-b - sqrt(D)) / (2 * a);
			t = true;
			cout << x1 << " " << x2 << endl;
		}
		else { cout << "��� ������������ ������\n"; }
	}
	else { cout << "��������� �� ����������\n"; }
}

void task4() {
	cout << "����� �� ��������� � ������������� ������� ���������\n����� ����������� ������������ ����� ������ "
		"A(x1,y1), B(x2,y2), C(x3,y3).\n����������, �������� �� ������ ����������� ��������������, �������������� ��� ��������������?\n"
		"���� �� ���� ���� ������ ������ ��������� �����������, �� �������� ��������� �� ������.\n\n";

	double ax, ay, bx, by, cx, cy, AB, BC, AC;
	cout << "������� ���������� ������ (x1 y1 x2 y2 x3 y3)\n";
	cin >> ax >> ay >> bx >> by >> cx >> cy;
	
	AB = sqrt(pow((bx - ax), 2) + pow((by - ay), 2));
	AC = sqrt(pow((cx - ax), 2) + pow((cy - ay), 2));
	BC = sqrt(pow((cx - bx), 2) + pow((cy - by), 2));

	if ((AB + AC) >= BC) {
		if (AB == AC == BC) {
			cout << "����������� ��������������\n";
		}
		else if (AB == AC || AB == BC || AC == BC) { 
			cout << "����������� ��������������\n";
		}
		else { cout << "����������� ��������������\n"; }
	}
	else { cout << "����������� �� ����������\n"; }
}

void task5() {
	cout << "��������� �������� ���������\n"; //TODO �������� ���������
	double T, x, y, z, a, b;
	cout << "������� a b\n";
	cin >> a >> b;

	x = a * a - 1; y = b * b - a * a; z = sqrt(abs(a + b));
	T = ((abs(x)+min(x,min(y,z)))/(abs(y)+max(x,y)));
	cout << "T = " << T << endl;
}

void task6() {
	cout << "���� �������������� ����� x,y.\n������� �� ���� ���� ����� �������� �� ����������, � ������� - �� ��������� �������������.\n���� "
		"����� x � y �������� �������, �� �������� ��������� �� ������.\n";

	double x, y, hsum, dprod;
	cout << "������� x y:\n";
	cin >> x >> y;
	hsum = (x + y) / 2;
	dprod = x * y * 2;	

	if (x > y) {
		y = hsum;
		x = dprod;
		cout << "x = " << x << "\ny = " << y;
	}
	else if (y > x) {
		x = hsum;
		y = dprod;
		cout << "x = " << x << "\ny = " << y << endl;
	}
	else { cout << "������.\n"; }
	
}

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
		case 3:
			task3();
			break;
		case 4:
			task4();
			break;
		case 5:
			task5();
			break;
		case 6:
			task6();
			break;
		default:
			cout << "���-�� ����� �� ���\n";
			M = false;
			break;
		}
		if (menu_choice != 0) { system("pause"); } //��������� ���������� ��� ����������� ���������� ������
	}
}