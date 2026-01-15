#ifdef _WIN64
#include <windows.h>
#endif
#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <cmath>
#include <cstdlib>
#include <string>
#include "6laura.h"
#include <algorithm>



int main() {
    #ifdef _WIN64
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    #endif
    using namespace std;
    int choice;
    do {
        cout << "1. ExamTaskC3 " << endl;
        cout << "2. Задание 1" << endl;
        cout << "3. Задание 2" << endl;
        cout << "999. Выход из программы" << endl;
        
        cin >> choice;
        switch (choice) {
            case 1: {
                ExamTaskC3();
                break;
            }
            case 2: {
                task1(); 
                break;
            }
            case 3: {
                taskPoints2D();
                break;
            }
            case 999: {
                cout << "Выход из программы" << endl;
                break;
            }
            default:
            cout << "Введены неверные данные" << endl;
            break;         
        }
    } 
    while (choice != 999);
    return 0;
}