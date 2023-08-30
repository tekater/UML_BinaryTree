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


int main()
{
    setlocale(0, "");
    //cout << "Hello world!";
    int n;
    cout << "Введите номер этажа\n";
    cin >> n;

    elevator(n);


}
