#include <iostream>
#include <vector>
#include <algorithm>

const int NUM_OF_CITIES = 6;

int orderOfCitiesInPath[NUM_OF_CITIES];

// variables - camalCase
// functions - underscore_case

void find_shortest_path(int distances[NUM_OF_CITIES][NUM_OF_CITIES]) {
  std::vector<int> vertex; 
  for (int i = 1; i < NUM_OF_CITIES; i++) 
    vertex.push_back(i); 
  int currentMinimalPathDistance = 1000000000;
  do { 
        int currentCost = 0; 
        int k = 0; 
        for (int i = 0; i < vertex.size(); i++) { 
            currentCost += distances[k][vertex[i]]; 
            k = vertex[i]; 
        } 
        currentCost += distances[k][0];
        currentMinimalPathDistance = std::min(currentMinimalPathDistance, currentCost);
    } while (next_permutation(vertex.begin(), vertex.end())); 
  std::cout << currentMinimalPathDistance;
}

int main() {
  int distances[NUM_OF_CITIES][NUM_OF_CITIES];
  if (NUM_OF_CITIES == 4) {
    int distances[4][4] = {
      {0, 10, 8, 6},
      {10, 0, 3, 7},
      {8, 3, 0, 1},
      {6, 7, 1, 0}
    };
  } else if (NUM_OF_CITIES == 5) {
    int distances[5][5] = {
      {0, 3, 13, 9, 7},
      {3, 0, 6, 12, 10},
      {13, 6, 0, 9, 6},
      {9, 12, 9, 0, 8},
      {7, 10, 6, 8, 0}
    };
  } else {
    int distances[6][6] = {
      {0, 9, 14, 2, 6, 11},
      {9, 0, 4, 1, 7, 6},
      {14, 4, 0, 2, 10, 9},
      {2, 1, 2, 0, 5, 12},
      {6, 7, 10, 5, 0, 3},
      {11, 6, 9, 12, 3, 0}
    };
  }

  find_shortest_path(distances);
}
