#include <bits/stdc++.h>
using namespace std;
vector<int> vrr_x[30100], vrr_y[30100];
map<int, bool> mp_x[30100];
int main() {
  int n, m, k, ans;
  cin >> n >> m >> k;
  for (int i = 1; i <= k; i++) {
    int x, y;
    cin >> x >> y;
    vrr_x[x].push_back(y);
    vrr_y[y].push_back(x);
  }
  ans = 0;
  for (int x = 1; x <= n; x++) {
    if (vrr_x[x].empty()) {
      if (m > 1)
        ans++;
      else
        mp_x[x][1] = 1;
    } else {
      int left = 1;
      sort(vrr_x[x].begin(), vrr_x[x].end());
      for (int y : vrr_x[x]) {
        if (left + 1 == y)
          mp_x[x][left] = 1;
        else if (left < y)
          ans++;
        left = y + 1;
      }
      if (left == m)
        mp_x[x][m] = 1;
      else if (left < m)
        ans++;
    }
  }
  for (int y = 1; y <= m; y++) {
    if (vrr_y[y].empty()) {
      if (n > 1)
        ans++;
      else
        ans += mp_x[1][y];
    } else {
      int left = 1;
      sort(vrr_y[y].begin(), vrr_y[y].end());
      for (int x : vrr_y[y]) {
        if (left + 1 == x)
          ans += mp_x[left][y];
        else if (left < x)
          ans++;
        left = x + 1;
      }
      if (left == n)
        ans += mp_x[n][y];
      else if (left < n)
        ans++;
    }
  }
  cout << ans;
}
