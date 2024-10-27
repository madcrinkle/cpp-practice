#include <iostream>

using namespace std;

double m;

void min(double x[5]) {
    m = x[0];
    int i;
    for (i=0; i<=5; i++) {
        if ( x[i] < m ) {
           m = x[i];
        }
    }
}

int main() {
    double arr[5];
    int i;

    for (i=0; i<5; i++) {
        cout << i << ": ";
        double x;
        cin >> x;
        arr[i] = x;
    }
    min(arr);
    cout << "Наименьший элемент: " << m << "\n";

    return 0;
}

