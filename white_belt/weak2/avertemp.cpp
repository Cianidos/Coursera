#include <vector>
#include <iostream>

using namespace std;

int main()
{
    int n, k, sum = 0;
    vector<int> v;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> k;
        sum += k;
        v.push_back(k);
    }
    sum /= n;
    vector<int> v2;
    k = 0;
    for (int i = 0; i < n; ++i)
    {
        if (v[i] > sum)
        {
            v2.push_back(i);
            ++k;
        }
    }
    cout << k << "\n";
    for (int i : v2)
    {
        cout << i << " ";
    }
    return 0;
}