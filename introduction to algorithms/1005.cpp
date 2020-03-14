#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int stones[22];
    for (int i = 0; i < n; i++) {
        cin >> stones[i];
    }
    int result = 2000000;
    for (int i = 0; i < 1 << n; i++) {
        int first = 0;
        int second = 0;
        int I = i;
        for (int j = 0; j < n; j++) {
            if (I % 2 == 0) {
                second += stones[j];
            } else {
                first += stones[j];
            }
            I = I / 2;
        }
        result = min(result, abs(first - second));
    }
    cout << result;
}