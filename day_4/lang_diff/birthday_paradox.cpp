#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <chrono> 
using namespace std::chrono; 

const int TIMES = 50000;

int gen_day_of_birth() {
  return rand() % 365 + 1;
}


int check_group(int num_of_people) {
  // Return 1 if group with random numbers of people 
  // satisfies conditions of task.
  int births[num_of_people];
  for (int i = 0; i<num_of_people; i++){
    births[i] = gen_day_of_birth();
  }
  for (int man_1 = 0; man_1 < num_of_people; man_1++) {
    for (int man_2 = man_1; man_2 < num_of_people; man_2++) {
      if (man_1 == man_2) {
        continue;
      } 
      if (births[man_1] == births[man_2]) return 1;
    }
  }
  return 0;
}

int main() {
  srand (time(NULL));

  auto start = high_resolution_clock::now(); 

  int things_to_check[] = {22, 23, 70, 367};
  for (int num_of_people : things_to_check) {
    std::cout << "Probability with " << num_of_people << " people: ";
    float res = 0;
    for (int i = 0; i < TIMES; i++) {
      res += check_group(num_of_people);
    }
    std::cout << res / TIMES * 100 << "%\n";
  }

  auto stop = high_resolution_clock::now(); 
  auto duration = duration_cast<microseconds>(stop - start); 
  std::cout << "Time taken for execution is " << float(duration.count()) / (1000000)<< " seconds\n"; 
}