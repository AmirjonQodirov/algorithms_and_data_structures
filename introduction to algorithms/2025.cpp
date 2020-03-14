#include <iostream>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t > 0) {
        int n, k;
        cin >> n >> k;
        int h = n / k;
        int x = k - (n % k);
        int y = n % k;
        int ans = h * ((x * n) - ((h * x * (x + 1)) / 2)) +
                  (h + 1) * (((n - (x * h)) * y) - (((h + 1) * y * (y + 1)) / 2));
        cout << ans;
        t--;
        cout << '\n';
    }
}