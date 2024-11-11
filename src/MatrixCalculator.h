/**
 ** |====Class - Menu====|
 **
 **
 **
 **
 **/
#pragma once

#include "Matrix.h"

using namespace std;

class MatrixCalculator
{
private:
    //* Will have at max two matrices, A and B. As well as a third matrix to store solutions the given matrices.
public:
    //^ Construct
    MatrixCalculator() {};

    //^ Public Functions:
    int getInput()
    {
        int userInput;
        //* want to continue looping until a valid input is reached [1 - 9]
        do
        {
            displayMenu();
            cout << ">> ";
            cin >> userInput;
        } while (userInput < 1 || userInput > 11);

        return userInput;
    }

    //^ Matrix Operations:

    //* display()
    void displayMenu()
    {
        cout << "|==========Matrix Calculator==========|" << endl
             << "|Matrix Operations:                   |" << endl
             << "| 1. Addition                         |" << endl
             << "| 2. Subtraction                      |" << endl
             << "| 3. Multiplication                   |" << endl
             << "| 4. Determinant                      |" << endl
             << "| 5. Adjugate                         |" << endl
             << "| 6. Transpose                        |" << endl
             << "| 7. Inverse                          |" << endl
             << "| 8. Rank                             |" << endl
             << "| 9. Row Reduce                       |" << endl
             << "|10. Reset Matrices                   |" << endl
             << "|11. Exit                             |" << endl
             << "|=====================================|" << endl;
    }

    //* want to read input and run it thru a switch to determine which sub-function we want to go to
    void runProgram()
    {
        int userInput = getInput();
        while (userInput != 11)
        {
            switch (userInput)
            {
            //* Addition
            case 1:
                cout << "TODO -- addition" << endl;
                break;

            //* Subtraction
            case 2:
                cout << "TODO -- subtraction" << endl;
                break;

            //* Multiplication
            case 3:
                cout << "TODO -- multiplication" << endl;
                break;

            //* Determinant
            case 4:
                cout << "TODO -- determinant" << endl;
                break;

            //* Adjugate
            case 5:
                cout << "TODO -- adjugate" << endl;
                break;

            //* Transpose
            case 6:
                cout << "TODO -- transpose" << endl;
                break;

            //* Inverse
            case 7:
                cout << "TODO -- inverse" << endl;
                break;

            //* Rank
            case 8:
                cout << "TODO -- rank" << endl;
                break;

            //* Row Reduce
            case 9:
                cout << "TODO -- row reduce" << endl;
                break;

            //* Reset Matrix
            case 10:
                cout << "TODO -- Reset Matrix" << endl;
                break;

            //* Exit Program
            case 11:
                cout << "User Exited Program" << endl;
                userInput = 11;
                return;
            }

            userInput = getInput();
        }

        return;
    }
};