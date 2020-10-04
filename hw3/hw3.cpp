#include <iostream>
#include <cmath>
#include <clocale>
using namespace std;

//2.23
void task1() {
	cout << "Целое положительное число M записывается в двоичной системе счисления,\n"
    "разряды (исключая левые нули) переставляются в обратном порядке.\n"
    "Получившееся таким образом двоичное число переводится в десятичное и печатается.\n"
    "Введите М: ";
    int M, bin = 0;
    cin >> M;
    while (M) {
        bin = bin * 2 + M % 2;
        M /= 2;
    }
    cout << bin << endl;
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
	cout << "Дано натуральное число n. Определить:\n"
            "а) сколько цифр в числе n\nб) чему равна сумма его цифр\n"
            "в) найти первую цифру числа n\nг) записать число в обратном порядке.\n"
            "Введите n: ";
    unsigned int n;
    cin >> n;
    cout << "а) ";  int i = task2_a(n);
    cout << "б) ";  cout << task2_b(n) << endl;
    cout << "в) ";  task2_c(n);
    cout << "г) ";  task2_d(i, n);
}

//2.28 (я не смог сделать а) :(
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
    cout << "Пусть дано натуральное число n.\n"
            "Составить программу вычисления n^3 как суммы нечетных чисел\n"
            "Введите n: ";
    int n;
    cin >> n;
    task3_s(n);
}

//2.30
void task4() {
    cout << "Найти минимальную и максимальную сумму цифр для чисел в интервале от N1 до N2.\n"
            "Введите N1 N2: ";
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
	cout << "Введите номер задания\n1) 2.23\n2) 2.27\n3) 2.28\n4) 2.30\n0) Выйти\n";
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