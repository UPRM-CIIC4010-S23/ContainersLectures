#include <iostream>
#include <cmath>
#include <functional>

using namespace std;

function<double(double)> derivative(function<double(double)> f) {
    return ([f] (double x) {
        double deltaX = 0.000001;
        return (f(x+deltaX) - f(x)) / deltaX;
    });
}

double newtonRoot(double guess, double epsilon, function<double(double)> f) {

    long maxIterations =  10000;
    double x1 = guess;
    long i = 0;

    while ((abs(f(x1)) > epsilon) && (i < maxIterations)) {
        x1 = x1 - (f(x1) / (derivative(f))(x1));
        i++;
    }

    if (i >= maxIterations) {
        return NAN;
    } else {
        return x1;
    }


}

double integrate(double start, double end, function<double(double)> f)
{

    long numIntervals = 10000;
    double result = 0;

    double deltaX = (end-start) / numIntervals;

    double xBar = start;
    for (long i = 0; i<numIntervals; i++) {

        double nextArea = deltaX * ((f(xBar) + f(xBar+deltaX))/2.0);
        result += nextArea;
        xBar += deltaX;

    }

    return result;


}

double fsquare(double x) {
    return x * x;
}

int main() {

    cout << integrate(0,M_PI/2,[] (double x) { return sin(x); }) << endl;

    // cout << "Derivative x^3 at x=4: " << (derivative([](double x){return x*x*x;})(4.0)) << endl;
    // cout << "2nd Derivative x^3 at x=4: " << (derivative(derivative([](double x){return x*x*x;})))(4.0) << endl;

    // cout << "Derivative x^2 at x=4: " << (derivative([](double x){return x*x;})(4.0)) << endl;
    // cout << "2nd Derivative x^2 at x=4: " << (derivative(derivative([](double x){return x*x;})))(4.0) << endl;

    double root = newtonRoot(0.5,0.00000001,[](double x){return (x*x)-4;});
    cout <<  "Newton root: " 
        << root
        << "F at root: "
        << ([](double x){return (x*x)-4;})(root)
        << endl;

}