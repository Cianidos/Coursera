#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> A;
    int d;
    for (int i = 0; i < n; ++i)
    {
        cin >> d;
        A.push_back(d);
    }
    sort(A.begin(), A.end(), [](int x, int y) { return abs(x) < abs(y); });
    for (auto &i : A)
    {
        cout << i << " ";
    }
    return 0;
}