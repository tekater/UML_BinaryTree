#include <iostream>
using namespace std;

void hello() {
	cout << "Hello" << endl;
}

int sum(int a, int b) {
	return a + b;
}

void main()
{
	setlocale(0, "");

	//hello();

	cout << sum(2, 3) << endl;
	cout << sum << endl; // Указатели на функцию
	
	void (*p_hello)() = hello; // void* - void pointer (указатель на 'void',
						   // может хранить адрес абсолютно любого типа)
	// при разыменовании void-pointer'a нужно обязательно преобразовывать его в целевой тип
	
	p_hello();
	int (*p_sum)(int, int) = sum;
	cout << p_sum(2, 3) << endl;

}
