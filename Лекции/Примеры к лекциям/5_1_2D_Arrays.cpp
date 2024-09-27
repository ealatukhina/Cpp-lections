#include <iostream>
using namespace std;
void print_mas(const int n, const int m, int **arr);
int summa(const int n, const int m, int **arr);

int main() {
  int n, m;
  cout << "Введите количество строк и столбцов массива" << endl;
  cin >> n >> m;
  //Выделение памяти для создания динамического двумерного массива
  int **a = new int *[n];
  for (int i = 0; i < n; i++)
    a[i] = new int[m];

  //Задача 1. Заполнение массива с клавиатуры
  cout << "Введите элементы массива" << endl;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> a[i][j];

  //Задача 2. Вывод массива
  cout << "Вывод массива" << endl;
  print_mas(n, m, a);

  //Задача 3. Вычисление суммы элементов массива
  cout << "Сумма элементов массива" << endl;
  cout << "summa=" << summa(n, m, a) << endl;

  //Очистка памяти для двумерного динамического массива
  for (int i = 0; i < n; i++)
    delete[] a[i];
  delete[] a;
  return 0;
}

//Вычисление суммы всех элементов массива
int summa(const int n, const int m, int **arr) {
  int S = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      S += arr[i][j];
  return S;
}

//Вывод массива на экран
void print_mas(const int n, const int m, int **arr) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++)
      cout << arr[i][j] << " ";
    cout << endl;
  }
}
