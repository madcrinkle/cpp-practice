#include <iostream>
#include <cstring>
#include <map>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "practice5_classes.h"
using namespace std;


// Функция расчета количества студентов обущающихся у конкретных преподавателей
void calc_students(student students[], professor professors[]) {
    map <string, int> students_count;
    // Подсчитываем студентов обучающихся у преподавателей
    for (int i=0; i<5; i++) {
        vector<string> student_group = students[i].get_groups();
        for (int j=0; j<5; j++) {
            string professor_name = professors[j].get_professor_name();
            vector<string> professor_groups = professors[j].get_professor_group();
            for (const auto& group : professor_groups) {
                if ( group == student_group[0] ) {
                    students_count[professor_name] += 1;
                }
            }
        }
    }
    // Выводим количество стундентов обучающихся у преподавателей
    for (const auto& [name, count] : students_count) {
        cout << name << ": " << count << endl;
    }
}

int main() {
    student *students = new student[5];
    students[0] = student("Kuznetsov", vector<string>{ "Group1" });
    students[1] = student("Sidorov", vector<string>{ "Group2" });
    students[2] = student("Kozlov", vector<string>{ "Group3" });
    students[3] = student("Sokolov", vector<string>{ "Group1" });
    students[4] = student("Mikhailov", vector<string>{ "Group2" });

    professor *professors = new professor[5];
    professors[0] = professor("Ivanov", vector<string>{ "Group1", "Group2" });
    professors[1] = professor("Petrov", vector<string>{ "Group2", "Group3" });
    professors[2] = professor("Smirnov", vector<string>{ "Group1", "Group2", "Group3" });
    professors[3] = professor("Popov", vector<string>{ "Group1" });
    professors[4] = professor("Vasilev", vector<string>{ "Group1", "Group3" });

    calc_students(students, professors);

    return 0;
}

