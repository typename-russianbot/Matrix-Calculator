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
    bool isSquare{false}; //* if m == n, isSquare = true

    //^ |===Private Functions===|
    //* setSize()
    void setSize(const int &newSize)
    {
        this->size = newSize;
    }
    //* setM()
    void setM(const int &newM)
    {
        this->m = newM;
    }
    //* setN()
    void setN(const int &newN)
    {
        this->n = newN;
    }

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
    //? -takes two integer parameters than set n & m to their respective new values
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

    //^ |===Public Functions===|

    //* clear()
    //? - resets the matrix & all conditions to 0
    void clear()
    {
        array.clear();
        size = 0;
        m = 0;
        n = 0;
        isSquare = false;
    }
    //* getSize()
    //? - returns the current size of the matrix
    int getSize()
    {
        return size;
    }
    //* setMatrix()
    void setMatrix(int m, int n)
    {
        this->setM(m);
        this->setN(n);
        this->setSize(m * n);
        array.resize(m * n);
    }
    //* setArray()
    //? - copies the contents of nMatrix into this matrix
    void setArray(vector<int> &nMatrix)
    {
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                array[i * n + j] = nMatrix[i * n + j];
            }
        }
    }

    //^ |===Matrix Operations===|

    //* display() -- in progress
    //? displays the current matrix
    void display()
    {
        for (int i = 0; i < m; i++)
        {
            cout << "\t|  ";
            for (int j = 0; j < n; j++)
            {
                int element = array[i * n + j];
                cout << element << "  |  ";
            }
            cout << endl;
        }
    }
    //* input()
    //? - grabs user input & inputs that into the current matrix
    void input()
    {
        cout << "Matrix Dimensions: [" << m << ", " << n << "]" << endl;
        cout << "Inserting [" << size << "] Elements: ";

        for (int i = 0; i < size; i++)
        {
            cin >> array[i];
        }
    }
    //* determinant() -- in progress
    int determinant()
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
    //* adjugate() -- in progress
    int adjugate()
    {
        return 0;
    }
    //* transpose()
    //? - transposes a given matrix
    //? - sets every element at a given position [i, j] to [j, i]
    void transpose()
    {
        //* Method for square matrices:
        if (isSquare == true)
        {
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (i - j == 0)
                    {
                        break;
                    }
                    else
                    {
                        int temp = array[i * n + j];
                        array[i * n + j] = array[j * n + i];
                        array[j * n + i] = temp;
                    }
                }
            }
        }

        //* Method for non-square matrices
        else
        {
            Matrix copy{n, m};

            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    copy.array[j * copy.n + i] = this->array[i * n + j];
                }
            }

            //*
            m = copy.m;
            n = copy.n;
            this->setArray(copy.array);
        }
    }
    //* inverse() -- in progress
    //? - inverses a given matrix
    bool inverse()
    {
        int det = determinant();

        //! if determinant of matrix = 0, matrix is not invertible
        if (det == 0)
        {
            cerr << "ERROR -- Cannot invert matrix" << endl;
            return false;
        }

        return true;
    }

    //* Addition
    Matrix operator+(const Matrix &other) const
    {
        //* create result matrix:
        Matrix result(m, n);

        //! Check addition validity
        if (m != other.m || n != other.n)
        {
            cerr << "ERROR -- Matrix Overflow/Underflow occurred" << endl;
            return result; 
        }

        //* add a
        for (int i = 0; i < size; i++)
        {
            result.array[i] = this->array[i] + other.array[i];
        }

        return result;
    }
    //* Subtraction
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
    //* Scaling [Matrix * int]
    Matrix operator*(int scalar) const
    {
        Matrix result(m, n);

        for (int i = 0; i < size; i++)
        {
            result.array[i] = array[i] * scalar;
        }

        return result;
    }
    //* Scaling [int * Matrix]
    friend Matrix operator*(int scalar, const Matrix &other)
    {
        return other * scalar;
    }
    //* Matrix Multiplication
    Matrix operator*(const Matrix &other)
    {
        Matrix result(m, n);

        //* matrices can only be multiplied if m is equal to other m or n
        if (this->m == other.n)
        {
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < other.n; j++)
                {
                }
            }
        }
        else if (this->m != other.n && this->m == other.m)
        {
            // cout << "matrices can be multiplied if transposed" << endl;
        }

        return result;
    }
};