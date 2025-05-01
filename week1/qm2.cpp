#include <iostream>

int main() {
  float a, b;

  std::cout << "Enter first number: ";
  std::cin >> a;

  std::cout << "Enter second number: ";
  std::cin >> b;

  float sum = a + b;
  float diff = a - b;
  float product = a * b;

  std::cout << "Sum = " << sum << " difference = " << diff << " product = " << product << std::endl;

  if (b != 0) {
    float quotient = a / b;
    std::cout << ", Quotient = " << quotient << std::endl;
  } else {
    std::cout << ", cannot divide by zero." << std::endl;
  }

  return 0;
}