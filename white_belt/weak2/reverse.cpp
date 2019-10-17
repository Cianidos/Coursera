#include <vector>
#include <algorithm>
//#include <iostream>

using namespace std;

vector<int> Reversed(const vector<int> &v)
{
    auto res = v;
    reverse(res.begin(), res.end());
    return res;
}

int main()
{
    // vector<int> v = {1, 5, 3, 4, 2};
    // auto v2 = Reversed(v);
    // for (auto i: v2){
    //     cout << i << " ";
    // }
    return 0;
}