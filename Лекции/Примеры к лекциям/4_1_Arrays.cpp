#include <iostream>
using namespace std;

void print_mas(const int n, int *arr);
int summa(const int n, int *arr);
int num_min(const int n, int *arr);
int search(const int n, int *arr, int k, int q = 0);
void sort(const int n, int *arr);
int bin_search(const int n, int *arr, int k);
void quicksort(const int n, int *arr);

int main() {
  //Задача 1. Создание массива, заполнение массива, печать массива.
  const int n = 10;
  int mas[n] = {3, -4, 1, -5, -2, 10, 2, 1, 6};
  cout << "Первый массив" << endl;
  cout << mas << endl;
  print_mas(n, mas);

  //Задача 2. Создание, заполнение с клавиатуры и вывод динамического массива.
  int m;
  cout << "Введите размер второго массива" << endl;
  cin >> m;
  int *mas2 = new int[m];

  cout << "Введите элементы второго массива" << endl;
  for (int i = 0; i < m; i++)
    cin >> mas2[i];

  cout << "Второй массив" << endl;
  print_mas(m, mas2);

  //Задача 3. Вычислить сумму элементов массива.
  //Для подсчета суммы двух массивов одного типа, но разной длины и разного
  //способа задания используется одна и та же функция обработки!
  cout << "Сумма элементов первого массива" << endl;
  cout << summa(n, mas) << endl;
  cout << "Сумма элементов второго массива" << endl;
  cout << summa(m, mas2) << endl;

  //Задача 4. Поиск минимального элемента массива.
  cout << "Номер минимального элемента во втором массиве" << endl;
  cout << num_min(m, mas2) << endl;

  //Задача 5. Линейный поиск (поиск образца)
  int k, p;
  cout << "Введите элемент для линейного поиска во втором массиве" << endl;
  cin >> k;
  p = search(m, mas2, k);
  if (p != -1)
    cout << "Элемент под номером " << p << endl;
  else
    cout << "Элемента нет" << endl;

  //Задача 6. Сортировка выбором
  sort(m, mas2);
  cout << "Отсортированный второй массив" << endl;
  print_mas(m, mas2);

  //Задача 7. Бинарный поиск
  cout << "Введите элемент для бинарного поиска во втором массиве" << endl;
  cin >> k;
  p = bin_search(m, mas2, k);
  if (p != -1)
    cout << "Элемент под номером " << p << endl;
  else
    cout << "Элемента нет" << endl;

  //Задача 8. Быстрая сортировка
  cout << "Отсортированный первый массив" << endl;
  quicksort(n, mas);
  print_mas(n, mas);

  delete[] mas2;
  return 0;
}

//Быстрая сортировка целочисленного массива (рекурсивная версия)
void quicksort(const int n, int *arr) {
  int i = 0, j = n - 1;
  int temp, p;
  p = arr[n >> 1]; //получение опорного элемента. Используется операция
                   //побитового сдвига
  //Выражение n>>1 эквивалентно n/2, однако операция сдвига работает быстрее

  //Разделение массива на две части
  do {
    while (arr[i] < p)
      i++; //ищем первый элемент в левой части, который больше опорного
    while (arr[j] > p)
      j--; //аналогично для правой части и меньше опорного

    //Если нашлось два таких элемента, меняем их местами и сдвигаем границы
    if (i <= j) {
      temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
      i++;
      j--;
    }
  } while (i <= j);

  // Рекурсирвно вызываем сортировку для полученных частей массива
  if (j > 0)
    quicksort(j + 1, arr); //первая половина массива
  if (n > i)
    quicksort(n - i, &arr[i]); //получаем адрес начала второй половины массива
  //и запускаем сортировку для этой половины
}

//Бинарный поиск элемента в целочисленном массиве
int bin_search(const int n, int *arr, int k) {
  int left = 0, right = n, mid;
  while (left <= right) {
    mid = (left + right) / 2;
    if (arr[mid] == k)
      return mid;
    if (arr[mid] > k)
      right = mid - 1;
    if (arr[mid] < k)
      left = mid + 1;
  }
  return -1;
}

//Сортировка выбором целочисленного массива
void sort(const int n, int *arr) {
  for (int i = 0; i < n - 1; i++) {
    int nmin = i;
    for (int j = i + 1; j < n; j++)
      if (arr[j] < arr[nmin])
        nmin = j;
    if (nmin == i)
      continue;
    int buf = arr[i];
    arr[i] = arr[nmin];
    arr[nmin] = buf;
  }
}

//Линейный поиск образца в целочисленном массиве
int search(const int n, int *arr, int k, int q) {
  for (int i = q; i < n; i++)
    if (arr[i] == k)
      return i;
  return -1;
}

//Поиск номера минимального элемента в целочисленном массиве
int num_min(const int n, int *arr) {
  int n_min = 0;
  for (int i = 1; i < n; i++)
    if (arr[i] < arr[n_min])
      n_min = i;
  return n_min;
}

//Вывод целочисленного массива на экран
void print_mas(const int n, int *arr) {
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;
}

//Расчет суммы элементов целочисленного массива
int summa(const int n, int *arr) {
  int s = 0;
  for (int i = 0; i < n; i++)
    s += arr[i];
  return s;
}