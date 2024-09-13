#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <chrono>
using namespace std;

// Пример 1. Аргументы по умолчанию
// Функция для генерации случайного числа в заданном диапазоне
// Аргументы имеют значение по умолчанию
int irand(int a = 0, int b = 100) { return rand() % (b - a) + a; }

// Пример 2. Перегрузка функций
// Функция вычисляет площадь прямоугольника
// Функция перегружена и принимает два аргумента
float area(float a, float b) { return a * b; }

// Функция вычисляет площадь круга
// Функция перегружена и принимает один аргумент
float area(float a) { return 3.14 * a * a; }

// Пример 3. Шаблон функции
// Шаблон функции для обмена двух переменных значениями
template <class T> void myswap(T &x, T &y) {
  T tmp;
  tmp = x;
  x = y;
  y = tmp;
}

// Пример 4. Статические переменные
void greeting() {
  static bool first = true;
  if (first) {
    cout << "Hello!" << endl;
    first = false;
  } else
    cout << "Hello again!" << endl;
}

// Пример 5. Правильное использование рекурсии
// Плохая реализация вычисления чисел Фибоначчи
long long badFib(int n) {
  if (n < 2)
    return 1;
  return badFib(n - 1) + badFib(n - 2);
}

// Хорошая реализация вычисления чисел Фибоначчи
long long goodFib(int n, int k = 1, int m = 1) {
  if (n < 2)
    return m;
  return goodFib(n - 1, m, k + m);
}

// Пример 6. Передача имен функций в качестве параметров
// Две функции для расчета значений
float func2(float x) { return x * x; }
float func3(float x) { return x * x * x; }
// Определение типа указателя на функцию
typedef float (*PF)(float);
// Функция, принимающая в качестве параметра указатель на функцию
// и печатающая таблицу значений функции
void print(PF pf, float a = 0, float b = 5, float h = 1) {
  for (float x = a; x <= b; x += h)
    cout << pf(x) << endl;
}

int main() {
  srand(unsigned(time(0)));
  cout << "-------1--------" << endl;
  cout << "Генерация случайных чисел" << endl;
  cout << irand(-10, 10) << endl; // a=-10 b=10
  cout << irand(40) << endl;      // a = 40 b = 100
  cout << irand() << endl;        // a = 0 b = 100
  cout << "-------2--------" << endl;
  cout << "Вычисление площадей с использованием перегруженных функций" << endl;
  cout << area(10, 15) << endl;
  cout << area(3) << endl;
  cout << "-------3--------" << endl;
  cout << "Шаблоны функций" << endl;
  int a = 0, b = 10;
  float p = 1.5f, q = -3.7f;
  string st = "hello", t = "world";
  cout << a << " " << b << endl;
  myswap(a, b);
  cout << a << " " << b << endl;
  cout << p << " " << q << endl;
  myswap(p, q);
  cout << p << " " << q << endl;
  cout << st << " " << t << endl;
  myswap(st, t);
  cout << st << " " << t << endl;
  cout << "-------4--------" << endl;
  cout << "Статические переменные" << endl;
  greeting();
  greeting();
  greeting();
  cout << "-------5--------" << endl;
  cout << "Плохая и хорошая рекурсия" << endl;
  auto begin = std::chrono::steady_clock::now();
  long long f1 = badFib(40);  
  auto end = std::chrono::steady_clock::now();
  auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
  cout << "The time: " << elapsed_ms.count() << " ms\n";
  cout << f1 << endl;
  begin = std::chrono::steady_clock::now();
  long long f2 = goodFib(40);  
  end = std::chrono::steady_clock::now();
  elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
  cout << "The time: " << elapsed_ms.count() << " ms\n";
  cout << f2 << endl;
  cout << "-------6--------" << endl;
  cout << "Передача имен функций в качестве параметров" << endl;
  print(func2);
  print(func3);
}
 
 

  