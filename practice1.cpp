#include <iostream>

using namespace std;

int main() {
    // Обьявление переменных
    int a;
    int b;
    float result = 0;
    char op;
    bool start = true;

    // Запуск бесконечного цикла пока в операцию над числами не приходит Q
    while (op != 'Q') {
        // Если первый запуск или программа получила C запрашиваем значение А
        if (start) {
            cout << "A : ";
            cin >> a;
            result = a;
        }
        // Меняем значение start на false, что бы в дальнейшем не запрашивалось значение А
        start = false;
        // Запрашиваем операцию над числами
        cout << "Op: ";
        cin >> op;
        if (op == 'C') {
            // Если получаем значение С в перемнной операции, то сбрасываем результат до 0
            // переводим значение start в true что бы при следующем цикле программа запросила значение А
            result = 0;
            start = true;
            cout << "Result : "<< result << "\n";
            continue;
        } else if (op == 'Q') {
            // Если получаем значение Q в перемнной операции, то выводим результат и завершаем программу
            cout << "Result : "<< result << "\n";
            continue;
        }
        // Запрашиваем значение В
        cout << "B : ";
        cin >> b;

        // В зависимости от операции над числами, выполняем необходимые действия над числами А и B
        switch(op) {
            case '+':
                result += b;
                break;
            case '-':
                result -= b;
                break;
            case '*':
                result *= b;
                break;
            case '/':
                result /= b;
                break;
            default:
                cout << 'Error of enter';
                break;
        }
        // Выводим результат
        cout << "Result : "<< result << "\n";
    }

    return 0;
}