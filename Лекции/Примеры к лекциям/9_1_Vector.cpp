#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector <int> v; //создание вектора из целых чисел
	v.push_back(1); //добавление элемента в конец
	v.push_back(2);
	v.push_back(5);
	v.push_back(2);
	v.push_back(5);
	//вывод вектора
	for (int i=0;i<v.size();i++)
		cout<<v[i]<<" ";
	cout<<endl;
	v.pop_back();//извлечение элемента
	v.pop_back();
	cout<<v.size()<<endl;//после извлечения элементов размер вектора меняется
	cout<<v.capacity()<<endl;//а количество занимаемой памяти -- нет
	v.shrink_to_fit();//подрезка вектора
	cout<<v.size()<<endl;//размер остается прежним, т.е. элементы не исчезают
	cout<<v.capacity()<<endl;//а вот количество памяти уменьшается
	return 0;
}