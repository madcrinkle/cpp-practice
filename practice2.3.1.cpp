#include <iostream>

using namespace std;

long int summa_ng(signed long int a, char b) {
    int c = b;
    return a + c;
}

int memmory(float a) {
    return sizeof(a);
}

float sum_g;
signed long int a_g;
char b_g;

void summa_g() {
    // TODO: Параметры вынести в глобальные переменные
    int c = b_g;
    sum_g = a_g + c;
}

int main() {
    signed long int a;
    char b;
    float sum;
    int op;
    cout << "Введите значение с типом signed long int: ";
    cin >> a;
    cout << "Введите значение с типом char: ";
    cin >> b;
    cout << "Введите вариант подсчета: \n  0: Без использвоания глобальных переменных\n  1: С использвоанием глобальных переменных\n";
    cin >> op;
    switch (op) {
        case 0:
            sum = summa_ng(a, b);
            cout << "Сумма А + В: " << sum << "\n";
            cout << "Размер памяти: " << memmory(sum) << "\n";
            break;
        case 1:
            a_g = a;
            b_g = b;
            summa_g();
            cout << "Сумма А + В: " << sum_g << "\n";
            cout << "Размер памяти: " << memmory(sum_g) << "\n";
            break;
    }

    return 0;
}

