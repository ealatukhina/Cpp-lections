#include <iostream>
#include <string>//Обязательно для работы со строками string

using namespace std;

int main() {
	//Пример 3. Функции для работы со строками string
	string str;
	cin>>str;
	cout<<str<<endl;
	
	string str_dec = "2001, A Space Odyssey";
	int i_dec = stoi (str_dec,nullptr);//извлечение числа из строки
	cout<<i_dec<<endl;
	
	cout<<str.length()<<endl;//вывод длины строки
	
	//Функция для поиска find возвращает положение первого вхождения
	string st("very very long string");
	int k=st.find("long");
	cout<<k<<endl;
	//Если подстроки в строке нет, find возвращает -1
	int p=st.find("hello");
	cout<<p<<endl;

	return 0;
}