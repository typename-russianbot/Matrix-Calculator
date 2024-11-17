//* |===Matrix Calculator Prototype===|
//* - calculates a n x n matrix || n must be < ...

#include "MatrixCalculator.h"
#include "Matrix.h"
#include <chrono>

//* Code Block for Program Duration
// auto start = chrono::high_resolution_clock::now();
// auto end = chrono::high_resolution_clock::now();
// chrono::duration<double> duration = end - start;
// cout << "Execution time: " << duration.count() << " seconds\n";

int main()
{
    MatrixCalculator mc;
    mc.runProgram();
    return 0;
}