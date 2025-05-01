#include <iostream>

int main() {
    float length, width;

    std::cout << "Enter length: ";
    std::cin >> length;

    std::cout << "Enter width: ";
    std::cin >> width;

    float area = length * width;

    std::cout << "Area = " << area << std::endl;

    return 0;
}
