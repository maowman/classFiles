#include <iostream>

int main() {
  int n;
  std::cin >> n;
  unsigned long long max = 0, nextMax = 0, cache, result;
  for (int i = 0; i < n; i++) {
    std::cin >> cache;
    if (cache > max) {
      nextMax = max;
      max = cache;
    } else if (cache > nextMax) {
      nextMax = cache;
    }
  }
  result = max * nextMax;
  std::cout << result << std::endl;
}