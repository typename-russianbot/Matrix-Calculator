#pragma once

#include "Matrix.h"

void TestMatrix()
{
    Matrix A(2);
    Matrix B(3);
    int sizeA = A.getSize();
    int sizeB = B.getSize();

    int a[sizeA] = {1, 2, 3, 4};
    int *pa = a;
    int b[sizeB] = {2, 2, 3, 9, 1, 2, 9, 0, 3};
    int *pb = b;

    A.setArray(*&pa);

    B.setArray(pb);
    B.input();

    cout << "Matrix A: " << endl;
    A.display();

    cout << endl
         << endl;

    cout << "Matrix B: " << endl;
    B.display();

    int detA = A.det();
    int detB = B.det();

    cout << "det(A): " << detA << endl;
    cout << "det(B): " << detB << endl;
}
