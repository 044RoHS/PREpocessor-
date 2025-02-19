#include <iostream>
#define MODE 1

using namespace std;


#ifndef MODE
#error "Константа MODE не определена! Определите MODE как 0 или 1."
#endif


#ifdef MODE
#if MODE == 1
int add(int a, int b) {
    return a + b;
}
#endif
#endif

int main() {
    setlocale(LC_ALL, "RU");

    
#ifdef MODE
#if MODE == 1
    cout << "Работаю в боевом режиме" << endl;

    int a, b;
    cout << "Введите число 1: ";
    cin >> a;
    cout << "Введите число 2: ";
    cin >> b;

   
    cout << "Результат сложения: " << add(a, b) << endl;
#elif MODE == 0
    cout << "Работаю в режиме тренировки" << endl;
#else
    cout << "Неизвестный режим. Завершение работы" << endl;
#endif
#endif

    return 0;
}