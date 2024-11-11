#include <iomanip>
#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <fstream>
#include <map>


using namespace std;


// объявляем структуру Представителя университета
struct university_person {
    char full_name[20];
    char job_title[20];
    char supervisor[20];
};

// !!!! Надо было выводить без пробеллов
void mani() {
    // Задание 1.
    // Используя  манипуляторы ввода-вывода, в цикле  сформировать на экране матрицу согласно индивидуальному номеру.
    // 0
    // 1 #
    // 2 # #
    // 3 # # #
    // 4 # # # #
    // 5 # # # # #

    // Формируем строки
    for (int i=0; i<6; i++) {
        // Выводим номер строки
        cout << i << " ";
        for (int j=0; j<i; j++) {
            // Выводим знак звездочки то количество раз какое значение указано в перменной i
            cout << setfill('#') << setw(2) << " ";
        }
        // Выводим знак переноса строки
        cout << endl;
    }

}

void prepare_str(char *original_str) {
    // Задание 2.
    // Разработать функцию которая поменяеть местами Null и Zero в исходной строке "Zero Nine Null" с типом Символьный массив,
    // используя только библиотечные функции (обращение к элементам символьного массива по индексу запрещено).
    // При этом для исходной строки динамически выделить память в главной функции.

    int first_position;
    // Ищем в строке первый пробел
    char *first = strchr(original_str, ' ');
    // Получаем количество символов до первого пробела
    first_position = strcspn(original_str," ");
    // Создаем новую строку для первого слова
    char first_word[first_position];
    // Копируем первое слово в новую переменную
    strncat(first_word, original_str, first_position);

    // Получаем указательно на последнйи пробел в исходной строке
    char *last = strrchr(original_str, ' ');
    // Создаем новую строку для последнего слова
    char last_word[strlen(last)];
    // Копируем последнее слово в новую переменную
    strncat(last_word, last+1, strlen(last));

    // Создаем новую переменную для измененной строки
    char new_string[strlen(original_str)];
    // Вставляем последнее слово
    strcat(new_string,last_word);
    // Вставляем все символы между первым и последним словами
    strncat(new_string,first,strlen(original_str)-(first_position+strlen(last))+1);
    // Вставляем первое слово
    strcat(new_string,first_word);

    cout << new_string << endl;
}

void make_struct() {
    // Задание 3.
    // Спроектировать структуру, описывающую характеристики «Представителя университета».
    // Создать массив из 5-ти структурных переменных и записать их в файл, как показано на рисунке ниже.
    // Определить "Количество студентов, обучающихся у конкретного преподавателя"

    // объявляем массив структур
    university_person university[5] = {
        {"Ivanov", "professor", "none"},
        {"Petrov", "professor", "none"},
        {"Kuznetsov", "student", "Petrov"},
        {"Sidorov", "student", "Ivanov"},
        {"Kozlov", "student", "Petrov"},
    };
    // создаем поток вывода, создаем файл и открываем на запись
    ofstream out;
    char filename[] = "practice3.txt";
    out.open(filename);
    // проверяем что файл успешно открылся
    if (!out) {
        cout<<"Ошибка открытия файла " << filename << endl;
    } else {
        // записываем фамилии в файл
        for (int i=0; i<sizeof(university)/sizeof(*university); i++) {
            out << setfill(' ') << setw(15) << left << university[i].full_name ;
        }
        out << endl << left;
        // записываем должность в файл
        for (int i=0; i<sizeof(university)/sizeof(*university); i++) {
            out << setfill(' ') << setw(15) << left << university[i].job_title;
        }
        out << endl << left;
        // записываем руководителя в файл
        for (int i=0; i<sizeof(university)/sizeof(*university); i++) {
            out << setfill(' ') << setw(15) << left << university[i].supervisor;
        }
        out << endl << left;
        // закрываем файл
        out.close();
    }

    // подсчитываем количество студентов
    // объявляем карту
    map <string, int> students;
    for (int i=0; i<sizeof(university)/sizeof(*university); i++) {
        if ( ! strcmp(university[i].job_title, "student") ) {
            students[university[i].supervisor] += 1;
        }
    }
    for (const auto& [supervisor, count] : students) {
        cout << supervisor << ": " << count << endl;
    }
}

void read_struct(int position) {
    // Задание 4.
    // Прочитать из файла информацию о любом из «предметов»;
    string fields[3] = {"Фамилия", "Должность", "Преподаватель"};
    // создаем поток вывода, создаем файл и открываем на чтение
    ifstream in;
    char filename[] = "practice3.txt";
    in.open(filename);
    // проверяем открытие файла
    if (!in) {
        cout<<"Ошибка открытия файла " << filename << endl;
    } else {
        string line;
        // читаем файл построчно
        int line_num = 0;
        while (getline(in, line)) {
            string newline = line;
            // ищем позицию указанную пользователем
            for (int i=0; i<position; i++) {
                int last_index = newline.find(' ');
                if (i == position-1) {
                    // выводим значение из позиции
                    string found = newline.substr(0, last_index);
                    cout << fields[line_num] << ": " << found << endl;
                    break;
                }
                // перезаписываем временную строку
                newline = newline.substr(last_index, newline.length()-last_index);
                // удаляем пробелы вначале строки
                newline.erase(0, newline.find_first_not_of(" \t\n\r\f\v"));
            }
            line_num += 1;
        }
        in.close();
    }
}

int main() {
    char *s = new char[15];
    s = "Zero Nine Null";

    cout << "Введите вариант задачи:" << endl;
    cout << "   1: Манипуляторы ввода-вывода" << endl;
    cout << "   2: Работа с символьным массивом" << endl;
    cout << "   3: Работа со структурой" << endl;
    cout << "   4: Прочитать структуру" << endl;
    cout << "   5: Выйти из программы" << endl;
    cout << "Введите номер от 1 до 5: ";

    int op;
    cin >> op;
    switch (op) {
        case 1:
            mani();
            break;
        case 2:
            prepare_str(s);
            break;
        case 3:
            make_struct();
            break;
        case 4:
            cout << "Какого представителя института из файла вывести?:" << endl;
            cout << "Введите число от 1 до 5: ";
            int member;
            cin >> member;
            if (0 < member and member < 6) {
                read_struct(member);
            }
            break;
        case 5:
            return 0;
            break;
        default: cout << "Неверный ввод: \n";
    }

    return 0;
}

