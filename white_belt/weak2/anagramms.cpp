#include <vector>
#include <iostream>
#include <string>
#include <map>
using namespace std;

map<char, int> BuildCharCounters(const string &st)
{
    map<char, int> result;
    for (auto i : st)
    {
        ++result[i];
    }
    return result;
}

bool IsAnagramm(map<char, int> &one, map<char, int> &two)
{
    for (auto &i : one)
    {
        if (!(i.second == two[i.first]))
        {
            return false;
        }
    }
    for (auto &i : two)
    {
        if (!(i.second == one[i.first]))
        {
            return false;
        }
    }
    return true;
}
int main()
{
    int n;
    cin >> n;
    string first, second;
    for (int i = 0; i < n; ++i)
    {
        cin >> first >> second;
        map<char, int> one, two;
        one = BuildCharCounters(first);
        two = BuildCharCounters(second);
        if (IsAnagramm(one, two))
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
    return 0;
}