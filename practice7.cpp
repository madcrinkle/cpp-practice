#include <iostream>
#include <cstring>
#include <map>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

class university_person {
private:
    string full_name;
public:
    static string university_name;

    university_person() {}

    university_person(string n) {
        full_name = n;
    }

    void set_name(string name) { full_name = name; }
    string get_name() { return full_name; }

    virtual void show_class() {
        cout << "University: " << university_name << endl;
        cout << "Name: " << full_name << endl;
    }
};

string university_person::university_name = "Example University"; // Инициализация названия университета

class professor : private university_person {
private:
    vector<string> groups;
public:
    professor() {}

    professor(string n, vector<string> g) {
        set_name(n);
        groups = g;
    }

    void set_groups(vector<string> g) { groups = g; }
    vector<string> get_groups() { return groups; }
    string get_professor_name() { return get_name(); }
    vector<string> get_professor_group() { return get_groups(); }
};

class student : public university_person {
private:
    double average_score;
    string group;
public:
    student() {}

    student(string n, string g) : university_person(n) {
        srand(time(NULL) + rand());
        average_score = 2.0 + (double)rand() / RAND_MAX * 3.0; // Средний балл от 2.0 до 5.0
        group = g;
    }

    double get_score() { return average_score; }
    void set_group(string g) { group = g; }
    string get_group() { return group; }

    bool operator==(professor prof);

    void show_class() {
        cout << "University: " << university_name << endl;
        cout << "Name: " << get_name() << endl;
        cout << "AverageScore: " << average_score << endl;
        cout << "Group: " << group << endl;
        cout << endl;
    }
};

bool student::operator==(professor prof) {
    vector<string> professor_groups = prof.get_professor_group();
    for (const auto& professor_group : professor_groups) {
        if (get_group() == professor_group) {
            return true;
        }
    }
    return false;
}

template <typename T> class statistics {
private:
    vector<T> list;
public:
    statistics() {}
    statistics(T person) {
        list.push_back(person);
    }
    void add(T person) {
        list.push_back(person);
    }
    int get_size() { return list.size(); }
    vector<T> get_list() { return list; }
};

void calc_students(statistics<student> students, statistics<professor> professors) {
    map<string, int> students_count;

    // Подсчитываем студентов, обучающихся у преподавателей
    for ( auto& st : students.get_list()) {
        for ( auto& pr : professors.get_list()) {
            if (st == pr) {
                students_count[pr.get_professor_name()] += 1;
            }
        }
    }

    // Выводим количество студентов, обучающихся у преподавателей
    for (const auto& [name, count] : students_count) {
        cout << name << ": " << count << endl;
    }
}

int main() {
    statistics<student> students;
    students.add(student("Kuznetsov", "Group1"));
    students.add(student("Sidorov", "Group2"));
    students.add(student("Kozlov", "Group3"));
    students.add(student("Sokolov", "Group1"));
    students.add(student("Mikhailov", "Group2"));

    statistics<professor> professors;
    professors.add(professor("Ivanov", vector<string>{"Group1", "Group2"}));
    professors.add(professor("Petrov", vector<string>{"Group2", "Group3"}));
    professors.add(professor("Smirnov", vector<string>{"Group1", "Group2", "Group3"}));
    professors.add(professor("Popov", vector<string>{"Group1"}));
    professors.add(professor("Vasilev", vector<string>{"Group1", "Group3"}));

    cout << "Введите вариант задачи:" << endl;
    cout << "   1: Общее количество студентов" << endl;
    cout << "   2: Количество студентов, обучающихся у конкретного преподавателя" << endl;
    cout << "Введите номер от 1 до 2: ";

    int op;
    cin >> op;
    switch (op) {
        case 1:
            cout << "Общее количество студентов: " << students.get_size() << endl;
            break;
        case 2:
            calc_students(students, professors);
            break;
        default:
            cout << "Неверный ввод: \n";
    }

    return 0;
}