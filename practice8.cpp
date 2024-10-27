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
        string job_title;
        vector<string> groups;
    public:
        static string university_name;
        university_person() {}
        university_person(string n, vector<string> g) {
            full_name = n;
            groups = g;
        }
        void set_name(string name) { full_name = name; }
        string get_name() { return full_name; }
        void set_job(string job) { job_title = job; }
        string get_job() { return job_title; }
        void set_groups(vector<string> g) { groups = g; }
        vector<string> get_groups() { return groups; }
        virtual void show_class() {
            cout << "University: " << university_name << endl;
            cout << "Name: " << full_name << endl;
            cout << "Job: " << job_title << endl;
            cout << "Groups:" << endl;
            for (const auto& group : groups) {
                cout << "  " << group << endl;
            }
        }
};

class professor: private university_person {
    private:
    public:
        professor() {}
        professor(string n, vector<string> g) {
            set_name(n);
            set_job("professor");
            set_groups(g);
        }
        string get_professor_name() { return get_name(); }
        vector<string> get_professor_group() { return get_groups(); }
};

class student: public university_person {
    private:
        double average_score;
    public:
        student() {}
        student(string n, vector<string> g): university_person(n, g) {
            set_job("student");
            srand(time(NULL)+rand());
            average_score = 2.0+(double)rand()/RAND_MAX * 3.0;
        }
        double get_score() { return average_score; }
        bool operator==(professor prof);
        void show_class() {
            cout << "University: " << university_name << endl;
            cout << "Name: " << get_name() << endl;
            cout << "Job: " << get_job() << endl;
            cout << "AverageScore: " << average_score << endl;
            cout << "Groups:" << endl;
            for (const auto& group : get_groups()) {
                cout << "  " << group << endl;
            }
            cout << endl;
        }
};
bool student::operator==(professor prof) {
    vector<string> professor_groups = prof.get_professor_group();
    for (const auto& professor_group : professor_groups) {
        if ( get_groups()[0] == professor_group ) {
            return true;
        }
    }
    return false;
}

string university_person::university_name = "SUT";

void calc_students(vector<student> &students, vector<professor> &professors) {
    map <string, int> students_count;
    // Подсчитываем студентов обучающихся у преподавателей
    for (int i=0; i<students.size(); i++) {
        for (int j=0; j<professors.size(); j++) {
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
void calc_students(vector<professor> &professors, vector<student> &students) {
    calc_students(students, professors);
}

template <class X> X reverse(X &vector){
    X reversed;
    for(int i=vector.size()-1; i>=0; i--) {
        reversed.push_back(vector[i]);
    }
    return reversed;
}

int main() {
    vector<professor> professors = {
        professor("Ivanov", vector<string>{ "Group1", "Group2" }),
        professor("Petrov", vector<string>{ "Group2", "Group3" }),
        professor("Smirnov", vector<string>{ "Group1", "Group2", "Group3" }),
        professor("Popov", vector<string>{ "Group1" }),
        professor("Vasilev", vector<string>{ "Group1", "Group3" })
    };

    // Заполнение студентов
    vector<student> students;
    vector<student> students_changed;
    string all_groups[3] = {"Group1", "Group2", "Group3"};
    for(int i=0; i<1000; i++) {
        students.push_back(student("Student"+ to_string(i), vector<string>{ all_groups[rand() % 3] } ));
    }

    cout << "Введите вариант задачи:" << endl;
    cout << "   1: Развернуть вектор студентов" << endl;
    cout << "   2: Добавить еще 500 студентов" << endl;
    cout << "Введите номер от 1 до 2: ";

    int op;
    cin >> op;
    switch (op) {
        case 1:
            students_changed = reverse(students);
            cout << "Students Reversed:" << endl;
            for(int i=0; i<students_changed.size(); i++) {
                cout << students_changed[i].get_name() << ":" << students_changed[i].get_groups()[0] << endl;
            }
            calc_students(professors, students);
            break;
        case 2:
            for(int i=1000; i<1500; i++) {
                students_changed.push_back(student("Student"+ to_string(i), vector<string>{ all_groups[rand() % 3] } ));
            }
            students.insert(students.cbegin()+students.size()/2, students_changed.begin(), students_changed.end());
            for(int i=0; i<students.size(); i++) {
                cout << students[i].get_name() << ":" << students[i].get_groups()[0] << " ";
            }
            cout << endl;
            calc_students(professors, students);
            break;
        default: cout << "Неверный ввод: \n";
    }

    return 0;
}

