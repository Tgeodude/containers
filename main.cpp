#include "s21_vector.h"
#include <iostream>

int main() {
  vector<int> myVector = {1, 2, 3};
  vector<int> myVector2 = std::move(myVector);
  std:: cout << myVector2[2] << std::endl;
}