#include "6laura.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>

void ExamTaskC3() {
    using namespace std;
    int n;
    cout << "Введите кол-во клиенов (n): " << endl;
    cin >> n;
    if (n <= 0) {
        cout << "Неверные данные" << endl;
        return;
    }
    client mini = {100500, 100500, 100500, 100500};
    for (int i = 0; i < n; i++) {
        cout << "Клиент " << i + 1 << endl;
        client c;
        cout << "Введите продолжительность занятий (в часах, от 1 до 30): " << endl;
        cin >> c.hours;
        if (c.hours < 1 || c.hours > 30) {
            cout << "Вы ввели неверные данные " << endl;
            return;
        }
        cout << "Введите код клиента (от 10 до 99): " << endl;
        cin >> c.codeclient;
        if (c.codeclient < 10 || c.codeclient > 99) {
            cout << "Вы ввели неверные данные " << endl;
            return;
        }
        cout << "Введите год (с 2000 до 2010): " << endl;
        cin >> c.year;
        if (c.year < 2000 || c.year > 2010) {
            cout << "Вы ввели неверные данные " << endl;
            return;
        }
        cout << "Введите номер месяца (1 - 12): " << endl;
        cin >> c.month;
        if (c.month < 1 || c.month > 12) {
            cout << "Вы ввели неверные данные " << endl;
            return;
        }
        // if (c.year < 2000 || c.year > 2010 || c.codeclient < 10 || c.codeclient > 99 || c.hours < 1 || c.hours > 30 || c.month < 1 || c.month > 12) {
        //     cout << "Вы ввели неверные данные " << endl;
        //     return;
        // }
        if (c.hours < mini.hours) {
            mini = c;
        }
        else if (c.hours == mini.hours) {
            if ((c.year == mini.year) && (c.month < mini.month )) {
                mini = c;
            }
        }
    }
    cout << "Cтрока исходных данных с минимальной продолжительностью занятий: " << endl;
    cout << mini.hours << " (часы) " <<mini.year << " (год) " << mini.month << " (мес) " << endl;
}

//--------------------------------------------

void task1() {
    using namespace std;
    ofstream c("c.txt");
    c << "| " << left << setw(12) << "Цвет" << "| " << setw(12) << "Тип" << "| " << setw(12) << "Параметр" << "|\n";
    c << string(43, '-') << endl;
    c.close();

    int n;
    cout << "Введите n - кол-во фигур: " << endl;
    cin >> n;
    if (n <= 0) {
        cout << "Неверные данные" << endl;
        return;
    }
    figura f;
    for (int i = 0; i < n; i++) {
    cout << "Фигура " << i + 1 << endl;
    if (!vvodfiguri()) {
        cout << "Программа завершена из-за ошибки ввода" << endl;
        cout << endl;
        return;
    }
    cout << endl;
    }
    ifstream file("c.txt");;  
    string line;
    while (getline(file, line)) {
        cout << line << endl;
    } 
    cout << endl;
    file.close();
}

bool vvodfiguri() {
    using namespace std;
    ofstream file("c.txt", ios::app);

    figura f;
    cout << "Введите цвет фигуры: ";
    cin >> f.color;

    cout << "Введите тип фигуры (1 - круг, 2 - квадрат, 3 - отрезок): ";
    cin >> f.type;

    if (f.type < 1 || f.type > 3) {
        cout << "\nОшибка: неверный тип фигуры" << endl;
        return false;
    }

    aboutfigure t;
    file << "| " << left << setw(12) << f.color;

    switch (f.type) {
        case 1: {
            cout << "Введите радиус круга: ";
            cin >> t.radius;
            if (t.radius <= 0) {
                cout << "Ошибка: радиус должен быть положительным" << endl;
                return false;
            }
            file << "| " << left << setw(12) << "Круг"
                 << "| " << left << setw(12) << t.radius << "|\n";
            file << string(43, '-') << endl;
            break;
        }
        case 2: {
            cout << "Введите сторону квадрата: ";
            cin >> t.storona;
            if (t.storona <= 0) {
                cout << "Ошибка: сторона должна быть положительной" << endl;
                return false;
            }
            file << "| " << left << setw(12) << "Квадрат"
                 << "| " << left << setw(12) << t.storona << "|\n";
            file << string(43, '-') << endl;
            break;
        }
        case 3: {
            cout << "Введите длину отрезка: ";
            cin >> t.otrezok;
            if (t.otrezok <= 0) {
                cout << "Ошибка: длина должна быть положительной" << endl;
                return false;
            }
            file << "| " << left << setw(12) << "Отрезок"
                 << "| " << left << setw(12) << t.otrezok << "|\n";
            file << string(43, '-') << endl;
            break;
        }
    }

    file.close();
    return true;
}

//---------------------------------------------------------

void printPoint(const point& p) {
    std::cout << "Точка: (" << p.x << ", " << p.y << ")\n";
}

double distance(const point& a, const point& b) {
    return std::sqrt((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y));
}

void movePoint(point& p, double dx, double dy) {
    p.x += dx;
    p.y += dy;
}

double square(const std::vector<point>& pts) {
    double sum = 0;
    int n = pts.size();
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        sum += pts[i].x * pts[j].y - pts[j].x * pts[i].y;
    }
    return std::abs(sum) / 2.0;
}


void inputPoints(std::vector<point>& pts) {
    using namespace std;
    int n;
    cout << "Введите количество точек: ";
    cin >> n;
    if (n < 1) {
        cout << "Неверное количество точек\n";
        return;
    }
    pts.resize(n);
    for (int i = 0; i < n; i++) {
        cout << "Точка " << i + 1 << " (x y): ";
        cin >> pts[i].x >> pts[i].y;
    }
}

void taskPoints2D() {
    using namespace std;
    vector<point> points;
    int choice;
    do {
        cout << "Задача номер 3 (структура Point)"<< endl;
        cout << "1. Ввести точки\n";
        cout << "2. Расстояние между двумя точками\n";
        cout << "3. Вывод координат точки\n";
        cout << "4. Переместить точку\n";
        cout << "5. Площадь многоугольника\n";
        cout << "0. Выход из программы\n";
        cin >> choice;
        switch (choice) {
        case 1: {
            inputPoints(points);
            break;
        }
        case 2: {
            if (points.size() < 2) {
                cout << "Введите минимум 2 точки\n";
                break;
            }

            int i, j;
            cout << "Введите номера двух точек (1 - " << points.size() << "): ";
            cin >> i >> j;

            if (i < 1 || j < 1 || i > points.size() || j > points.size()) {
                cout << "Неверный ввод точек\n";
                break;
            }
            double d = distance(points[i - 1], points[j - 1]);
            cout << "Расстояние между ними = " << d << "\n";
            break;
        }
        case 3: {
            if (points.empty()) {
                cout << "Точки не введены\n";
                break;
            }

            int i;
            cout << "Введите номер точки (1 - " << points.size() << "): ";
            cin >> i;

            if (i < 1 || i > points.size()) {
                cout << "Неверный номер точки\n";
                break;
            }
            printPoint(points[i - 1]);
            break;
        }
        case 4: {
            if (points.empty()) {
                cout << "Точки не введены\n";
                break;
            }
            int i;
            double dx, dy;
            cout << "Введите номер точки (1 - " << points.size() << "): ";
            cin >> i;
            if (i < 1 || i > points.size()) {
                cout << "Неверный номер точки\n";
                break;
            }
            cout << "Введите смещение x и y: ";
            cin >> dx >> dy;
            cout << "Точка до:  ";
            printPoint(points[i - 1]);
            movePoint(points[i - 1], dx, dy);
            cout << "Точка после: ";
            printPoint(points[i - 1]);
            break;
        }
        case 5: {
            if (points.size() < 3) {
                cout << "Для многоугольника нужно минимум 3 точки\n";
                break;
            }
            cout << "Площадь многоугольника = " << square(points) << "\n";
            break;
        }
        case 0: {
            cout << "Выход из программы задачи\n";
            break;
        }
        default: {
            cout << "Неверный ввод\n";
        }
        }

    } while (choice != 0);
}

