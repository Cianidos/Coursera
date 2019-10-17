#include <vector>
#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
    int q;
    vector<int> mounths_sizes =
        {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    vector<string> mounth[32];
    int current_mounth = 0;

    cin >> q;
    for (int j = 0; j < q; ++j)
    {
        string query, s;
        int i;
        cin >> query;
        if (query == "ADD")
        {
            cin >> i >> s;
            mounth[i].push_back(s);
        }
        else if (query == "NEXT")
        {
            int old_count = mounths_sizes[current_mounth];
            if (current_mounth == 11)
            {
                current_mounth = 0;
            }
            else
            {
                ++current_mounth;
            }
            int new_count = mounths_sizes[current_mounth];
            if (new_count < old_count)
            {
                
                for (int i = new_count + 1; i <= old_count; ++i)
                {
                    mounth[new_count].insert(
                        mounth[new_count].end(),
                        mounth[i].begin(),
                        mounth[i].end());
                }
                
               /*
                for (int i = new_count + 1; i <= old_count; ++i)
                {
                    for (auto t : mounth[i])
                    {
                        mounth[new_count].push_back(t);
                    }
                    mounth[i].clear();
                }
                */
            }
        }
        else if (query == "DUMP")
        {
            cin >> i;
            cout << mounth[i].size();
            for (auto d : mounth[i])
            {
                cout << " " << d;
            }
            cout << "\n";
        }
    }
    return 0;
}