#include <iostream>
#include <cmath>
#include <clocale>
using namespace std;

void main() {
	setlocale(LC_CTYPE, "rus");

	unsigned long int n, N;
	int i=0, sum=0, last=0;
	int k, a, b = 0, p = 1, first, count = 1;
	cout << "������� n: \n";
	cin >> n;
	N = n;
	// ����� ����
	while (N > 0) {
		sum += N % 10;
		N /= 10;

	}
	cout << "����� ���� = " << sum << endl;

	//���������� �����
	N = n;
	while (N > 0) {
		
		if ((N%10)>last) {
			last = N % 10;
		}
		N /= 10;
	}
	cout << "���������� ����� = " << last << endl;

	//����������� ������� 1 � ���������
	N = n;
	a = N % 10;
	N /= 10;
	while (N > 9) {
		a *= 10;
		b += (N % 10) * p;
		p *= 10;
		N /= 10;
	}
	N = a * 10 + b * 10 + N;
	cout << "�������� ������� ������ � ��������� �����: " << N << endl;

	//�������� � ������ ����� ����� k (���� � �������)
	N = n;
	cout << "������� k: \n";
	cin >> k;
	cout << k << n;
}
