#include <iostream>
#include <cmath>
using namespace std;

// Задание 1
/*
void main() {
	double y, x1, x2;
	cout << "enter x1 x2" << endl;
	cin >> x1 >> x2;

	y =(double)(exp((-1) * x1) + exp((-1) * x2)) / 2;

	cout << "y = " << y;
}
*/

// Задание 2
/*
void main() {
	double a, b, c, s, p;
	cout << "enter a b c" << endl;
	cin >> a >> b >> c;

	p = (double)(a + b + c) / 2;
	s = sqrt(p * (p - a) * (p - b) * (p - c));

	cout << "s = " << s;
}
*/

// Задание 3
/*
void main() {
	double s, p, hA, hB, hC, a, b, c;

	cout << "Enter a b c" << endl;
	cin >> a >> b >> c;

	p = (a + b + c) / 2;
	s = sqrt(p * (p - a) * (p - b) * (p - c));
	hA = 2 * s / a;
	hB = 2 * s / b;
	hC = 2 * s / c;

	cout << hA << ' ' << hB << ' ' << hC;
}
*/

// Задание 4
/*
void main() {
	double s, v, R, r, l, h;
	double pi = 3.14159265358979323846;

	cout << "Enter R r l h" << endl;
	cin >> R >> r >> l >> h;

	s = (pi * (R + r) * l) + (pi * R * R) + (pi * r * r);
	v = ((double)1 / 3) * (R * R + r * r + R * r) * h * pi;

	cout << "s = " << s << endl << "v = " << v;
}
*/

// Задание 5
/*
void main() {
	double pi = 3.14159265358979323846;
	double x, y, a, fi, w;

	cout << "Enter a fi w" << endl;
	cin >> a >> fi >> w;

	x = (pi / 2) - fi;
	y = (double)a * exp((-a) * w * x) * sin(w * x);
	
	cout << "y = " << y;
}
*/

// Задание 6
/*
void main() {
	long input;
	cout << "Enter a number" << endl;
	cin >> input;

	if (input / 100 > 0) {

		for (int i = 0; i < 2; ++i) {
			input /= 10;
		}
		input %= 10;

		cout << endl << input;
	}
	else {
		cout << endl << "Entered number has less than 3 digits!";
	}
}
*/

// Задание 7
/*
void main() {
	double input;
	int number;
	cout << "Enter a number" << endl;
	cin >> input;
	input *= 10;
	number = (int)input;
	number %= 10;

	cout << endl << number;
}
*/

// Задание 8
/*
void main() {
	double a, b, c=1, d=2, x, x1, x2;
	// пункт а)
	a = c - d;
	b = 3 * c * d;

	// пункт б)
	cout << "enter x1 x2" << endl;
	cin >> x1 >> x2;
	x1 = x1 + x2;
	x2 = x2 - x1;
	x2 = -x2;
	x1 = x1 - x2;
	cout << "x1 = " << x1 << " " << "x2 = " << x2;

	// пункт в)
	x2 *= x1;
	x1 = a + b;
}
*/

// Задание 9
// пункт о) затем л)
/*
void main() {
	double x, y, z, t, s;
	cout << "enter x y z" << endl;
	cin >> x >> y >> z;

	s = asin((double)x / (y * y + z + 1));
	
	cout << s << endl << "enter t x" << endl;
	cin >> t >> x; // конец о) и начало л)

	s = (2 * t * sin(log(pow(x, sqrt(t)-0.55))-(1.3756*10*10*10)))/(2*log(x)-(t*t*sin(x)));
	cout << s;
}
*/