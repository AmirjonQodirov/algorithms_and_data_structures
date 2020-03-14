#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n;
    int tme;
    cin >> n;
    vector<int> times(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> tme;
        times[i] = tme;
    }
    int ans = times[0];
    int sum = 0;
    for (int r = 0; r < n; r++) {
        sum += times[r];
        ans = max(ans, sum);
        sum = max(sum, 0);
    }
    if (ans < 0) {
        ans = 0;
    }
    cout << ans << endl;
    return 0;
}