#include <iostream>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include "Matrix.h"
using namespace std;

int main () {
    cout << "Введите n, m: ";
    int n, m;
    cin >> n >> m;
    Matrix M(n, m);
    // M.Randomize(-100, 100);
    M.Input();
    M.Print();
    return 0;
}