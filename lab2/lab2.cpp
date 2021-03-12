#include <iostream>
#include <fstream>
#include "Matrix.h"
using namespace std;

void FileWork();

int main() {

    Matrix M();
    // ChooseTask();
    return 0;
}

Matrix ChooseMatrix() {
    int menu_choice;
    int n, m;
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

    cout << "Введите размерность матрицы n m: ";
    cin >> n >> m;
    Matrix M(n, m);

    switch (menu_choice) {
        case 1:
            cout << "Введите название файла: ";
            cin >> filename;
            M.GetFile(filename);
            break;
        case 2:
            
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
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
    return M;
}

void ChooseTask() {
    int menu_choice;
    do {
        cout << " ------Выбор действия------ " << endl;
        cout << " 1 - Решение СЛАУ" << endl;
        cout << " 2 - Определитель" << endl;
        cout << " 3 - Обратная матрица" << endl;
        cout << " 0 - Выйти" << endl;
        cout << " -------------------------- " << endl;

        cin >> menu_choice;

        switch (menu_choice) {
            case 1:
                Matrix M = ChooseMatrix();
                M.UpperTriangle();
                M.Solution(x);
                cout << "После преобразований: " << endl;
                M.Print();
                cout << "Ответ: ";
                x.Print();
                break;
            case 2:
                Matrix M = ChooseMatrix();
                M.UpperTriangle();
                cout << "Определитель = " << M.Determinant() << endl;
                break;
            case 3:
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