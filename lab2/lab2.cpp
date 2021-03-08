#include <iostream>
#include <fstream>
#include "Matrix.h"
using namespace std;

int main () {
    cout << "Введите n, m: ";
    int n, m, a, b;
    bool isReal = true;
    char name[50];
    cin >> n >> m;
    Matrix M(n, m);

    // cout << "Введите диапазон значений: ";
    // cin >> a >> b;
    // cout << "Введите тип чисел (0 - целые, 1 - действительные): ";
    // cin >> isReal;
    // M.Randomize(a, b, isReal);

    // M.Input();
    cout << "Введите название файла: ";
    cin >> name;
    M.GetFile(name);
    M.Print(isReal);
    Vector x(n);
    M.UpperTriangle();
    M.Solution(x);
    M.Print(isReal);
    x.Print();
    return 0;
}

