#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

string lowercase(string s)
{
    string result;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
            s[i] = char(+s[i] + 32);
    }
    return s;
}

int main()
{
    int n;
    cin >> n;
    vector<string> A;
    string d;
    for (int i = 0; i < n; ++i)
    {
        cin >> d;
        A.push_back(d);
    }
    sort(A.begin(), A.end(), [](string a, string b) {
        string x, y;
        x = lowercase(a);
        y = lowercase(b);
        bool z = x < y;
        return z;
    });
    for (auto &i : A)
    {
        cout << i << " ";
    }
    return 0;
}
