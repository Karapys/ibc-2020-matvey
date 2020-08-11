#include <iostream>

const int NUM_OF_CITIES = 4;

int orderOfCitiesInPath[NUM_OF_CITIES];

// variables - camalCase
// functions - underscore_case

void find_shortest_path_4(int distances[NUM_OF_CITIES][NUM_OF_CITIES]) {
  int currentMinimalPathDistance = 1000000000;
  int firstCity = 0;
  for (int secCity = 1; secCity < NUM_OF_CITIES; secCity++) {
    for (int thCity = 1; thCity < NUM_OF_CITIES; thCity++) {
      for (int frCity = 1; frCity < NUM_OF_CITIES; frCity++) {
        int orderOfCitiesInPath[4] = {firstCity, secCity, thCity, frCity};
        bool citiesInPathAreAllDifferent = true;
        for (int firstIndex = 0; firstIndex <= 3; firstIndex = firstIndex + 1) {
          for (int secondIndex = 0; secondIndex <= 3; secondIndex = secondIndex + 1) {
            if (firstIndex != secondIndex) {
              int firstCityToCheck = orderOfCitiesInPath[firstIndex];
              int secondCityToCheck = orderOfCitiesInPath[secondIndex];
              if (firstCityToCheck == secondCityToCheck) {
                citiesInPathAreAllDifferent = false;
              }
            }
          }
        }
        if (citiesInPathAreAllDifferent == false) {
          continue;
        } else {
          int currentPathDistance = 0;
          currentPathDistance += distances[firstCity][secCity];
          currentPathDistance += distances[secCity][thCity];
          currentPathDistance += distances[thCity][frCity];
          currentPathDistance += distances[frCity][firstCity];
          if (currentPathDistance < currentMinimalPathDistance)
            currentMinimalPathDistance = currentPathDistance;
        }
      }
    }
  }
  std::cout << currentMinimalPathDistance;
}

int main() {
  int distances[NUM_OF_CITIES][NUM_OF_CITIES] = {
    {0, 10, 8, 6},
    {10, 0, 3, 7},
    {8, 3, 0, 1},
    {6, 7, 1, 0}
  };
  find_shortest_path_4(distances);
}
