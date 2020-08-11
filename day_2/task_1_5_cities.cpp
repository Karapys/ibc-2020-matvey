#include <iostream>

const int NUM_OF_CITIES = 5;

int orderOfCitiesInPath[NUM_OF_CITIES];

// variables - camalCase
// functions - underscore_case

void find_shortest_path_5(int distances[NUM_OF_CITIES][NUM_OF_CITIES]) {
  int currentMinimalPathDistance = 1000000000;
  int firstCity = 0;
  for (int secCity = 1; secCity < NUM_OF_CITIES; secCity++) {
    for (int thCity = 1; thCity < NUM_OF_CITIES; thCity++) {
      for (int frCity = 1; frCity < NUM_OF_CITIES; frCity++) {
        for (int fifCity = 1; fifCity < NUM_OF_CITIES; fifCity++) {
          int orderOfCitiesInPath[NUM_OF_CITIES] = {firstCity, secCity, thCity, frCity, fifCity};
          bool citiesInPathAreAllDifferent = true;
          for (int firstIndex = 0; firstIndex < NUM_OF_CITIES; firstIndex = firstIndex + 1) {
            for (int secondIndex = 0; secondIndex < NUM_OF_CITIES; secondIndex = secondIndex + 1) {
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
            currentPathDistance += distances[frCity][fifCity];
            currentPathDistance += distances[fifCity][firstCity];
            if (currentPathDistance < currentMinimalPathDistance)
              currentMinimalPathDistance = currentPathDistance;
          }
        }
      }
    }
  }
  std::cout << currentMinimalPathDistance;
}

int main() {
  int distances[NUM_OF_CITIES][NUM_OF_CITIES] = {
    {0, 3, 13, 9, 7},
    {3, 0, 6, 12, 10},
    {13, 6, 0, 9, 6},
    {9, 12, 9, 0, 8},
    {7, 10, 6, 8, 0}
  };
  find_shortest_path_5(distances);
}
