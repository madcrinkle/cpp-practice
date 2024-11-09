#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

// Обьявляем пространство имен
namespace University {

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
    class student;
    class professor: private university_person {
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
            // bool operator==(student stud);
    };
    // bool professor::operator==(student stud) {
    //     vector<string> student_groups = stud.get_groups();
    //     for (const auto& professor_group : get_professor_group()) {
    //         if ( student_groups[0] == professor_group ) {
    //             return true;
    //         }
    //     }
    //     return false;
    // }

    class student: public university_person {
        private:
            double average_score;
            string group;
        public:
            student() {}
            student(string n, string g): university_person(n) {
                srand(time(NULL)+rand());
                average_score = 2.0+(double)rand()/RAND_MAX * 3.0;
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
            if ( get_group() == professor_group ) {
                return true;
            }
        }
        return false;
    }
}
