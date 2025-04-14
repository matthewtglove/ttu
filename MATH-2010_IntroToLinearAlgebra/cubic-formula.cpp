/*
Author: Matthew Love
Date: 2025-04-14
Purpose: Calculating roots of 3rd degree polynomial
*/

#include <iostream>
using namespace std;

double[] calculateCubicPolynomialRoots (int a, int b, int c, int d) {
    double roots[3];
    double delta0 = b * b - 3 * a * c;
    double delta1 = 2 * b * b * b - 9 * a * b * c + 27 * a * a * d;

    double discriminant = delta1 * delta1 - 4 * delta0 * delta0 * delta0;

    if (discriminant > 0) {
        // Three distinct real roots
        // Implement the formula for three distinct real roots
    } else if (discriminant == 0) {
        // All roots are real and at least two are equal
        // Implement the formula for multiple roots
    } else {
        // One real root and two non-real complex conjugate roots
        // Implement the formula for one real root and complex conjugates
    }

    return roots;
}

int main () {
    double a, b, c, d;
    cout << "a: ";
    cin >> a;
    cout << endl;
    cout << "b: ";
    cin >> b;
    cout << endl;
    cout << "c: ";
    cin >> c;
    cout << endl;
    cout << "d: ";
    cin >> d;
    cout << endl;


}