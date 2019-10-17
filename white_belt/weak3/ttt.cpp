#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>


using namespace std;

void print(const vector<int> &v){
    cout << "Size: " << v.size() << "\n";
    for(auto &i : v){
        cout << i << " ";
    }
    cout << "\n";
}

int main() {
    map<int, string> m = {{1, "ten"}, {10, " one"}, {3, "three"} };
    for (auto &i: m) {
        cout << i.first << " " << i.second << "\n";
    }
    std::cout << __cplusplus << endl;
    return 0;
}