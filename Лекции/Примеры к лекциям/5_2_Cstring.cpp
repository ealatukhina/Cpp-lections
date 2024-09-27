#include <iostream>
#include <cstring> //обязательно для работы со строками С
using namespace std;

int main() {
	//Пример 1. Создание строк
	char *a = "Hello"; //константная строка, не может быть изменена
	char b[10];//="Privet";//обычная строка, 9 полезных символов
	
	//Вывод самой строки и ее длины
	cout<<a<<"  "<<strlen(a)<<endl;
	cout<<b<<"  "<<strlen(b)<<endl;
	
	//Ввод строки с клавиатуры до первого разделителя
	//Т.к. а -- это константная строка, ее ввод вызовет ошибку
//	cin>>a;
	cin>>b;

	//Строка b изменилась
	cout<<a<<"  "<<strlen(a)<<endl;
	cout<<b<<"  "<<strlen(b)<<endl;

	cout<<"**********************************************"<<endl;
	
	//Пример 2. Функции для работы со строками
	char str[81];//достаточно большая строка
	strcpy (str,"these "); //копирование строки в другую
	strcat (str,"strings "); //конкатенация (склеивание) строк
	strcat (str,"are ");
	strcat (str,"concatenated. ");
	strcat (str, b);
	cout<<str<<endl;
	
	char *st;//строка-указатель
	st=strstr(str, "are");//поиск подстроки
	cout<<st<<endl;
	
	//Разделение строки на слова
	char *pch;
	pch = strtok (str," ,.-");//второй параметр здесь -- набор символов-разделителей
	//разделители будут проигнорированы, остальные символы останутся
	while (pch != NULL) //пока есть что искать
	{
    	cout<<pch<<endl; 
    	pch = strtok (NULL, " ,.-"); //повторяем поиск разделителей
	}
	
	//Пример 2(а). Работа с getline()
	char str2[81];
	cin.getline(str2,80); // При чтении строки с клавиатуры обязательно указывать ее длину
	cout<<str2;
	return 0;
}