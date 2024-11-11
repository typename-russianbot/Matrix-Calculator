//* Matrix Operations:
//* - row reduce to echelon form
//* - find the determinant
//* - find the inverse of a matrix
//* - find the adjucate of a matrix
//* - matrix subtraction
#pragma once

#include <iostream>
#include <vector>

using namespace std;

class Matrix
{
private:
    //^ |===Attributes===|
    vector<int> array;    //* m * n array
    int size;             //* size of array
    int m;                //* rows of array
    int n;                //* cols of array
    bool isSquare{false}; //*

public:
    //^ |===Constructors===|
    //* Construct 1:
    //? -- takes one integer parameter that sets both n/m to the new size
    Matrix(const int &nSize) : m(nSize), n(nSize)
    {
        isSquare = true;     //* implied that the matrix is square via the param
        array.resize(m * n); //* re-size array to correctly match dimensions
        size = static_cast<int>(array.size());

        //* initialize matrix w/ zeroes
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                array[i * n + j] = 0;
            }
        }
    }

    //* Construct 2:
    //? -- takes a single integer & an integer array w/ filled out elements
    Matrix(const int &nSize, int *nMatrix) : m(nSize), n(nSize)
    {
        isSquare = true;                       //* always a square matrix if in this construct
        array.resize(m * n);                   //* re-size array
        size = static_cast<int>(array.size()); //* update size

        //* initialize
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                array[i * n + j] = nMatrix[i * n + j];
            }
        }
    }

    //* Construct 3:
    //? -- takes two integer parameters than set n & m to their respective new values
    Matrix(const int &nRows, const int &nCols) : m(nRows), n(nCols)
    {
        //* is still possible to encounter a square matrix in this constructor
        if (m == n)
        {
            isSquare = true;
        }
        array.resize(m * n);                   //* re-size array
        size = static_cast<int>(array.size()); //* update size

        //* initialize matrix w/ zeroes
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                array[i * n + j] = 0;
            }
        }
    }

    //* Construct 4:
    Matrix(const int &nRows, const int &nCols, int *nMatrix) : m(nRows), n(nCols)
    {
        if (m == n)
        {
            isSquare = true;
        }

        array.resize(m * n);                   //* re-size array
        size = static_cast<int>(array.size()); //* update size

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                array[i * n + j] = nMatrix[i * n + j];
            }
        }
    }

    //^ |===Public Functions===|
    //* getSize()
    int getSize()
    {
        return size;
    }

    //* setArray()
    //? copies the contents of nMatrix into this matrix
    void setArray(int *&nMatrix)
    {
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                array[i * n + j] = nMatrix[i * n + j];
            }
        }
    }

    //* display()
    //? displays the current matrix
    void display()
    {
        //? displays the matrix sequentially in grid format to the console
        for (int i = 0; i < m; i++)
        {
            cout << "|  ";
            for (int j = 0; j < n; j++)
            {
                int element = array[i * n + j];
                cout << element << "  |  ";
            }
            cout << endl;
        }
    }

    //* input()
    //? inserts user input into current matrix
    void input()
    {
        //?
        cout << "Input Matrix Contents Sequentially:" << endl
             << endl;

        for (int i = 0; i < size; i++)
        {
            cout << "Cell[" << i + 1 << "]: ";
            cin >> array[i];
        }
        system("clear");

        display();
    }

    //^ |===Matrix Operations===|
    
    //* det()
    int det()
    {
        int result;

        //* given array is a 2x2 matrix
        //* | a  b |
        //* | c  d |

        if (m && n == 2)
        {
            //* det(matrix) = ad - bc
            result = (array[0] * array[3]) - (array[1] * array[2]);
        }

        //* 3x3 matrix
        //* | a  b  c |
        //* | d  e  f |
        //* | g  h  i |
        //? det(matrix) = a(e * i - f * h) - b(d * i - f * g) + c(d * h - e * g)
        else if (m && n == 3)
        {
            result = (array[0] * (array[4] * array[8] - array[5] * array[7])) - (array[1] * (array[3] * array[8] - array[5] * array[6])) + (array[2] * (array[3] * array[7] - array[4] * array[6]));
        }

        //* if > 3, use diagonal det theorem

        return result;
    }

    //* adj()
    int adj()
    {
    }

    //* Matrix Addition
    Matrix operator+(const Matrix &other) const
    {
        //! Check addition validity
        if (m != other.m || n != other.n)
        {
            throw invalid_argument("Invalid Matrix Dimensions for Addition");
        }

        //* create result matrix:
        Matrix result(m, n);

        //* add a
        for (int i = 0; i < size; i++)
        {
            result.array[i] = this->array[i] + other.array[i];
        }

        return result;
    }

    //* Matrix Subtraction
    Matrix operator-(const Matrix &other) const
    {
        //! Check subtraction validity:
        if (m != other.m || n != other.n)
        {
            throw invalid_argument("Invalid Matrix Dimensions for Subtraction");
        }

        //* create result matrix:
        Matrix result(m, n);

        //* subtract:
        for (int i = 0; i < size; i++)
        {
            result.array[i] = this->array[i] - other.array[i];
        }

        return result;
    }

    //* Matrix Scaling [Matrix * int]
    Matrix operator*(int scalar) const
    {
        Matrix result(m, n);

        for (int i = 0; i < size; i++)
        {
            result.array[i] = array[i] * scalar;
        }

        return result;
    }
    //* Matrix Scaling [int * Matrix]
    friend Matrix operator*(int scalar, const Matrix &other)
    {
        return other * scalar;
    }

    //* Matrix Multiplication
    Matrix operator*(const Matrix &other)
    {
    }
};