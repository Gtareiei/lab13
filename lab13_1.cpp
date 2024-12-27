#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << fixed << setprecision(2);
    cout << "Arithmetic Mean = " << B[0] << endl;
    cout << "Standard Deviation = " << B[1] << endl;
    cout << "Geometric Mean = " << B[2] << endl;
    cout << "Harmonic Mean = " << B[3] << endl;
    cout << "Max = " << B[4] << endl;
    cout << "Min = " << B[5];
    return 0;
}
void stat(const double x[], int N, double y[]) {
    double sum = 0;
    double sum_sq = 0;
    double product = 1;
    double harmonic_sum = 0;
    double max = x[0];
    double min = x[0];

    for (int i = 0; i < N; i++) {
        sum += x[i];
        sum_sq += x[i] * x[i];
        product *= x[i];
        harmonic_sum += 1.0 / x[i];
        if (x[i] > max) max = x[i];
        if (x[i] < min) min = x[i];
    }

    y[0] = sum / N;
    double mean_sq = sum_sq / N;
    y[1] = sqrt(mean_sq - (y[0] * y[0]));
    y[2] = pow(product, 1.0 / N);
    y[3] = N / harmonic_sum;
    y[4] = max;
    y[5] = min;
}
