#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <cmath>
#include <map>
#include <vector>

using namespace std;

// Обьявляем класс точки
class point {
    private:
        // Обьявляем координаты х и у, а так же пустую переменную для определения угла радиус-вектор
        double x;
        double y;
        double angle;
    public:
        string name;
        point() {}
        point(double a, double b) {
            x = a;
            y = b;
        }
        ~point() {}
        double get_x() { return x; }
        double get_y() { return y; }
        double get_angle() { return angle; }
        void show_position() { cout << x << "," << y ; }
        void set_angle(double a) { angle = a; }
        friend void calc_square(point rectangle[4]);
};

class university_person {
    private:
        string full_name;
        string job_title;
        vector<string> groups;
    public:
        university_person() {}
        university_person(string n, string j, vector<string> g) {
            full_name = n;
            job_title = j;
            groups = g;
        }
        string get_name() { return full_name; }
        string get_job() { return job_title; }
        vector<string> get_groups() { return groups; }
};

// Функция расчета растояния между двумя точками
double calc_distance(point p1, point p2){
    return sqrt(pow((p1.get_y() - p2.get_y()),2) + pow((p1.get_x() - p2.get_x()),2));
}

// Отображение координат вершин четырехугольника
void show_coordinates(point rectangle[4]) {
    for(int i = 0; i < 4; i++) {
        cout << "Точка " << rectangle[i].name << ": X:" << rectangle[i].get_x() << " Y:" << rectangle[i].get_y() << endl;
    }
}

// Функция подсчета правильного четырехугольника, за счет вычисления центра масс и сортировки точек по радиус-вектору
void prepare_rectangle(point rectangle[4]) {
    // Вычисляем координаты центра масс
    double sum_x = {};
    double sum_y = {};
    for(int i = 0; i < 4; i++) {
        sum_x += rectangle[i].get_x();
        sum_y += rectangle[i].get_y();
    }
    point сenter = point(sum_x/4,sum_y/4);

    // Подсчитываем угол который образует радиус-вектор
    for(int i = 0; i < 4; i++) {
        rectangle[i].set_angle(atan2(rectangle[i].get_y() - сenter.get_y(), rectangle[i].get_x() - сenter.get_x()));
    }

    // Сортируем точки по возрастанию угла радиус-вектор
    for(int i = 1; i < 4; i++) {
        int j = i - 1;
        while(j >= 0 && rectangle[j].get_angle() > rectangle[j + 1].get_angle()) {
            swap(rectangle[j], rectangle[j + 1]);
            j--;
        }
    }

    // Задаем имена для точек
    string point_names[4] = {"A", "B", "C", "D"};
    for(int i = 0; i < 4; i++) {
        rectangle[i].name = point_names[i];
    }
}

// Функция подсчета длин сторон четырехугольника
void calc_sides(point rectangle[4]) {
    for(int i = 0; i < 4; i++) {
        int j = i+1;
        if ( j == 4 ) { j = 0; }
        cout << "Длина стороны " << rectangle[i].name << rectangle[j].name << ": " << calc_distance(rectangle[i], rectangle[j]) << endl;
    }
}

// Функция подсчета длины диагоналей четырехугольника
void calc_diagonals(point rectangle[4]) {
    cout << "Диагональ " << rectangle[0].name << rectangle[2].name << ": " << calc_distance(rectangle[0], rectangle[2]) << endl;
    cout << "Диагональ " << rectangle[1].name << rectangle[3].name << ": " << calc_distance(rectangle[1], rectangle[3]) << endl;
}

// Функция расчета длин сторон четырехугольника и его диагоналей
void calc_rectangle(point rectangle[4]) {
    show_coordinates(rectangle);
    calc_sides(rectangle);
    calc_diagonals(rectangle);
}

// Функция расчета площади четырехугольника
void calc_square(point rectangle[4]) {
    show_coordinates(rectangle);
    double square = abs((rectangle[0].x - rectangle[1].x)*(rectangle[0].y + rectangle[1].y) + (rectangle[1].x - rectangle[2].x)*(rectangle[1].y + rectangle[2].y) + (rectangle[2].x - rectangle[3].x)*(rectangle[2].y + rectangle[3].y) + (rectangle[3].x - rectangle[0].x)*(rectangle[3].y + rectangle[0].y))/2;
    cout << "Площадь: " << square << endl;
}

// Функция расчета количества студентов обущающихся у конкретных преподавателей
void calc_students(university_person university[6], size_t size) {
    map <string, vector<string>> students;
    map <string, vector<string>> professors;
    map <string, int> students_count;
    // Заполняем карты стундентов и преподователей
    for (int i=0; i<size; i++) {
        string job = university[i].get_job();
        if ( job == "student") {
            students[university[i].get_name()] = university[i].get_groups();
        } else if ( job == "professor") {
            professors[university[i].get_name()] = university[i].get_groups();
        }
    }
    // Подсчитываем студентов обучабщихся у преподователей
    for (const auto& [student_name, student_group] : students) {
        for (const auto& [professor_name, professor_groups] : professors) {
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
    point* rectangle = new point[4];
    rectangle[0] = { point(-4,-2) };
    rectangle[1] = { point(1,4) };
    rectangle[2] = { point(-1,0) };
    rectangle[3] = { point(3,4) };
    prepare_rectangle(rectangle);

    university_person university[6] = {
        university_person("Ivanov", "professor", vector<string>{ "Group1", "Group2" }),
        university_person("Petrov", "professor", vector<string>{ "Group2", "Group3" }),
        university_person("Kuznetsov", "student", vector<string>{ "Group1" }),
        university_person("Sidorov", "student", vector<string>{ "Group2" }),
        university_person("Kozlov", "student", vector<string>{ "Group3" }),
        university_person("Sokolov", "student", vector<string>{ "Group1" })
    };
    size_t university_size = sizeof(university) / sizeof(university[0]);

    cout << "Введите вариант задачи:" << endl;
    cout << "   1: Вычисление длины сторон и гипотенузы" << endl;
    cout << "   2: Вычисление площади прямоугольника" << endl;
    cout << "   3: Индивидуальное задание" << endl;
    cout << "Введите номер от 1 до 3: ";

    int op;
    cin >> op;
    switch (op) {
        case 1:
            calc_rectangle(rectangle);
            break;
        case 2:
            calc_square(rectangle);
            break;
        case 3:
            calc_students(university, university_size);
            break;
        default: cout << "Неверный ввод: \n";
    }

    return 0;
}

