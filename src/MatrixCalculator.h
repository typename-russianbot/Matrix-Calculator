/**
 ** |============================MatrixCalculator============================|
 ** - Currently, all the matrix ops are private.
 ** - May want to create matrix vars in the class before-hand
 ** - to save memory & use currently stored matrices, opposed
 ** - to defining them over and over w/ each function call.
 ** |========================================================================|
 **/
#pragma once

#include "Matrix.h"
#include <cstdlib>
#include <chrono>

using namespace std;
class MatrixCalculator
{
private:
    //^ Attributes:
    Matrix A;
    Matrix B;
    bool isEmptyA;
    bool isEmptyB;

    //^ Private Functions:
    //* getMenuInput()
    int getMenuInput()
    {
        displayMenu();

        int uInput;

        do
        {
            cout << " >> ";
            cin >> uInput;
        } while (uInput < 1 || uInput > 14);

        return uInput;
    }

    //* displayMenu()
    void displayMenu()
    {
        cout << "|==========Matrix Calculator==========|" << endl
             << "|Matrix Operations:                   |" << endl
             << "| 1. Set Matrices                     |" << endl
             << "| 2. Reset Matrices                   |" << endl
             << "| 3. Display Matrices                 |" << endl
             << "| 4. Add                              |" << endl
             << "| 5. Subtract                         |" << endl
             << "| 6. Multiply                         |" << endl
             << "| 7. Scale                            |" << endl
             << "| 8. Determinant                      |" << endl
             << "| 9. Adjugate                         |" << endl
             << "|10. Transpose                        |" << endl
             << "|11. Inverse                          |" << endl
             << "|12. Rank                             |" << endl
             << "|13. Row Reduce                       |" << endl
             << "|14. Exit                             |" << endl
             << "|=====================================|" << endl;
    }

    //^ Matrix Operations:
    //* setMatrices()
    //? - sets A, B, or both depending on user selection
    void setMatrices()
    {
        int uInput = 0;
        int m{0}, n{0};

        do
        {
            cout << "|==========Matrix Calculator==========|" << endl
                 << "| 1. Set A                            |" << endl
                 << "| 2. Set B                            |" << endl
                 << "| 3. Set A & B                        |" << endl
                 << "|=====================================|" << endl
                 << " >> ";

            cin >> uInput;
        } while (uInput < 1 || uInput > 3);

        system("clear");

        switch (uInput)
        {
        case 1: //* Initialize A
            cout << "|==========Initialize Matrix==========|" << endl;
            isEmptyA = false;

            cout << "Set Matrix A Dimensions: ";
            cin >> m >> n;
            A.setMatrix(m, n);

            A.input();

            cout << "|=====================================|" << endl;

            break;

        case 2: //* Initialize B
            cout << "|==========Initialize Matrix==========|" << endl;
            isEmptyB = false;

            cout << "Set Matrix B Dimensions: ";
            cin >> m >> n;
            B.setMatrix(m, n);

            B.input();
            cout << "|=====================================|" << endl;
            break;

        case 3: //* Initialize A & B
            cout << "|==========Initialize Matrix==========|" << endl;
            isEmptyA = isEmptyB = false;

            cout << "Set Matrix A Dimensions: ";
            cin >> m >> n;
            A.setMatrix(m, n);

            A.input();

            cout << endl
                 << endl;

            cout << "Set Matrix B Dimensions: ";
            cin >> m >> n;
            B.setMatrix(m, n);

            B.input();
            cout << "|=====================================|" << endl;
            break;

        default:
            break;
        }

        system("clear");
    }

    //* clearMatrices()
    //? - resets all matrices & sets isEmpty to true
    void clearMatrices()
    {
        A.clear();
        B.clear();
        isEmptyA = isEmptyB = true;
    }

    //* displayMatrices()
    //? - prints all matrices
    void displayMatrices()
    {
        cout << "|=========Outputting Matrices=========|" << endl
             << " Matrix A:                            " << endl;

        A.display();
        cout << endl;

        cout << " Matrix B:                            " << endl;

        B.display();
        cout << endl;
        cout << "|=====================================|" << endl
             << endl;
    }

    //* Add
    void Addition()
    {
        if (isEmptyA == true || isEmptyB == true)
        {
            cerr << "ERROR -- A matrix is empty" << endl;
            return;
        }

        cout << "|=============Matrix Additon=============|" << endl;
        cout << "Matrix A: " << endl;
        A.display();

        cout << endl;

        cout << "Matrix B: " << endl;
        B.display();

        Matrix result = A + B;

        cout << "Result: " << endl;
        result.display();
        cout << "|========================================|" << endl
             << endl;
    }

    //* Subtract
    void Subtraction()
    {
        if (isEmptyA == true || isEmptyB == true)
        {
            cerr << "ERROR -- A matrix is empty" << endl;
            return;
        }

        cout << "|=============Matrix Subtraction=============|" << endl;
        cout << "Matrix A: " << endl;
        A.display();

        cout << endl;

        cout << "Matrix B: " << endl;
        B.display();

        Matrix result = A - B;

        cout << "Result: " << endl;
        result.display();
        cout << "|============================================|" << endl
             << endl;
    }

    //* Multiplication -- add plug-ins
    void Multiplication() {}

    //* Scale -- in progress
    void Scale() {}

    //* Determinant -- add plug-in
    void Determinant() {}

    //* Adjugate -- in progress
    void Adjugate() {}

    //* Transpose -- Add plug-in
    void Transpose()
    {
        if (isEmptyA == false)
        {
            A.transpose();
        }
        if (isEmptyB == false)
        {
            B.transpose();
        }
        if (isEmptyA && isEmptyB == true)
        {
            cerr << "ERROR -- Both matrices are empty" << endl
                 << endl;
            return;
        }
    }

    //* Inverse -- in progress
    void Inverse()
    {
    }

    //* Rank -- in progress
    void Rank() {}

    //* RowReduce
    void RowReduce() {}

public:
    //^ Construct

    //* default():
    //? - sets Matrices A/B to 0 & isEmpty to true
    MatrixCalculator() : A(0), B(0), isEmptyA(true), isEmptyB(true) {};

    //^ Public Functions:

    //* runProgram()
    void runProgram()
    {
        //* Grab input
        int userInput = getMenuInput();
        system("clear");

        while (userInput != 14)
        {
            switch (userInput)
            {
            //* Set Matrices
            case 1:
                setMatrices();
                break;

            //* Clear Matrices:
            case 2:
                clearMatrices();
                break;

            //* Display Matrices
            case 3:
                displayMatrices();
                break;

            //* Addition
            case 4:
                Addition();
                break;

            //* Subtraction
            case 5:
                Subtraction();
                break;

            //* Multiplication
            case 6:
                Multiplication();
                break;

            //* Scale
            case 7:
                Scale();
                break;

            //* Determinant
            case 8:
                Determinant();
                break;

            //* Adjugate
            case 9:
                Adjugate();
                break;

            //* Transpose
            case 10:
                Transpose();
                break;

            //* Inverse
            case 11:
                Inverse();
                break;

            //* Rank
            case 12:
                Rank();
                break;

            //* Row Reduce
            case 13:
                RowReduce();
                break;

            //* Exit Program
            case 14:
                cout << "User Exited Program" << endl;
                return;
            }

            userInput = getMenuInput();
            system("clear");
        }

        return;
    }
};