#ifndef MATRIX_H
#define MATRIX_H

class Vector {
private:
    double *vect;
    int _len;
public:
    Vector(int n);
    ~Vector();
    void Set(int i, double val);
    double Get(int i);
    void Print();
};

class Matrix {
private:
    double **Matr;
    int _n, _m;
public:
    Matrix(int, int);
    ~Matrix();
    void Randomize(int, int, bool);
    void Input();
    void Print();
    void One();
    void Hilbert();
    void Nullify();
    void SwapRows(int);
    void GetFile(const char *);
    void UpperTriangle();
    void Inverse(Vector &, Matrix &Inversed);
    void VerifyInverse(Matrix &);
    double EpsCheck(Vector &);
    void Solution(Vector &);
    double Determinant();
    void CopyMatrix(Matrix &);
};

#endif