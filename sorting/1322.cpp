#include <iostream>
using namespace std;
int d_sim[100], begin_sim[100], next_sim[100100];
int get_id(char a) {
    if (a <= 'Z')
        return int(a) - int('A');
    if (a == '_')
        return 26;
    return int(a) - int('a') + 27;
}
int main() {
    int k;
    string s;
    cin >> k >> s;
    for (int i = 0; i < s.size(); i++) {
        d_sim[get_id(s[i])]++;
        cout << d_sim[get_id(s[i])] << "\n";
    }
    begin_sim[0] = 0;
    for (int i = 1; i <= 70; i++) {
        begin_sim[i] = begin_sim[i - 1] + d_sim[i - 1];cout << begin_sim[i] << "\n";
    }
    for (int i = 0; i < s.size(); i++) {
        int id = get_id(s[i]);
        int position = begin_sim[id];
        begin_sim[id]++;
        next_sim[position] = i;
    }
    int x = next_sim[k - 1];
    for (int i = 0; i < s.size(); i++) {
        cout << s[x];
        x = next_sim[x];
    }
}