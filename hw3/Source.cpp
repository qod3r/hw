#include <iostream>
#include <cmath>
using namespace std;

void main() {
	setlocale(LC_CTYPE, "rus");

	unsigned long int n, N;
	int i=0, sum=0, last=0;
	int k, a, b = 0, p = 1, first, count = 1;
	cout << "Введите n: \n";
	cin >> n;
	N = n;
	// сумма цифр
	while (N > 0) {
		sum += N % 10;
		N /= 10;

	}
	cout << "Сумма цифр = " << sum << endl;

	//наибольшая цифра
	N = n;
	while (N > 0) {
		
		if ((N%10)>last) {
			last = N % 10;
		}
		N /= 10;
	}
	cout << "Наибольшая цифра = " << last << endl;

	//переставить местами 1 и последнюю
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
	cout << "Поменять местами первую и последнюю цифры: " << N << endl;

	//добавить в начало числа цифру k (ввод в консоли)
	N = n;
	cout << "Введите k: \n";
	cin >> k;
	cout << k << n;
}





































// Задание 2
/*
void main() {
	double a, b, c, x1, x2, D;
	bool t;

	cout << "enter a b c\n";
	cin >> a >> b >> c;

	if (a!=0) {
		D = (double)b * b - 4 * a * c;
		if (D >= 0) {
			t = true;
			x1 = (-b + sqrt(D)) / (2 * a);
			x2 = (-b - sqrt(D)) / (2 * a);
			cout << x1 << " " << x2;
		}
		else {
			t = false;
			cout << "no solutions";
		}
	}
	else { cout << "a is 0"; }
}
*/