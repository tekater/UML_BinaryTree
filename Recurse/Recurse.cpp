#include <iostream>
#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <math.h>
using namespace std;

//void elevator(int floor) {
//    if (floor == 0) {
//        cout << "Вы в подвале!\n";
//        return;
//    }
//    else {
//        cout << "Вы на " << floor << " этаже\n";
//        Sleep(50);
//        if (floor > 0) {
//           return elevator(floor - 1);
//        }
//        else {
//            cout << "Вы оказались ниже :|\n";
//            return;
//        }
//    }
//}

void elevator(int floor) {
    if (floor == 0) {
        cout << "\nВы в подвале!\n\n";
        return;
    }
    else {
        cout << "Вы на " << floor << " этаже\n";
        Sleep(50);
        elevator(floor - 1);
        cout << "Вы на " << floor << " этаже\n";
        Sleep(50);
    }
}

//int Factorial(int n, int i) {
//    if (i == n) {
//        return n;
//    }
//    return i * Factorial(n, i + 1);
//}

int Factorial(int n) {
    if (n == 1) {
        return n;
    }
    return n* Factorial(n - 1);
}

double Power(double a, int n) {
    if (n == 1) {
        return a;
    }
    return a * Power(a, n - 1);
}

int Fibonacci(int n)
{
    if (n < 2) {
        return n;
    }
    return (Fibonacci(n - 1) + Fibonacci(n - 2));
}
        


int main()
{
    setlocale(0, "");
    //cout << "Hello world!";
    int n; int i;
    double d;
    cout << "Введите номер этажа\n";
    cin >> n;

    elevator(n);

    cout << "\nВведите число для Факториала:\n"; cin >> n;
    cout << "Факториал "  <<  n << ": " << Factorial(n) << endl; // Done

    cout << "\nВведите число для Возведения в степень:\n"; cin >> d;
    cout << "Введите Степень:\n"; cin >> i;
    cout << d << " в степени " <<  i  << ": " << Power(d, i) << endl; // Done

    cout << "Фибоначчи: " << Fibonacci(20) << endl; // Done? с void не додумал

}
