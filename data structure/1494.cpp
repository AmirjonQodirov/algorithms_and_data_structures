#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, x, last;
  cin >> n;
  deque<int> pocket;
  last = 0;
  for (int i = 1; i <= n; i++) {
    cin >> x;
    if (x > last) {
      for (int j = last + 1; j <= x; j++) {
        pocket.push_back(j);
      }
      last = x;
    }
    if (pocket.back() == x) {
      pocket.pop_back();
    } else {
      cout << "Cheater";
      return 0;
    }
  }
  cout << "Not a proof";
}
