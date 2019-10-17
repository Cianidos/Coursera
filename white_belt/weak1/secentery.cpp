#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int k, id;
    k = id = 0;
    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] == 'f' && k < 2)
        {
            ++k;
            id = i;
        }
    }
    switch (k)
    {
    case 2:
        cout << id;
        break;
    case 1:
        cout << -1;
        break;
    default:
        cout << -2;
        break;
    }
}