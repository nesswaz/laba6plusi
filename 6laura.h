#ifndef H_H
#define H_H

#include <vector>
#include <string>

struct client {
    int hours;
    int codeclient;
    int year;
    int month;
};

void ExamTaskC3();

struct figura {
    std::string color;
    int type;
    
};

union aboutfigure{
    short int radius;
    int storona;
    float otrezok;
};

bool vvodfiguri();
void task1();

struct point {
    double x;
    double y;
};


void taskPoints2D();
void inputPoints(std::vector<point>& pts);
double square(const std::vector<point>& pts);
void movePoint(point& p, double dx, double dy);
double distance(const point& a, const point& b);
void printPoint(const point& p);


#endif