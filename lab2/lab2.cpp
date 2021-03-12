//выбор элемента, дельта
#include <iostream>
#include <fstream>
#include "Matrix.h"
using namespace std;

void ChooseTask();

int main() {
    ChooseTask();
    return 0;
}

void ChooseMatrix(Matrix &M) {
    int menu_choice;
    int n, m, a, b;
    bool isReal=1;
    char filename[50];
    cout << endl << " ------Выбор матрицы------ " << endl;
    cout << " 1 - Из файла" << endl;
    cout << " 2 - С экрана" << endl;
    cout << " 3 - Случайная" << endl;
    cout << " 4 - Единичная" << endl;
    cout << " 5 - Гильберта" << endl;
    cout << " 0 - Выйти" << endl;
    cout << " ------------------------- " << endl;

    cin >> menu_choice;

    switch (menu_choice) {
        case 1:
            cout << "Введите название файла: ";
            cin >> filename;
            M.GetFile(filename);
            break;
        case 2:
            M.Input();
            break;
        case 3:
            cout << "Введите диапазон значений: ";
            cin >> a >> b;
            cout << "Введите типа числа (0 - целые, 1 - действительные): ";
            cin >> isReal;
            M.Randomize(a, b, isReal);
            break;
        case 4:
            M.One();
            break;
        case 5:
            M.Hilbert();
            break;
        case 0:
            break;
        default:
            cout << "Что-то пошло не так, попробуйте снова" << endl;
            break;
    }
}

void ChooseTask() {
    int menu_choice, n = 3, m = 3;
    cout << "Введите размер матрицы: ";
    cin >> n >> m;
    Matrix M(n, m);
    Matrix Inversed(n, m);
    Vector x(n);
    do {
        cout << " ------Выбор действия------ " << endl;
        cout << " 1 - Решение СЛАУ" << endl;
        cout << " 2 - Определитель" << endl;
        cout << " 3 - Обратная матрица" << endl;
        cout << " 4 - Вывести матрицу" << endl;
        cout << " 0 - Выйти" << endl;
        cout << " -------------------------- " << endl;

        cin >> menu_choice;

        switch (menu_choice) {
            case 1:
                ChooseMatrix(M);
                M.Print();
                M.UpperTriangle();
                M.Solution(x);
                cout << "После преобразований: " << endl;
                M.Print();
                cout << "Ответ: ";
                x.Print();
                M.Nullify();
                break;
            case 2:
                ChooseMatrix(M);
                M.Print();
                M.UpperTriangle();
                cout << "Определитель = " << M.Determinant() << endl;
                M.Nullify();
                break;
            case 3:
                ChooseMatrix(M);
                M.Print();
                M.Inverse(x, Inversed);
                Inversed.Print();
                break;
            case 4:
                ChooseMatrix(M);
                M.Print();
                M.Nullify();
                break;
            case 0:
                cout << "Bye" << endl;
                break;
            default:
                cout << "Что-то пошло не так, попробуйте снова" << endl;
                break;
        }
        if (menu_choice != 0) {
            cout << endl << "Нажмите Enter чтобы продолжить...";
            cin.get();
            cin.get();
        }
    } while (menu_choice);
}