#include <iostream>
#include <stdexcept>

int f(int x) {
  int result = 0;

  try {
    if (x == 0) {
      throw std::runtime_error("division by zero");
    }
    result = 10 / x;
  } catch (const std::runtime_error&) {
    result = 0;
  }
  
  std::cout << "done" << std::endl;
  return result;
}