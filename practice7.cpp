#include <iostream>
#include <cstring>
#include <map>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

template <typename G> class university_person {
    private:
        string full_name;
        string job_title;
        G groups;
    public:
        static string university_name;
        university_person() {}
        university_person(string n, string j, G g) {
            full_name = n;
            job_title = j;
            groups = g;
        }
        void set_name(string name) { full_name = name; }
        string get_name() { return full_name; }
        void set_job(string job) { job_title = job; }
        string get_job() { return job_title; }
        void set_groups(vector<string> g) { groups = g; }
        G get_groups() { return groups; }
};

void calc_students(vector<university_person<string>> &students, vector<university_person<vector<string>>> &professors) {
    map <string, int> students_count;
    // Подсчитываем студентов обучающихся у преподавателей
    for (int i=0; i<5; i++) {
        string student_group = students[i].get_groups();
        for (int j=0; j<5; j++) {
            string professor_name = professors[j].get_name();
            vector<string> professor_groups = professors[j].get_groups();
            for (const auto& professor_group : professor_groups) {
                if ( student_group == professor_group ) {
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

int calc_all_students(vector<university_person<string>> &students){
    return students.size();
}

int main() {
    vector<university_person<string>> students = {
        university_person<string>("Kuznetsov", "student", "Group1"),
        university_person<string>("Sidorov", "student", "Group2"),
        university_person<string>("Kozlov", "student", "Group3"),
        university_person<string>("Sokolov", "student", "Group1"),
        university_person<string>("Mikhailov", "student", "Group2"),
    };

    vector<university_person<vector<string>>> professors = {
        university_person<vector<string>>("Ivanov", "professor", vector<string>{ "Group1", "Group2" }),
        university_person<vector<string>>("Petrov", "professor", vector<string>{ "Group2", "Group3" }),
        university_person<vector<string>>("Smirnov", "professor", vector<string>{ "Group1", "Group2", "Group3" }),
        university_person<vector<string>>("Popov", "professor", vector<string>{ "Group1" }),
        university_person<vector<string>>("Vasilev", "professor", vector<string>{ "Group1", "Group3" })
    };

    cout << "Введите вариант задачи:" << endl;
    cout << "   1: Общее количество студентов" << endl;
    cout << "   2: Количество студентов, обучающихся у конкретного преподавателя" << endl;
    cout << "Введите номер от 1 до 2: ";

    int op;
    cin >> op;
    switch (op) {
        case 1:
            cout << "Количество стундентов: "<< calc_all_students(students) << endl;
            break;
        case 2:
            calc_students(students, professors);
            break;
        default: cout << "Неверный ввод: \n";
    }

    return 0;
}

