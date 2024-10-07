#include <cstdlib>
#include <iostream>
#include <sstream>

#define EPS 0.000000001

using namespace std;

class my_complex {
  // Поля делаем скрытыми
  double Re, Im;

public:
  // Конструкторы
  my_complex() {
    Re = 0;
    Im = 0;
  } // по умолчанию
  my_complex(double a, double b = 0) {
    Re = a;
    Im = b;
  }                          // преобразования
  my_complex(my_complex &X); // копирования
  // Деструктор
  ~my_complex() {}

  // Сеттеры и геттеры
  void setRe(double x) { Re = x; }
  void setIm(double x) { Im = x; }
  double getRe() { return Re; }
  double getIm() { return Im; }

  // Дружественные функции
  friend void print_complex(my_complex A);
  friend my_complex operator+(my_complex A, my_complex B);
  friend bool operator==(const my_complex A, const my_complex B);
  friend ostream &operator<<(std::ostream &out, my_complex &X);

  // Перегрузка операций как членов класса
  my_complex &operator=(const my_complex &A) {
    if (&A == this)
      return *this;
    this->Re = A.Re;
    this->Im = A.Im;
    return *this;
  }

  // Функция преобразования в строку (см. лекцию по STL)
  string toString() {
    ostringstream ss; //выходной строковый поток
    if (abs(Im) < 0.0000001) {
      ss << Re;
      return ss.str();
    }
    if (Im > 0)
      ss << Re << "+" << Im << "i";
    else
      ss << Re << Im << "i";
    return ss.str();
  }
};
// Перегрузка оператора вывода в поток (см. лекцию по STL)
ostream &operator<<(std::ostream &out, my_complex &X) {
  out << X.toString();
  return out;
}

// Определение конструктора копирования (будет дополнен позже)
my_complex::my_complex(my_complex &X) {
  Re = X.Re;
  Im = X.Im;
}

// Перегрузка оператора проверки на равенство
bool operator==(const my_complex A, const my_complex B) {
  if (abs(A.Re - B.Re) < EPS && abs(A.Im - B.Im) < EPS)
    return true;
  return false;
}

// Перегрузка оператора сложения
my_complex operator+(my_complex A, my_complex B) {
  my_complex C;
  C.Re = A.Re + B.Re;
  C.Im = A.Im + B.Im;
  return C;
}

// Вывод комплексного числа на экран (после перегрузки операции вывода можно не
// использовать)
void print_complex(my_complex A) {
  cout << A.Re;
  if (A.Im < 0)
    cout << A.Im << "i" << endl;
  else
    cout << "+" << A.Im << "i" << endl;
}

int main() {
  // Объявляем объекты для хранения комплексных чисел:
  // А -- значение по умолчанию
  // В -- инициализируем переданными значениями
  // С -- инициализируем переданным значением, используя параметр по умолчанию
  // D -- создается копированием В
  my_complex A, B(4, -3), C(5), D(B);
  print_complex(A);
  // Меняем значения А
  A.setRe(2);
  A.setIm(3);
  // Выводим все числа
  cout << A << endl; // Замена вывода с помощью функции на более привычный
  // print_complex(A);
  print_complex(B);
  print_complex(C);
  print_complex(D);
  // Демонстрация работы оператора сложения
  my_complex P;
  P = B + C;
  print_complex(P);
  // Демонстрация работы оператора проверки на равенство
  if (C == D)
    cout << "Yes";
  else
    cout << "No";
  return 0;
}