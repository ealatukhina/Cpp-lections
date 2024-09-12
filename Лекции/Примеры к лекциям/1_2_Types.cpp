#include <iostream>//подключение ввода-вывода
using namespace std;//подключение стандартного пространства имен

int main() {
  //endl -- вывод энтера
	cout << "Hello, \nworld!" << endl; 
	int a, b=1;
	cin >> a >> b;
	cout << a + b << endl;
  //(float) -- приведение к типу float
	float c = (float)a/b; 
	cout << c << endl;
	cout << 5./9 << endl; 
	return 0;
}