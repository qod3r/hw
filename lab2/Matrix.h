#ifndef MATRIX_H
#define MATRIX_H

class Matrix {
private:
    double **Matr;
    int _n, _m;
public:
    Matrix(int n, int m);
    ~Matrix();
    void Randomize(int a, int b);
    void Input();
    void Print();
};

#endif