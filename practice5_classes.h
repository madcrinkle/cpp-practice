#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

class university_person {
    private:
        string full_name;
    public:
        university_person() {}
        university_person(string n) {
            full_name = n;
        }
        void set_name(string name) { full_name = name; }
        string get_name() { return full_name; }
};

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
        void set_groups(string g) { group = g; }
        string get_group() { return group; }
};

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
};
