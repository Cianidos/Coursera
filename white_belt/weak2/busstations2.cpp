#include <map>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void ReadStopsVector(vector<string> &stops)
{
    int stops_count;
    string stop;
    cin >> stops_count;
    for (int i = 0; i < stops_count; ++i)
    {
        cin >> stop;
        stops.push_back(stop);
    }
}
int main()
{
    map<vector<string>, int> buses;
    int q, size = 0;
    cin >> q;
    for (int i = 0; i < q; ++i)
    {
        vector<string> stops;
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
