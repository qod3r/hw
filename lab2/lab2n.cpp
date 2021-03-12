#include <iostream>
#include <fstream>
#include <sstream>
#include "Matrix.h"
using namespace std;

void Execute(Matrix &, Vector &, int, int);

int main(int argc, char *argv[]) {
    if (argc == 2) {
        stringstream convert(argv[1]);
        int choice;
        if (!(convert >> choice))
            exit(0);
        switch (choice) {
            case 2: {
                cout << "Введите размерность матрицы: ";
                int n, m;
                cin >> n >> m;
                Matrix M(n, m);
                Vector x(n);
                M.Input();
                Execute(M, x, n, m);
                break;
            }
            case 4: {
                cout << "Введите размерность матрицы: ";
                int n, m;
                cin >> n >> m;
                Matrix M(n, m);
                Vector x(n);
                M.One();
                Execute(M, x, n, m);
                break;
            }
            case 5: {
                cout << "Введите размерность матрицы: ";
                int n, m;
                cin >> n >> m;
                Matrix M(n, m);
                Vector x(n);
                M.Hilbert();
                Execute(M, x, n, m);
                break;
            }
            default:
                cout << "bruh" << endl;
                break;
        }
    } else if (argc == 3) {
        stringstream convert(argv[1]);
        int choice;
        if (!(convert >> choice))
            exit(0);
        switch (choice) {
            case 1: {
                cout << "Введите размерность матрицы: ";
                int n, m;
                cin >> n >> m;
                Matrix M(n, m);
                Vector x(n);
                char *filename = argv[2];
                M.GetFile(filename);
                Execute(M, x, n, m);
                break;
            }
            default:
                cout << "bruh" << endl;
                break;
        }
    } else if (argc == 5) {
        stringstream convert(argv[1]), r_start(argv[2]), r_end(argv[3]), type(argv[4]);
        int choice, a, b;
        bool isReal;
        if (!(convert >> choice) || !(r_start >> a) || !(r_end >> b) || !(type >> isReal)){
            cout << "bruh" << endl;
            exit(0);
        }
        switch (choice) {
            case 3: {
                cout << "Введите размерность матрицы: ";
                int n, m;
                cin >> n >> m;
                Matrix M(n, m);
                Vector x(n);
                M.Randomize(a, b, isReal);
                Execute(M, x, n, m);
                break;
            }
            default:
                cout << "bruh" << endl;
                break;
        }
    } else {
        cout << "Использование: <имя файла> <число> <аргументы>" << endl;
        cout << "1 - загрузить из файла(требуется название файла)\n./lab2.o 1 matrix_data\n" << endl;
        cout << "2 - ввести с экрана\n./lab2.o 2\n" << endl;
        cout << "3 - сгенерировать случайную(требуется диапазон значений и тип числа)\nТипы: 0 - целое, 1 - действительное\n"
                "./lab2.o 3 -10 10 1\n" << endl;
        cout << "4 - единичная матрица\n./lab2.o 4\n" << endl;
        cout << "5 - матрица Гильберта\n./lab2.o 5" << endl;
        exit(0);
    }

    return 0;
}

void Execute(Matrix &M, Vector &x, int n, int m) {
    M.Print();
    cout << "Решение СЛАУ: " << endl;

    Matrix SLAU(n, m);
    SLAU.CopyMatrix(M);
    Vector Sx(n);

    SLAU.UpperTriangle();
    SLAU.Solution(Sx);
    SLAU.Print();

    cout << "Ответ: ";
    Sx.Print();
    cout << "Точность: " << M.EpsCheck(Sx) << endl << endl;

    cout << "Определитель: ";
    cout << SLAU.Determinant() << endl;

    Matrix M2(n, m);
    M.Inverse(x, M2);
    cout << "Обратная матрица:\n";
    M2.Print();
    M.VerifyInverse(M2);
}
