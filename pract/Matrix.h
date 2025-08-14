// Matrix.h
#ifndef MATRIX_H
#define MATRIX_H

const int SIZE = 3;

class Matrix {
    double mat[SIZE][SIZE];
public:
    void input();
    void display(const char* name);
    void setZero();
    void identity();               // Identity Matrix
    Matrix add(const Matrix& other);
    Matrix subtract(const Matrix& other);
    Matrix multiply(const Matrix& other);

    void doolittle(Matrix& L, Matrix& U);
    void crout(Matrix& L, Matrix& U);
    void cholesky(Matrix& L);

    Matrix getUpper();
    Matrix getLower();

    void gaussJacobi(double* b, double* x, int iterations);
      void gaussSeidel(double* b, double* x, int iterations);
    double euclideanNorm(double* x1, double* x2);
    double residualNorm(double* b, double* x);
    double normalizedResidualNorm(double* b, double* x);

#endif
