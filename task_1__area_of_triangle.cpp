#include <iostream>

const int NUMBER_OF_POINTS = 3;
// Points in space
// Arrays would be better
float x1, y1, x2, y2, x3, y3;

void getInputFromUser() {
  for (int i = 1; i <= NUMBER_OF_POINTS; i++) {
    // Display the mesage
    std::cout << "Enter coordinates of point №" << i << ". Example: -0.1 2: \n";

    if (i == 1) std::cin >> x1 >> y1;
    if (i == 2) std::cin >> x2 >> y2;
    if (i == 3) std::cin >> x3 >> y3;
  }
}

float calculateArea() {
  // Actual code: calcualte area using the formula
  float term1 = x1 * (y2 - y3);
  float term2 = x2 * (y3 - y1);
  float term3 = x3 * (y1 - y2);
  return abs( (term1 + term2 + term3) / 2);
}

int main() {
  std::cout << "Hello! It is a simple program what calculates the area of a triangle\n";
  getInputFromUser();

  float area = calculateArea();
  // Guard
  if (area == 0) {
    std::cout << "It is not a triangle\n";
    return 0;
  }

  std::cout << "Area is " << area << "\n";
  return 0;
}