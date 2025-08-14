#include <iostream>
#include "Matrix.h"

using namespace std;

int main() {
    Matrix A, B, C;
    Matrix L, U;

    // Input Matrix A
    cout << "Matrix A:\n";
    A.input();
    A.display("Matrix A");

    // Input Matrix B
    cout << "Matrix B:\n";
    B.input();
    B.display("Matrix B");

    // Addition
    C = A.add(B);
    C.display("A + B");

    // Subtraction
    C = A.subtract(B);
    C.display("A - B");

    // Multiplication
    C = A.multiply(B);
    C.display("A * B");
    
     // Cholesky Decomposition (A should be symmetric positive-definite)
    A.cholesky(L);
    L.display("L from Cholesky");

    // Identity Matrix Example
    Matrix I;
    I.identity();     // ✅ Correct
    I.display("Identity Matrix");

    // Doolittle Decomposition
    A.doolittle(L, U);
    L.display("L from Doolittle");
    U.display("U from Doolittle");

    // Crout Decomposition
    A.crout(L, U);
    L.display("L from Crout");
    U.display("U from Crout");
    
     // Gauss-Jacobi Method
    double b[SIZE] = {5, 12, 8};
    double x[SIZE] = {0, 0, 0};  // initial guess
    A.gaussJacobi(b, x, 10);
      //Gauss-siedel mathord 
      double b[SIZE] = {5, 12, 8};
    double x[SIZE] = {0, 0, 0};  // initial guess
    A.gaussSiedel(b, x, 10);
   
    return 0;
}
