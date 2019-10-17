#include <map>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    int q;
    map<string, string> cou_cap;
    cin >> q;
    for (int i = 0; i < q; ++i)
    {
        string query;
        cin >> query;
        string first, second;
        if (query == "CHANGE_CAPITAL")
        {
            cin >> first >> second;
            if (cou_cap.count(first) == 0)
            {
                cout << "Introduce new country " << first << " with capital " << second << "\n";
                cou_cap[first] = second;
            }
            else if (second == cou_cap[first])
            {
                cout << "Country " << first << " hasn't changed its capital\n";
            }
            else
            {
                cout << "Country " << first << " has changed its capital from " << cou_cap[first] << " to " << second << "\n";
                cou_cap[first] = second;
            }
        }
        else if (query == "RENAME")
        {
            cin >> first >> second;
            if (first == second || cou_cap.count(first) == 0 || cou_cap.count(second) == 1)
            {
                cout << "Incorrect rename, skip\n";
            }
            else
            {
                cout << "Country " << first << " with capital " << cou_cap[first] << " has been renamed to " << second << "\n";
                cou_cap[second] = cou_cap[first];
                cou_cap.erase(first);
            }
        }
        else if (query == "ABOUT")
        {
            cin >> first;
            if (cou_cap.count(first) == 1)
            {
                cout << "Country " << first << " has capital " << cou_cap[first] << "\n";
            }
            else
            {
                cout << "Country " << first << " doesn't exist\n";
            }
        }
        else if (query == "DUMP")
        {
            if (cou_cap.size() > 0)
            {
                for (auto &i : cou_cap)
                {
                    cout << i.first << "/" << i.second << "\n";
                }
            }
            else
            {
                cout << "There are no countries in the world\n";
            }
        }
    }
    return 0;
}