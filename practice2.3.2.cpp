#include <iostream>

using namespace std;

double min_ng(double x[5]) {
    double m = x[0];
    int i;
    for (i=0; i<5; i++) {
        if ( x[i] < m ) {
            m = x[i];
        }
    }
    return m;
}

double m_g;
double arr_g[5];

void min_g() {
    // TODO: Параметры вынести в глобальные переменные
    m_g = arr_g[0];
    int i;
    for (i=0; i<5; i++) {
        if ( arr_g[i] < m_g ) {
           m_g = arr_g[i];
        }
    }
}

int main() {
    int i;
    int op;
    cout << "Введите вариант подсчета: \n  0: Без использвоания глобальных переменных\n  1: С использвоанием глобальных переменных\n";
    cin >> op;
    switch (op) {
        case 0:
            double m;
            double arr[5];
            for (i=0; i<5; i++) {
                cout << i << ": ";
                double x;
                cin >> x;
                arr[i] = x;
            }
            m = min_ng(arr);
            cout << "Наименьший элемент: " << m << "\n";
            break;
        case 1:
            for (i=0; i<5; i++) {
                cout << i << ": ";
                double x;
                cin >> x;
                arr_g[i] = x;
            }
            min_g();
            cout << "Наименьший элемент: " << m_g << "\n";
            break;
        default: cout << "Неверный ввод: \n";
    }

    return 0;
}

