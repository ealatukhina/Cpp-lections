#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b;
	// Начало контролируемого блока кода
	try{
		if (b == 0) throw 0; // бросок исключения
    if (b < 0) throw 1;
		c = a/sqrt(b);
		cout << "a/b=" << c <<endl;
	} // try -- рекомендуется добавлять для больших блоков, чтобы не запутаться
	// Начало обработки исключения
	catch(int err){ // err хранит номер ошибки
		// switch удобно использовать, когда обрабатывается много ошибок
		switch (err){ 
			case 0: cout<<"Division by zero!"<<endl; break;
      case 1: cout<<"Negative number!"<<endl; break;
		}
	}
	return 0;
}