#include <bits/stdc++.h>

using namespace std;
struct Dir {
  string name;
  map<string, Dir *> subDir;
};
void print_directories(Dir *disk, string space_char) {
  cout << space_char << disk->name << '\n';
  space_char += " ";
  for (auto &it : disk->subDir) {
    print_directories(it.second, space_char);
  }
}

int main() {
  int n;
  string s, temp;
  cin >> n;
  Dir *dir = new Dir;
  dir->name = "";
  for (int i = 1; i <= n; ++i) {
    cin >> s;
    s += "\\";
    temp = "";
    Dir *node = dir;
    for (char j : s) {
      if (j == '\\') {
        auto it = node->subDir.find(temp);
        if (it == node->subDir.end()) {
          auto *new_node = new Dir();
          new_node->name = temp;
          node->subDir[temp] = new_node;
          it = node->subDir.find(temp);
        }
        node = it->second;
        temp = "";
      } else {
        temp += j;
      }
    }
  }
  for (auto &it : dir->subDir) {
    print_directories(it.second, "");
  }
}
