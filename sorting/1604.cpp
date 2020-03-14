#include <bits/stdc++.h>
using namespace std;
bool compare(pair<int, int> a, pair<int, int> b) { return a.first > b.first; }
int main() {
    pair<int, int> signs[10000];
    int n;
    cin >> n;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> signs[i].first;
        sum += signs[i].first;
        signs[i].second = i + 1;
    }
    sort(signs, signs + n, compare);
    while (sum > 0) {
        sum--;
        cout << signs[0].second << " ";
        signs[0].first--;
        if (signs[1].first != 0) {
            cout << signs[1].second << " ";
            signs[1].first--;
        }
        int j = 1, k = 2;while (signs[j].first < signs[k].first) {
            int t = signs[j].first;
            signs[j].first = signs[k].first;
            signs[k].first = t;
            t = signs[j].second;
            signs[j].second = signs[k].second;
            signs[k].second = t;
            k++;
            j++;
            if (k == n) {
                break;
            }
        }
        j = 0, k = 1;
        while (signs[j].first < signs[k].first) {
            int t = signs[j].first;
            signs[j].first = signs[k].first;
            signs[k].first = t;
            t = signs[j].second;
            signs[j].second = signs[k].second;
            signs[k].second = t;
            k++;
            j++;
            if (k == n) {
                break;
            }
        }
        if (signs[0].first <= 0) {
            return 0;
        }
    }
    return 0;
}