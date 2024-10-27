#include <iostream>

using namespace std;

double min(double x[5]) {
    double m = x[0];
    int i;
    for (i=0; i<=5; i++) {
        if ( x[i] < m ) {
            m = x[i];
        }
    }
    return m;
}

int main() {
    double arr[5];
    int i;
    double m;
    for (i=0; i<5; i++) {
        cout << i << ": ";
        cin >> arr[i];
    }
    m = min(arr);
    cout << "Наименьший элемент: " << m << "\n";

    return 0;
}

