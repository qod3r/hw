#include <iostream>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <cmath>
#include "Matrix.h"

Vector::Vector(int n) {
    _len = n;
    vect = new double[n];
}

Vector::~Vector() {
    delete[] vect;
}

void Vector::Set(int i, double val) {
    vect[i] = val;
}

double Vector::Get(int i) {
    return vect[i];
}

void Vector::Print() {
    std::cout << "[";
    for (int i = 0; i < _len; i++) {
        std::cout << vect[i] << ", ";
    }
    std::cout << "\b\b" << "]" << std::endl;
}




Matrix::Matrix(int n, int m) {  //выделение памяти на матрицу при создании экземпляра
    _n = n;
    _m = m;
    Matr = new double* [n];
    for (int i = 0; i < n; i++)
        Matr[i] = new double[m];
}

Matrix::~Matrix() {
    for (int i = 0; i < _n; i++)
        delete[] Matr[i];
    delete[] Matr;
}

void Matrix::Randomize(int a, int b, bool isReal) {
    srand(time(0));
    if (isReal) {
        for (int i = 0; i < _n; i++) {
            for (int j = 0; j < _m; j++) {
                Matr[i][j] = (double)(rand())/RAND_MAX*(b-a-1) + a;
            }
        }
    } else {
        for (int i = 0; i < _n; i++) {
            for (int j = 0; j < _m; j++) {
                Matr[i][j] = rand() % (b-a-1) + a;
            }
        }
    }
}

void Matrix::Print() {
    for (int i = 0; i < _n; i++) {
        for (int j = 0; j < _m; j++) {
            std::cout << std::setw(11) << Matr[i][j];
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void Matrix::One() {
    for (int i = 0; i < _n; i++) {
        Matr[i][i] = 1;
    }
}

void Matrix::SwapRows(int k) {
    for (int i = k+1; i < _n; i++) {
        if (Matr[i][k] != 0) {
            for(int j = 0; j < _m; j++) {
                double t = Matr[k][j];
                Matr[k][j] = Matr[i][j];
                Matr[i][j] = t;
            }
        }
    }
}

void Matrix::Nullify() {
    for (int i = 0; i < _n; i++) {
        for (int j = 0; j < _m; j++) {
            Matr[i][j] = 0;
        }
    }
}

void Matrix::Hilbert() {
    for (int i = 0; i < _n; i++) {
        for (int j = 0; j < _m; j++) {
            Matr[i][j] = double(1./(i+j+1));
        }
    }
}

void Matrix::Input() {
    std::cout << "Введите матрицу " << _n << "х" << _m << " :" << std::endl;
    for (int i = 0; i < _n; i++) {
        for (int j = 0; j < _m; j++) {
            std::cin >> Matr[i][j];
        }
    }
}

void Matrix::GetFile(const char *name) {
    std::ifstream f(name);
    if (!f) {
        std::cout << "Ошибка, файла " << name << " не существует" << std::endl;
    } else {
        for (int i = 0; i < _n; i++) {
            for (int j = 0; j < _m; j++) {
                if (!(f >> Matr[i][j])) {
                    std::cout << "Ошибка, в файле " << name << " недостаточно данных" << std::endl;
                }
            }
        }
    }
    f.close();
}

void Matrix::CopyMatrix(Matrix &orig) {
    for (int i = 0; i < _n; i++) {
        for (int j = 0; j < _m; j++) {
            Matr[i][j] = orig.Matr[i][j];
        }
    }
}

void Matrix::UpperTriangle() {
    for (int i = 0; i < _n; i++) {
        if (Matr[i][i] == 0) {
            SwapRows(i);
        }
    }
    
    double c;

    for (int k = 0; k < _n; k++) {
        for (int i = k+1; i < _n; i++) {
            c = (double)(-1 * Matr[i][k]/Matr[k][k]);
            for (int j = k; j < _m; j++) {
                Matr[i][j] += Matr[k][j] * c;
            }
        }
    }
}

void Matrix::Inverse(Vector &x, Matrix &Inversed) {
    for (int i = 0; i < _n; i++) {
        Matrix buff(_n, _m);
        buff.CopyMatrix(*this);
        for (int j = 0; j < _n; j++) {
            (i == j) ? buff.Matr[j][_m - 1] = 1 : buff.Matr[j][_m - 1] = 0;
        }
        buff.UpperTriangle();
        buff.Solution(x);
        for (int j = 0; j < _n; j++) {
            Inversed.Matr[j][i] = x.Get(j);
        }
    }
}

void Matrix::VerifyInverse(Matrix &Inversed) {
    long double S;
    Matrix buff(_n, _n);
    for (int i = 0; i < _n; i++) {
        for (int j = 0; j < _n; j++) {
            S = 0;
            for (int k = 0; k < _m-1; k++) {
                S += Matr[i][k] * Inversed.Matr[k][j];
            }
            if (S < 0.000001) {
                buff.Matr[i][j] = 0;
            } else {
                buff.Matr[i][j] = S;
            }
        }
    }
    std::cout << "Проверка:\n";
    buff.Print();
}

double Matrix::EpsCheck(Vector &x) {
    double epsilon = 0;
    double s;
    for (int i = 0; i < _n; i++) {
        s = 0;
        for (int k = 0; k < _m-1; k++) {
            s += Matr[i][k] * x.Get(k);
        }
        if (fabs(Matr[i][_m-1] - s) > epsilon)
            epsilon = fabs(Matr[i][_m-1] - s);
    }
    return epsilon;
}

void Matrix::Solution(Vector &x) {
    double res = 0;
    for (int i = _n-1; i >= 0; i--) {
        res = 0;
        for (int j = i+1; j <= _n-1; j++) {
            res -= x.Get(j)*Matr[i][j];
        }
        res += Matr[i][_n];
        x.Set(i, (double)(res/Matr[i][i]));
    }
}

double Matrix::Determinant() {
    double det = 1;
    for (int i = 0; i < _n; i++) {
        det *= Matr[i][i];
    }
    return det;
}

