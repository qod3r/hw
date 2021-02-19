#include <iostream>

namespace qL {
  void Print(double arr[], int n) {
    std::cout << "[";
    for (int i = 0; i < n; i++) {
      std::cout << arr[i] << ", ";
    }
    std::cout << "\b\b" << "]" << std::endl;
  }
}