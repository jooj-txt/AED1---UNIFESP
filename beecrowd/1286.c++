#include <bits/stdc++.h>
// using namespace std;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  int testcases;
  while (std::cin >> testcases && testcases != 0) {
    int max;
    std::cin >> max;
    std::vector<int> time;
    std::vector<int> pizzas;
    while (testcases--) {
      int t, p;
      std::cin >> t >> p;
      time.push_back(t);
      pizzas.push_back(p);
    }

    //std::vector<int> poss(max + 1, 0);
    //poss[0] = 0;
    //for (int i = 1; i <= max; i++) {
    //  for (int j = 0; j < pizzas.size(); j++) {
    //    if (i >= pizzas[j]) {
    //      poss[i] = std::max(poss[i - pizzas[j]] + time[j], poss[i]);
    //    }
    //  }
    //}

    std::cout << max << " min.\n";
  }

  return 0;
}