#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

// Обьявляем пространство имен
namespace University {

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
            // bool operator==(student stud);
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

    // Почему не работает обратное переопределение?
    // In file included from practice6.cpp:7:
    // practice6_classes.h:36:25: ошибка: «student» не был декларирован
    //    36 |         bool operator==(student stud);
    //       |                         ^~~~~~~
    // practice6_classes.h:63:6: ошибка: no declaration matches «bool professor::operator==(student)»
    //    63 | bool professor::operator==(student stud) {
    //       |      ^~~~~~~~~
    // practice6_classes.h:36:14: замечание: кандидат «bool professor::operator==(int)»
    //    36 |         bool operator==(student stud);
    //       |              ^~~~~~~~
    // practice6_classes.h:25:7: замечание: «class professor» defined here
    //    25 | class professor: private university_person {
    //       |       ^~~~~~~~~
    //
    // bool professor::operator==(student stud) {
    //     vector<string> student_groups = stud.get_groups();
    //     for (const auto& professor_group : get_professor_group()) {
    //         if ( student_groups[0] == professor_group ) {
    //             return true;
    //         }
    //     }
    //     return false;
    // }
}