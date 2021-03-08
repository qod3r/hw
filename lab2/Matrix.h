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
    void Print(bool);
    void GetFile(const char *);
    void UpperTriangle();
    void Solution(Vector &);
};

#endif