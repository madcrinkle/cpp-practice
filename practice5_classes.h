#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

class university_person {
    private:
        string full_name;
        string job_title;
        vector<string> groups;
    public:
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
