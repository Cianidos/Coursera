#include <map>
#include <iostream>
#include <string>
#include <set>

using namespace std;

void ReadStopsVector(set<string> &stops)
{
    int stops_count;
    string stop;
    cin >> stops_count;
    for (int i = 0; i < stops_count; ++i)
    {
        cin >> stop;
        stops.insert(stop);
    }
}
int main()
{
    map<set<string>, int> buses;
    int q, size = 0;
    cin >> q;
    for (int i = 0; i < q; ++i)
    {
        set<string> stops;
        ReadStopsVector(stops);
        if (buses.count(stops) == 1)
        {
            cout << "Already exists for " << buses[stops] << "\n";
        }
        else
        {
            ++size;
            buses[stops] = size;
            cout << "New bus " << size << "\n";
        }
    }
    return 0;
}
