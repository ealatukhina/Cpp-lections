#include <iostream>
#include <map>
using namespace std;

int main() {
	map <char, int> m;//словарь из пар символ-число	
	m.insert ( pair<char,int>('z',200) );//добавление нескольких элементов
	m.insert ( pair<char,int>('a',100) );//элементы добавляются в порядке сортировки ключа
	m.insert ( pair<char,int>('k',0) );//т.е. для символов по номеру кода символа
	
	
	map<char,int>::iterator it = m.begin();//создаем прямой итератор
	//итератор пробегает все элементы контейнера, пока не дойдет до конца
	//т.к. элементами являются значения типа "пара", то можно использовать
	//first (здесь хранится ключ) и second (значение)
	//в других случаях можно просто напечатать *it (см. в справке)
	for (it=m.begin(); it!=m.end(); ++it)
    	cout << it->first << " => " << it->second << '\n';	
 
	//считаем, сколько раз в строке появляется каждый символ
	string st="very very long test string привет мир";
  map <char, int> M;	
  for (int i=0; i<st.length(); i++)//проходим всю строчку
    M[ st[i] ]++;//увеличиваем на единицу значение в словаре, где ключ -- текущий символ строки

 	for (it=M.begin(); it!=M.end(); ++it)
    cout << it->first << " => " << it->second << '\n';   	
  cout << "-----------------" << endl;
  cout << M['a'] << endl;  
  cout << M.at('a') << endl;
	return 0;
}