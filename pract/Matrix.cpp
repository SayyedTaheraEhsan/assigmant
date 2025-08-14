// Matrix.cpp

#include <iostream>
#include <cmath>
#include "Matrix.h"

using namespace std;

void Matrix::input() {
    cout << "Enter elements of a 3x3 matrix:\n";
    for (int i = 0; i < SIZE; ++i)
        for (int j = 0; j < SIZE; ++j)
            cin >> mat[i][j];
}

void Matrix::display(const char* name) {
    cout << name << ":\n";
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j)
            cout << mat[i][j] << "\t";
        cout << endl;
    }
    cout << endl;
}

Matrix Matrix::add(const Matrix& other) {
    Matrix result;
    for (int i = 0; i < SIZE; ++i)
        for (int j = 0; j < SIZE; ++j)
            result.mat[i][j] = mat[i][j] + other.mat[i][j];
    return result;
}

Matrix Matrix::subtract(const Matrix& other) {
    Matrix result;
    for (int i = 0; i < SIZE; ++i)
        for (int j = 0; j < SIZE; ++j)
            result.mat[i][j] = mat[i][j] - other.mat[i][j];
    return result;
}

Matrix Matrix::multiply(const Matrix& other) {
    Matrix result;
    result.setZero();
    for (int i = 0; i < SIZE; ++i)
        for (int j = 0; j < SIZE; ++j)
            for (int k = 0; k < SIZE; ++k)
                result.mat[i][j] += mat[i][k] * other.mat[k][j];
    return result;
}

void Matrix::setZero() {
    for (int i = 0; i < SIZE; ++i)
        for (int j = 0; j < SIZE; ++j)
            mat[i][j] = 0;
}

void Matrix::identity() {
    setZero();
    for (int i = 0; i < SIZE; ++i)
        mat[i][i] = 1;
}

void Matrix::doolittle(Matrix& L, Matrix& U) {
    L.setZero(); U.setZero();
    for (int i = 0; i < SIZE; ++i) {
        // Upper
        for (int k = i; k < SIZE; ++k) {
            U.mat[i][k] = mat[i][k];
            for (int j = 0; j < i; ++j)
                U.mat[i][k] -= L.mat[i][j] * U.mat[j][k];
        }

        // Lower
        for (int k = i; k < SIZE; ++k) {
            if (i == k)
                L.mat[i][i] = 1;
            else {
                L.mat[k][i] = mat[k][i];
                for (int j = 0; j < i; ++j)
                    L.mat[k][i] -= L.mat[k][j] * U.mat[j][i];
                L.mat[k][i] /= U.mat[i][i];
            }
        }
    }
}

void Matrix::crout(Matrix& L, Matrix& U) {
    L.setZero(); U.setZero();
    for (int i = 0; i < SIZE; ++i) {
        U.mat[i][i] = 1;

        // Lower
        for (int j = i; j < SIZE; ++j) {
            L.mat[j][i] = mat[j][i];
            for (int k = 0; k < i; ++k)
                L.mat[j][i] -= L.mat[j][k] * U.mat[k][i];
        }

        // Upper
        for (int j = i + 1; j < SIZE; ++j) {
            U.mat[i][j] = mat[i][j];
            for (int k = 0; k < i; ++k)
                U.mat[i][j] -= L.mat[i][k] * U.mat[k][j];
            U.mat[i][j] /= L.mat[i][i];
        }
    }
}

void Matrix::cholesky(Matrix& L) {
    L.setZero();
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j <= i; ++j) {
            double sum = 0;
            for (int k = 0; k < j; ++k)
                sum += L.mat[i][k] * L.mat[j][k];

            if (i == j)
                L.mat[i][j] = sqrt(mat[i][i] - sum);
            else
                L.mat[i][j] = (1.0 / L.mat[j][j]) * (mat[i][j] - sum);
        }
    }
} 

Matrix Matrix::getUpper() {
    Matrix result;
    result.setZero();
    for (int i = 0; i < SIZE; ++i)
        for (int j = i; j < SIZE; ++j)
            result.mat[i][j] = mat[i][j];
    return result;
}

Matrix Matrix::getLower() {
    Matrix result;
    result.setZero();
    for (int i = 0; i < SIZE; ++i)
        for (int j = 0; j <= i; ++j)
            result.mat[i][j] = mat[i][j];
    return result;
}

void Matrix::gaussJacobi(double* b, double* x, int iterations) {
    double temp[SIZE] = {0};
    for (int it = 0; it < iterations; ++it) {
        for (int i = 0; i < SIZE; ++i) {
            double sum = 0;
            for (int j = 0; j < SIZE; ++j) {
                if (i != j)
                    sum += mat[i][j] * x[j];
            }
            temp[i] = (b[i] - sum) / mat[i][i];
        }

        // Update x
        for (int i = 0; i < SIZE; ++i)
            x[i] = temp[i];
    }

    cout << "Solution using Gauss-Jacobi:\n";
    for (int i = 0; i < SIZE; ++i)
        cout << "x[" << i << "] = " << x[i] << endl;
}

void Matrix::gaussSeidel(double* b, double* x, int iterations) {
    double prevX[SIZE] = {0};
}

double Matrix::euclideanNorm(double* x1, double* x2) {
    double sum = 0;
    for (int i = 0; i < SIZE; ++i)
        sum += pow(x1[i] - x2[i], 2);
    return sqrt(sum);
}

double Matrix::residualNorm(double* b, double* x) {
    double res[SIZE] = {0};
    for (int i = 0; i < SIZE; ++i) {
        res[i] = b[i];
        for (int j = 0; j < SIZE; ++j)
            res[i] -= mat[i][j] * x[j];
    }
    double sum = 0;
    for (int i = 0; i < SIZE; ++i)
        sum += res[i] * res[i];
    return sqrt(sum);
}

double Matrix::normalizedResidualNorm(double* b, double* x) {
    double norm_b = 0;
    for (int i = 0; i < SIZE; ++i)
        norm_b += b[i] * b[i];
    return residualNorm(b, x) / sqrt(norm_b);
}
