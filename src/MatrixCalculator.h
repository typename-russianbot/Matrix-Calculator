/**
 ** |====Class - Menu====|
 **
 **
 **
 **
 **/
#pragma once

#include "Matrix.h"
#include <cstdlib>

using namespace std;

class MatrixCalculator
{
private:
    //^ Private Functions:

    //* Add
    void Addition()
    {
        int userM;
        int userN;

        cout << "|============= Addition =============|" << endl
             << "Input Dimensions [m x n]: ";

        cin >> userM >> userN;

        cout << endl;

        //* Define Matrix A & B w/ user dimensions
        Matrix A(userM, userN);
        Matrix B(userM, userN);

        //* Load Elements onto A:
        cout << "Input Elements into Matrix A: " << endl;
        A.input();

        //* Load Elements onto B:
        cout << "Input Elements into Matrix B: " << endl;
        B.input();

        cout << endl;

        //* Display A & B
        cout << "Matrix A: " << endl;
        A.display();
        cout << endl;

        cout << "Matrix B: " << endl;
        B.display();
        cout << endl;

        //* Add
        Matrix C = A + B;
        cout << "[A + B]: " << endl;
        C.display();
        cout << endl;

        cout << "|=====================================|" << endl
             << endl;
    }
    
    //* Subtract
    void Subtraction()
    {
        int userM;
        int userN;

        cout << "|============ Subtraction ============|" << endl
             << "Input Dimensions [m x n]: ";

        cin >> userM >> userN;

        cout << endl;

        //* Define Matrix A & B w/ user dimensions
        Matrix A(userM, userN);
        Matrix B(userM, userN);

        //* Load Elements onto A:
        cout << "Input Elements into Matrix A: " << endl;
        A.input();

        //* Load Elements onto B:
        cout << "Input Elements into Matrix B: " << endl;
        B.input();

        cout << endl;

        //* Display A & B
        cout << "Matrix A: " << endl;
        A.display();
        cout << endl;

        cout << "Matrix B: " << endl;
        B.display();
        cout << endl;

        //* Add
        Matrix C = A - B;
        cout << "[A - B]: " << endl;
        C.display();
        cout << endl;

        cout << "|=====================================|" << endl
             << endl;
    }
    
    //* Multiplication
    void Multiplication() {}
    
    //* Scale
    void Scale() {}

    //* Determinant
    void Determinant() {}

    //* Adjugate
    void Adjugate() {}

    //* Transpose
    void Transpose() {}

    //* Inverse
    void Inverse() {}

    //* Rank
    void Rank() {}

    //* RowReduce
    void RowReduce() {}

public:
    //^ Construct
    MatrixCalculator() {};

    //^ Public Functions:

    //* getInput()
    int getInput()
    {
        displayMenu();

        int uInput;

        do
        {
            cout << ">> ";
            cin >> uInput;
        } while (uInput < 1 || uInput > 11);

        return uInput;
    }

    //* display()
    void displayMenu()
    {
        cout << "|==========Matrix Calculator==========|" << endl
             << "|Matrix Operations:                   |" << endl
             << "| 1. Add                              |" << endl
             << "| 2. Subtract                         |" << endl
             << "| 3. Multiply                         |" << endl
             << "| 4. Scale                            |" << endl
             << "| 5. Determinant                      |" << endl
             << "| 6. Adjugate                         |" << endl
             << "| 7. Transpose                        |" << endl
             << "| 7. Inverse                          |" << endl
             << "| 9. Rank                             |" << endl
             << "|10. Row Reduce                       |" << endl
             << "|11. Exit                             |" << endl
             << "|=====================================|" << endl;
    }

    //* runProgram()
    void runProgram()
    {
        //* Grab input
        int userInput = getInput();
        system("clear");

        while (userInput != 10)
        {
            switch (userInput)
            {
            //* Addition
            case 1:
                Addition();
                break;

            //* Subtraction
            case 2:
                Subtraction();
                break;

            //* Multiplication
            case 3:
                Multiplication();
                break;

            //* Scale
            case 4:
                Scale();
                break;

            //* Determinant
            case 5:
                Determinant();
                break;

            //* Adjugate
            case 6:
                Adjugate();
                break;

            //* Transpose
            case 7:
                Transpose();
                break;

            //* Inverse
            case 8:
                Inverse();
                break;

            //* Rank
            case 9:
                Rank();
                break;

            //* Row Reduce
            case 10:
                RowReduce();
                break;

            //* Exit Program
            case 11:
                cout << "User Exited Program" << endl;
                return;
            }

            userInput = getInput();
        }

        return;
    }
};