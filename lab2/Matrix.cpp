#include <iostream>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include "Matrix.h"

Matrix::Matrix(int n, int m) {  //выделение памяти на матрицу при создании экземпляра
    _n = n;
    _m = m;
    Matr = new double* [n];
    for (int i = 0; i < n; i++)
        Matr[i] = new double [m];
}

Matrix::~Matrix() {
    for (int i = 0; i < _n; i++)
        delete[] Matr[i];
    delete[] Matr;
}

void Matrix::Randomize(int a, int b) {
    srand(time(0));
    for (int i = 0; i < _n; i++) {
        for (int j = 0; j < _m; j++) {
            // Matr[i][j] = (double)(rand())/RAND_MAX*(b-a-1) + a;
            Matr[i][j] = rand() % (b-a-1) + a;
        }
    }
}

void Matrix::Print() {
    for (int i = 0; i < _n; i++) {
        for (int j = 0; j < _m; j++) {
            std::cout << std::setw(10) << Matr[i][j];
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void Matrix::Input() {
    std::cout << "Введите матрицу " << _n << "х" << _m << " :" << std::endl;
    for (int i = 0; i < _n; i++) {
        for (int j = 0; j < _m; j++) {
            std::cin >> Matr[i][j];
        }
    }
}