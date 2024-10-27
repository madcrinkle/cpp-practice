#include <iostream>

using namespace std;

float sum;

void summa(signed long int a, char b) {
    int c = b;
    sum = a + c;
}

int memmory(float a) {
    return sizeof(a);
}

int main() {
    signed long int a;
    char b;

    cout << "Введите значение с типом signed long int: ";
    cin >> a;
    cout << "Введите значение с типом char: ";
    cin >> b;
    summa(a, b);
    cout << "Сумма А + В: " << sum << "\n";

    cout << "Размер памяти: " << memmory(sum) << "\n";

    return 0;
}

