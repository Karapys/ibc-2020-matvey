#include <iostream>

const int NUMBER_OF_POINTS = 4;
// Points in space
// Arrays would be better
float x1, y1, x2, y2, x3, y3, x4, y4, px, py;

void checkIfPointsOnSameLine() {
  float term1 = x1 * (y2 - y3);
  float term2 = x2 * (y3 - y1);
  float term3 = x3 * (y1 - y2);
  if (0 == abs( (term1 + term2 + term3) / 2) ) {
    // if on the same line
    std::cout << "3 points are on the same line\n";
    std::exit(0);
  }
}

void checkLastPoint () {
  //TODO
  1 == 1;
}

void getInputFromUser() {
  std::cout << "Please, enter coordinates in clockwise or anticlockwise order, otherwise the program will not work :)\n\n";
  for (int i = 1; i <= NUMBER_OF_POINTS; i++) {
    // Display the mesage
    std::cout << "Enter coordinates of point of parallelogram №" << i << ". Example: -0.1 2: \n";

    if (i == 1) std::cin >> x1 >> y1;
    if (i == 2) std::cin >> x2 >> y2;
    if (i == 3) {
      std::cin >> x3 >> y3;
      checkIfPointsOnSameLine();
    }
    if (i == 4) {
      std::cin >> x4 >> y4;
      checkLastPoint();
    }
  }
  std::cout << "Enter coordinates of point you want to check: \n";
  std::cin >> px >> py;
}



bool checkIfPointInParallelogram() {
  // Actual code
  bool inside = false;
  // Get coordinates of 3 neighbor verticies
  float xb = x1 - x2;
  float yb = y1 - y2;

  float xc = x3 - x2;
  float yc = y3 - y2;

  float xp = px - x2;
  float yp = py - y2;
  float distance = xb * yc - yb * xc;
  if (distance != 0) {
      float oned = 1.0 / distance;
      float bb = (xp * yc - xc * yp) * oned;
      float cc = (xb * yp - xp * yb) * oned;
      inside = (bb >= 0) & (cc >= 0) & (bb <= 1) & (cc <= 1);
  }
  return inside;
}

bool ifPointIsOverlapsVertex() {
  bool term1 = ((px == x1) and (py == y1));
  bool term2 = ((px == x2) and (py == y2));
  bool term3 = ((px == x3) and (py == y3));
  bool term4 = ((px == x4) and (py == y4));
  return (term1 or term2 or term3 or term4);
}

int main() {
  std::cout << "Hello! It is a simple program what check if some point lies in parallelogram\n";
  getInputFromUser();

  // debug 
  //std::cout << x1 << y1 << x2 << y2 << x3 << y3 << x4 << y4 << px << py;
  
  // guard
  if (ifPointIsOverlapsVertex()) {
    std::cout << "Point overlaps some vertex of parallelogram\n";
    return 0;
  }

  float ifInParallelogram = checkIfPointInParallelogram();
  if (ifInParallelogram) {
    std::cout << "Point in the parallelogram or on the border\n";
  } else {
    std::cout << "Point not in the parallelogram\n";
  }
  return 0;
}