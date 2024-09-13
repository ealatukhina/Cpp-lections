#include <iostream>
#include <stdlib.h>

using namespace std;

// Объединяем два отсортированных подмассива `arr[low…mid]` и `arr[mid+1…high]`
void Merge(int arr[], int aux[], int low, int mid, int high)
{
    int k = low, i = low, j = mid + 1;
 
    // Пока есть элементы в левом и правом прогонах
    while (i <= mid && j <= high)
    {
        if (arr[i] <= arr[j]) {
            aux[k++] = arr[i++];
        }
        else {
            aux[k++] = arr[j++];
        }
    }
 
    // Копируем оставшиеся элементы
    while (i <= mid) {
        aux[k++] = arr[i++];
    }
 
    // Вторую половину копировать не нужно (поскольку остальные элементы
    // уже находятся на своем правильном месте во вспомогательном массиве)
 
    // копируем обратно в исходный массив, чтобы отразить порядок сортировки
    for (int i = low; i <= high; i++) {
        arr[i] = aux[i];
    }
}
 
// Сортируем массив `arr[low…high]`, используя вспомогательный массив `aux`
void mergesort(int arr[], int aux[], int low, int high)
{
    // Базовый вариант
    if (high == low) {        // если размер прогона == 1
        return;
    } 
    // найти середину
    int mid = (low + ((high - low) >> 1));
 
    // рекурсивное разделение выполняется на две половины до тех пор, пока размер выполнения не станет == 1,
    // затем объединяем их и возвращаемся вверх по цепочке вызовов
 
    mergesort(arr, aux, low, mid);          // разделить/объединить левую половину
    mergesort(arr, aux, mid + 1, high);     // разделить/объединить правую половину
 
    Merge(arr, aux, low, mid, high);        // объединить два полупрогона.
}
int main()
{
  const int N = 15;
  int arr[N], aux[N];
  srand(time(NULL));
  for (int i = 0; i < N; i++) {
        aux[i] = arr[i] = (rand() % 100) - 50;
  }
  for (int i = 0; i<N; i++)
    cout << arr[i] << " ";
  cout << endl;

  // сортируем массив `arr`, используя вспомогательный массив `aux`
  mergesort(arr, aux, 0, N - 1);
  
  for (int i = 0; i<N; i++)
    cout << arr[i] << " ";
  cout << endl;
  return 0;
}
