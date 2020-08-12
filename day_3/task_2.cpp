#include <iostream>
#include <vector>

int main() {
  int K, N, l, r;
  std::cin >> N >> K;
  std::vector <char> bottles(N, 'I');
  for (int i = 0; i<K; i++) {
    std::cin >> l >> r;
    for (int j = l; j<=r; j++) {
      bottles[j-1] = '.';
    }
  }
  for (const auto& ch: bottles)
  std::cout << ch;
  return 0;
}