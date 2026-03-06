#include <iostream>
#include <iomanip>
#include <cmath>
#include <chrono>
using namespace std;

// ============================================================
// Function to integrate
// Example: f(x) = x^2
// Integral from 0 to 1 should be 1/3
// ============================================================
double f(double x)
{
    return x * x;
}

// ============================================================
// Exact value of the integral (for comparison)
// ============================================================
double exactIntegral()
{
    return 1.0 / 3.0;
}

// ============================================================
// Kahan Summation Algorithm
// Improves precision by compensating for floating-point errors
// values[] : array of numbers to sum
// n        : number of elements
// ============================================================
double kahanSum(double* values, int n)
{
    double sum = 0.0;
    double c = 0.0; // compensation for lost precision

    for(int i = 0; i < n; i++)
    {
        double y = values[i] - c; // adjust value with compensation
        double t = sum + y;       // temporary sum
        c = (t - sum) - y;        // new compensation
        sum = t;                  // update sum
    }

    return sum;
}

// ============================================================
// Numerical Integration using Rectangle Method
// a : lower limit
// b : upper limit
// N : number of steps
// Returns approximate integral using Kahan summation
// ============================================================
double integrate(double a, double b, int N)
{
    double dx = (b - a) / N;          // width of each rectangle
    double* terms = new double[N];    // store each rectangle's area

    // Compute each term
    for(int i = 0; i < N; i++)
    {
        double x = a + i * dx;
        terms[i] = f(x) * dx;
    }

    // Sum all terms with high-precision Kahan summation
    double result = kahanSum(terms, N);

    delete[] terms; // free memory
    return result;
}

// ============================================================
// Main Function
// ============================================================
int main()
{
    double a = 0.0;                 // integration lower bound
    double b = 1.0;                 // integration upper bound
    int N = 1000000;                // number of steps for high precision

    // ------------------------------
    // Measure execution time
    // ------------------------------
    auto start = chrono::high_resolution_clock::now();
    double result = integrate(a, b, N);
    auto end = chrono::high_resolution_clock::now();

    // ------------------------------
    // Calculate absolute error
    // ------------------------------
    double error = fabs(result - exactIntegral());

    // ------------------------------
    // Display results with precision
    // ------------------------------
    cout << fixed << setprecision(10);
    cout << "Computed integral: " << result << endl;
    cout << "Exact integral   : " << exactIntegral() << endl;
    cout << "Absolute error   : " << error << endl;

    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    cout << "Execution time   : " << duration.count() << " ms" << endl;

    // ------------------------------
    // Check if target precision achieved
    // ------------------------------
    if(error < 1e-6)
    {
        cout << "Precision goal achieved (<= 1e-6)...." << endl;
    }
    else
    {
        cout << "Precision goal NOT achieved ...." << endl;
    }

    return 0;
}