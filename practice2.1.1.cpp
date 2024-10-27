#include <iostream>

using namespace std;

long int summa(signed long int a, char b) {
    int c = b;
    return a + c;
}

int memmory(float a) {
    return sizeof(a);
}

int main() {
    signed long int a;
    char b;
    float sum;
    cout << "Введите значение с типом signed long int: ";
    cin >> a;
    cout << "Введите значение с типом char: ";
    cin >> b;
    sum = summa(a, b);
    cout << "Сумма А + В: " << sum << "\n";

    cout << "Размер памяти: " << memmory(sum) << "\n";

    return 0;
}

