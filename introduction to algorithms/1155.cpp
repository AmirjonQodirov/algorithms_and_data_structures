#include <iostream>
#include <vector>
using namespace std;
int a, b, c, d, e, f, g, h;
int get_value(char x) {
    switch (x) {
        case 'A':
            return a;
        case 'B':
            return b;
        case 'C':
            return c;
        case 'D':
            return d;
        case 'E':
            return e;
        case 'F':
            return f;
        case 'G':
            return g;
        case 'H':
            return h;
    }
    return 0;
}void dead(char x) {
    switch (x) {
        case 'A':
            a--;
            break;
        case 'B':
            b--;
            break;
        case 'C':
            c--;
            break;
        case 'D':
            d--;
            break;
        case 'E':
            e--;
            break;
        case 'F':
            f--;
            break;
        case 'G':
            g--;
            break;
        case 'H':
            h--;
            break;
    }
}
bool check(string str) {
    if ((get_value(str[0]) > 0) && (get_value(str[1]) > 0)) {
        dead(str[0]);
        dead(str[1]);
        return true;}
    return false;
}
int main() {
    cin >> a >> b >> c >> d >> e >> f >> g >> h;
    vector<string> path{
            "DH", "DH-", "DA", "DA-", "DC", "DC-", "DF", "AB+\nDA-\nFB-",
            "HD", "HD-", "HE", "HE-", "HG", "HG-", "HB", "EF+\nHE-\nFB-",
            "EH", "EH-", "EA", "EA-", "EF", "EF-", "EC", "FB+\nEF-\nBC-",
            "AD", "AD-", "AE", "AE-", "AB", "AB-", "AG", "FB+\nAB-\nFG-",
            "FE", "FE-", "FB", "FB-", "FG", "FG-", "FD", "EA+\nFE-\nDA-",
            "BA", "BA-", "BF", "BF-", "BC", "BC-", "BH", "EA+\nBA-\nHE-",
            "GF", "GF-", "GC", "GC-", "GH", "GH-", "GA", "EF+\nGF-\nAE-",
            "CG", "CG-", "CB", "CB-", "CD", "CD-", "CE", "AB+\nCB-\nAE-"};
    string ans;
    if ((e + b + d + g != a + f + c + h)) {
        cout << "IMPOSSIBLE";
        return 0;
    }
    for (int i = 0; i < path.size(); i += 2) {
        while (check(path[i])) {
            ans += path[i + 1] + "\n";
        }
    }
    cout << ans;
    return 0;
}