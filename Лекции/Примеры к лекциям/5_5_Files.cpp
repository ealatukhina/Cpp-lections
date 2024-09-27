// Внимание! Этот код не выполняеся онлайн, т.к. содержит работу с файлами!
#include <fstream> // Для работы с файлами
#include <iostream>
#include <string>

using namespace std;

int main() {
  ifstream fin("input.txt");   // Открытие файла на чтение
  ofstream fout("output.txt"); // Открытие файла на запись
  int a, b;
  string st;
  fin >> a >> b >>
      st; // Чтение из файла не отличается от чтения из стандартного потока
  cout << a + b << endl;
  cout << st << endl;
  fout << a - b << endl; // Вывод в файл тоже не отличается
  fout << st << ", world!" << endl;

  string line;
  // В следующем цикле мы читаем строчки файла, пока не достигнем его конца, и
  // выводим их на экран и в другой файл.
  while (!fin.eof()) {
    fin >> line;
    cout << line << endl;
    fout << line << endl;
  }
  // После завершения работы с файлами обязательно их закрываем
  fin.close();
  fout.close();
  return 0;
}