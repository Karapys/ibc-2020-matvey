#include <iostream>
#include <set>

int array[8][2];
bool checkQueensNotIntersecting() {
  std::set <int> st;
  std::set <int> st2;
  std::set <int> st3;
  std::set <int> st4;
  
  for (auto& pair: array) {
    // Checka diagonals
    st.insert(pair[0] + pair[1]);
    st2.insert(pair[1] - pair[0]);
    // Check lines
    st3.insert(pair[0]);
    st4.insert(pair[1]);
  }
  return (st.size() == 8) and (st2.size() == 8) and (st3.size() == 8) and (st4.size() == 8);
}

int main() {
  int tmp1, tmp2;
  for (int i=0; i<8; i++) {
    std::cin >> tmp1 >> tmp2;
    array[i][0] = tmp1;
    array[i][1] = tmp2;
  }
  if (not checkQueensNotIntersecting()) {
    std::cout<< "YES";
  } else {
    std::cout << "NO";
  }

  return 0;
}