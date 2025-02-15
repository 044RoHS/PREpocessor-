#define MODE 1 
#include <iostream>
using namespace std;

int add(int a ,int b ) 
{
	return a + b;
}
int main()
{
	setlocale(LC_ALL,"RU");
#ifdef MODE	
	#if MODE == 1
	cout << "Работаю в боевом режиме" << endl;
	int a;
	int b;
	cout << "Введите число 1: ";
	cin >> a;
	cout << "Введите число 2: ";
	cin >> b;
	cout << "Результат сложения: " << add(a, b) << endl;
	#elif MODE  == 0  
	cout << "Работаю в режиме тренировки" << endl;
	#else
	cout << "Неизвестный режим. Завершение работы" << endl;
	#endif 
#endif
#ifndef MODE	
	cout << "Can you define MODE ?" << endl;
#endif 

}
