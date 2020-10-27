#include <iostream>
#include <cmath>
#include <clocale>
using namespace std;

//Примкулов Дмитрий - 11 вариант

void task1() {
	cout << "Задано целое число. Выяснить, входит ли цифра 3 в запись числа, и если входит, то сколько раз.\n"
            "Введите n: ";
	long long n; int k = 0;
    cin >> n;
    while (n) {
        if ((n % 10) == 3) {k++;}
        n /= 10;
    }
    if (k > 0) {cout << "Цифра 3 входит в число " << k << " раз(а)\n";}
    else {cout << "Цифра 3 не входит в число\n";}
}

// ----------Второе задание----------
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
        t = x * cos((i * PI) / 4);                              //S всегда суммируется только один раз, т.к при i = 2
        S += t;                                                 //косинус уходит в 0, следовательно весь член суммы(t) уходит в 0
        cout << "S(" << i << ") = " << S << endl;               //и по условию задачи цикл прекращается
        task2_calcy(x);
        if (x + h <= b) {x += h;}
    } 
}
void task2() {
    double a = 0.1, b = 0.8, x;
    cout << "Вычислить значения S, y\n"
            "Введите x (в диапазоне от " << a << " до " << b << "): ";
    cin >> x;
    if ((x >= a) && (x <= b)) {
        task2_calcS(x);
    }    
    else {cout << "x не принадлежит заданному диапазону.\n";}
}
// ----------Конец второго задания----------

void task3() {
    cout << "Вычислить значение выражения a^2 + 2a - 3 / 2 (a-1) при а = 0, 3, 6, ..., 21\n";
    int a = 0; double val = 0;
    while (a <= 21) {
        val = (a * a + 2 * a - 3)/(2 * (a - 1));
        cout << "a = " << a << endl;
        a += 3;
    }
}

void task4() {
    cout << "Вычислить первые 12 членов последовательности\n";
    //первые 12 членов посл-ти, v(i)=(i + 1)/(i^2 + 1)*v(i-1) - v(i-1)*v(i-2); i = 4, 5...
    double v1 = 0, v2 = 1.5;
    double vn = 1;
    cout << "v0 = v1 = 0\nv2 = " << v2 << endl; 
    for (double i = 4.0; i <= 12; i++) {
        vn = ((i + 1)/(i * i + 1)) * v2 - v2 * v1;
        cout << "v" << i << " = " << vn << endl;
        v1 = v2;
        v2 = vn;
    }
}

void print_menu() {
	system("cls");
	int menu_item;
	cout << "Вариант 11:\n1) Задание 1\n2) Задание 2\n3) Задание 3\n4) Задание 4\n0) Выйти\n";
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
		case 3:
			task3();
			break;
		case 4:
			task4();
			break;
		default:
			cout << "Что-то пошло не так\n";
			M = false;
			break;
		}
		if (menu_choice != 0) { system("pause"); } //остановка выполнения для отображения результата пункта
	}
}