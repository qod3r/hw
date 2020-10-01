#include <iostream>
#include <cmath>
#include <algorithm>
#include <clocale>
using namespace std;

void task1() {
	cout << "Идет k-я секунда суток. Определить, сколько времени в часах и минутах hh.mm.\n(Например, если k = 13257, то hh.mm = 03.40).\n\n";
	int k, hh, mm;
	cout << "Введите k: \n";
	cin >> k;

	hh = k / 3600;
	mm = (k - (hh * 3600))/60;

	cout << hh << "." << mm << endl;
}

//----------------начало второго задания----------------
double task2_f(double x) {
	if (x > 0) { return x; }
	if ((x >= (-1)) && (x <= 0)) { return 0; }
	if (x < (-1)) { return x * x; }
}

double task2_z(double x) {
	return (7 * x * x * x + 5 * x * x + x);
}

void task2() {
	cout << "Вычислить y = F(x)+0.75z, где z=7x^3+5x^2+x, -2<=x<=4,\nF(x)={x, если x>0; 0, если -1<=x<=0; x^2, если x<-1\n";
	double x, z=0;
	cout << "Введите x: ";
	cin >> x;
	if ((x >= (-2)) && (x <= 4)) {
		z = task2_z(x);
		cout << "y=" << task2_f(x) + 0.75 * z << endl;
	}
	else { cout << "x не подходит под условия задачи\n"; }
}
//----------------конец второго задания----------------

void task3() {
	cout << "Если уравнение ax^2+bx+c=0 (a!=0) имеет вещественные корни, то\nлогической переменной t присвоить значение TRUE, а переменным"
		"\nх1 и х2 - значения корней; иначе переменной t присвоить FALSE и выдать на экран дисплея 'нет вещественных корней'\n";
	
	double a, b, c, x1, x2, D;
	bool t=false;
	cout << "Введите a b c\n";
	cin >> a >> b >> c;

	if (a != 0) {
		D = b*b - 4*a*c;
		if (D >= 0) {
			x1 = (-b + sqrt(D)) / (2 * a);
			x2 = (-b - sqrt(D)) / (2 * a);
			t = true;
			cout << x1 << " " << x2 << endl;
		}
		else { cout << "нет вещественных корней\n"; }
	}
	else { cout << "Уравнение не квадратное\n"; }
}

void task4() {
	cout << "Пусть на плоскости в прямоугольной системе координат\nзадан треугольник координатами своих вершин "
		"A(x1,y1), B(x2,y2), C(x3,y3).\nОпределить, является ли данный треугольник равносторонним, равнобедренным или разносторонним?\n"
		"Если по этим трем точкам нельзя построить треугольник, то выводить сообщение об ошибке.\n\n";

	double ax, ay, bx, by, cx, cy, AB, BC, AC;
	cout << "Введите координаты вершин (x1 y1 x2 y2 x3 y3)\n";
	cin >> ax >> ay >> bx >> by >> cx >> cy;
	
	AB = sqrt(pow((bx - ax), 2) + pow((by - ay), 2));
	AC = sqrt(pow((cx - ax), 2) + pow((cy - ay), 2));
	BC = sqrt(pow((cx - bx), 2) + pow((cy - by), 2));

	if ((AB + AC) >= BC) {
		if (AB == AC == BC) {
			cout << "Треугольник равносторонний\n";
		}
		else if (AB == AC || AB == BC || AC == BC) { 
			cout << "Треугольник равнобедренный\n";
		}
		else { cout << "Треугольник разносторонний\n"; }
	}
	else { cout << "Треугольник не существует\n"; }
}

void task5() {
	cout << "Вычислить значение выражения\n"; //TODO дописать выражение
	double T, x, y, z, a, b;
	cout << "Введите a b\n";
	cin >> a >> b;

	x = a * a - 1; y = b * b - a * a; z = sqrt(abs(a + b));
	T = ((abs(x)+min(x,min(y,z)))/(abs(y)+max(x,y)));
	cout << "T = " << T << endl;
}

void task6() {
	cout << "Даны действительные числа x,y.\nМеньшее из этих двух чисел заменить их полусуммой, а большее - их удвоенным произведением.\nЕсли "
		"числа x и y окажутся равными, то выводить сообщение об ошибке.\n";

	double x, y, hsum, dprod;
	cout << "Введите x y:\n";
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
	else { cout << "Ошибка.\n"; }
	
}

void task7() {
	cout << "Треугольник задан координатами своих вершин. Проверить, будет ли какая-либо медиана\n"
            "этого треугольника параллельна заданной прямой ax+by+c=0\n"
            "Введите координаты вершин (x1 y1 x2 y2 x3 y3) и a b c\n";
	double ax, ay, bx, by, cx, cy, a, b, c;
	cin >> ax >> ay >> bx >> by >> cx >> cy >> a >> b >> c;
}

void task8() {
    cout << "Дано натуральное число n. Является ли данное число палиндромом – перевертышем,\n"
            "как, например, числа 2222, 6116, 0440 и т.д.?\n"
            "Введите n: ";                                          //в задаче не указана разрядность числа n
    int n;                                                          //предполагаю, что только четырехзначные значения
    cin >> n;
    // dist = sqrt(pow((bx - ax), 2) + pow((by - ay), 2));
}

void task9() {
    cout << "Дано действительное число x, вычислить f(x)\nВведите x: ";
    double x;
    cin >> x;
    if (x <= 0) {x = 0;}
    if (x > 1) {x = pow(x, 3);}
    cout << "f(x) = " << x << endl;
}

void task10a(double a, double b, double c) {
    if ((a > 0) && (b > 0) && (c > 0)) {
        if ((a < b) && (b < c)) {cout << "true";}
        else {cout << "false";}
    }
    else {cout << "false";}
}
void task10b(double a, double b, double c) {
    if ((a != b) && (b != c) && (a != c)) {
        if ((c < a) && (c < b)) {cout << "true";}
        else {cout << "false";}
    }
    else {cout << "false";}
}
void task10c(double a, double b, double c) {
    if ((a > 0) && (b > 0) && (c > 0)) {cout << "false";}
    else {cout << "true";}
}

void task10() {
    cout << "Записать с помощью логического выражения следующие высказывания:\n"
            "а) числа a, b, c образуют возрастающую последовательность, и все они положительные\n"
            "б) из трех попарно различных чисел a, b, c наименьшим является c\n"
            "в) либо все три числа a, b, c отрицательны, либо хотя бы одно\n" // все или хотя бы одно отрицательно = не (все положительные)
            "Введите a b c\n";
    double a, b, c;
    cin >> a >> b >> c;
    cout << "a) ";     task10a(a, b, c);
    cout << "\nб) ";   task10b(a, b, c);
    cout << "\nв) ";   task10c(a, b, c); cout << endl;
}

void task11() {
    cout << "Даны действительные числа x, y. Определить, принадлежит ли точка с\n"
            "координатами x, y заштрихованной части плоскости\n"
            "Введите x y: ";
    double x, y;
    cin >> x >> y;
    
    cout << "е) ";
    if (x >= 0) {
        if ((x*x + y*y) <= 1) {cout << "Принадлежит\n";}
        else {cout << "Не принадлежит\n";}                    
    }
    else {
        if ((y <= 0.5 * x + 1) && (y >= -0.5*x-1)) {cout << "Принадлежит\n";}
        else {cout << "Не принадлежит\n";}
    }
}

void print_menu() {
	system("cls");
	int menu_item;
	cout << "Введите номер задания (1-11)\n0. Выйти\n";
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
		case 5:
			task5();
			break;
		case 6:
			task6();
			break;
		case 7:
			task7();
			break;
		case 8:
			task8();
			break;
		case 9:
			task9();
			break;
		case 10:
			task10();
			break;
		case 11:
			task11();
			break;
		default:
			cout << "Что-то пошло не так\n";
			M = false;
			break;
		}
		if (menu_choice != 0) { system("pause"); } //остановка выполнения для отображения результата пункта
	}
}