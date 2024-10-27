#include <iostream>
#include <cstring>
#include <map>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "practice6_classes.h"
using namespace std;

string University::university_person::university_name = "SUT";

void calc_students(University::student students[], University::professor professors[]) {
    map <string, int> students_count;
    // Подсчитываем студентов обучающихся у преподавателей
    for (int i=0; i<5; i++) {
        for (int j=0; j<5; j++) {
            string professor_name = professors[j].get_professor_name();
            if ( students[i]==professors[j] ) {
                students_count[professor_name] += 1;
            }
        }
    }
    // Выводим количество стундентов обучающихся у преподавателей
    for (const auto& [name, count] : students_count) {
        cout << name << ": " << count << endl;
    }
}

// Переопределяем функцию для подсчета студентов
void calc_students(University::professor professors[], University::student students[]) {
    calc_students(students, professors);
}

// Выводим информацию о проекте
void show_project(University::student students[]) {
    University::university_person *pperson;
    for (int i=0; i<5; i++) {
        pperson = &students[i];
        pperson->show_class();
    }
}

int main() {
    University::student *students = new University::student[5];
    students[0] = University::student("Kuznetsov", vector<string>{ "Group1" });
    students[1] = University::student("Sidorov", vector<string>{ "Group2" });
    students[2] = University::student("Kozlov", vector<string>{ "Group3" });
    students[3] = University::student("Sokolov", vector<string>{ "Group1" });
    students[4] = University::student("Mikhailov", vector<string>{ "Group2" });

    University::professor *professors = new University::professor[5];
    professors[0] = University::professor("Ivanov", vector<string>{ "Group1", "Group2" });
    professors[1] = University::professor("Petrov", vector<string>{ "Group2", "Group3" });
    professors[2] = University::professor("Smirnov", vector<string>{ "Group1", "Group2", "Group3" });
    professors[3] = University::professor("Popov", vector<string>{ "Group1" });
    professors[4] = University::professor("Vasilev", vector<string>{ "Group1", "Group3" });

    cout << "Введите вариант задачи:" << endl;
    cout << "   1: Содержимое проекта" << endl;
    cout << "   2: Количество студентов, обучающихся у конкретного преподавателя" << endl;
    cout << "Введите номер от 1 до 2: ";

    int op;
    cin >> op;
    switch (op) {
        case 1:
            show_project(students);
            break;
        case 2:
            calc_students(professors, students);
            break;
        default: cout << "Неверный ввод: \n";
    }

    return 0;
}

