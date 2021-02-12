#include <iostream>
using namespace std;

int * CreateArr(int);
void FillArr(int *, int);
void PrintArr(int *, int);
void Reassign(int *&, int &, int);

int main() {
  int n;
  cout << "введите длину массива" << endl;
  cin >> n;
  
  int *arr = CreateArr(n);
  FillArr(arr, n);
  PrintArr(arr, n);
  cout << "введите k: ";
  int k; cin >> k;

  Reassign(arr, n, k);
  PrintArr(arr, n);
  delete[] arr;
}

int * CreateArr(int n) {
  int *arr = new int[n];
  return arr;
}

void PrintArr(int *arr, int n) {
  for (int i = 0; i < n; i++) {
      cout << arr[i] << ", ";
  }
  cout << endl;
}

void FillArr(int *arr, int n) {
  for (int i = 0; i < n; i++) {
      arr[i] = i;
  }
}

void Reassign(int *&arr, int &n, int k) {
  if (k >= 0 && k <= n+1) {
    int *buff = new int[n+1];
    for (int i = 0; i < k; i++) {
      buff[i] = arr[i];
    }
    buff[0] = 10;

    delete[] arr;
    arr = buff;
    n++;

    PrintArr(buff, n);

  } else {
    cout << "error";
  }
  
}