#include <iostream>
#include <string>//Обязательно для работы со строками string
using namespace std;

int main() {
	//Пример 4. Особенности чтения с клавиатуры строк с пробелами
	//Чтение строки при помощи cin оставляет в потоке ввода символ конца строки
	string q;
	cin>>q;
	//Если после чтения строки при помощи cin нам нужно прочитать строку при помощи getline
	//Обязательно использовать cin.ignore();
	//Если getline -- первое чтение строки из потока ввода, то cin.ignore(); писать не нужно!
	string name;
	cout << "Please, enter your full name: ";
	cin.ignore();
	getline(cin, name);
	cout << "Hello, " << name << "!\n";
	return 0;
}