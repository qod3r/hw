#include <iostream>
#include <cmath>
#include <clocale>
using namespace std;

//2.23
void task1() {
	cout << "����� ������������� ����� M ������������ � �������� ������� ���������,\n"
    "������� (�������� ����� ����) �������������� � �������� �������.\n"
    "������������ ����� ������� �������� ����� ����������� � ���������� � ����������.\n"
    "������� �: ";

    unsigned int M;
    int k = 1, bin = 0;
    cin >> M;
    while(M) {
        bin += (M % 2) * k;
        k *= 10;
        M /= 2;
    }
    cout << bin << endl;

    //�� �������
}

//2.27
int task2_a(int n) {
    int i = 0;
    while (n > 0) {
        n /= 10;
        i++;
    }
    cout << i << endl;
    return i;
}
int task2_b(int n) {
    int i = 0;
    while (n > 0) {
        i += n % 10;
        n /= 10;
    }
    return i;
}
void task2_c(unsigned int n) {
    int i;
    while (n > 0) {
        i = n;
        n /= 10;
    }
    cout << i << endl;
}
int task2_d(int i, int n) {
    int temp;
    for (i; i > 0; i--) {
        temp += (n % 10) * pow(10, i-1);     
        n /= 10;
    }
    cout << temp-1 << endl;
}
void task2() {
	cout << "���� ����������� ����� n. ����������:\n"
            "�) ������� ���� � ����� n\n�) ���� ����� ����� ��� ����\n"
            "�) ����� ������ ����� ����� n\n�) �������� ����� � �������� �������.\n"
            "������� n: ";
    unsigned int n;
    cin >> n;
    cout << "�) ";  int i = task2_a(n);
    cout << "�) ";  cout << task2_b(n) << endl;
    cout << "�) ";  task2_c(n);
    cout << "�) ";  task2_d(i, n);
}

//2.28 (� �� ���� ������� �) :(
void task3_s(int n) {
    int s = 0, i = n * n - n + 1;
    cout << n << "^3 = ";
    while (s < n * n * n) {
        if (s < (n * n * n - i)) {cout << i << " + ";}
        else {cout << i << " = ";}
        s += i;
        i += 2;
    }
    cout << s << endl;
}
void task3() {
    cout << "����� ���� ����������� ����� n.\n"
            "��������� ��������� ���������� n^3 ��� ����� �������� �����\n"
            "������� n: ";
    int n;
    cin >> n;
    task3_s(n);
}

//2.30
void task4() {
    cout << "����� ����������� � ������������ ����� ���� ��� ����� � ��������� �� N1 �� N2.\n"
            "������� N1 N2: ";
    int N1, N2, n, i, max = 0;
    cin >> N1 >> N2;
    int min = N2;
    for (n = N1; n <= N2; n++) {
        i = task2_b(n);
        if (max < i) {
            max = i;
        }
    }
    for (n = N2; n >= N1; --n) {
        i = task2_b(n);
        if (min > i) {
            min = i;
        }
    }
    cout << "max = " << max << "\nmin = " << min << endl;
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