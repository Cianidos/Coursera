#include <map>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int q;
    map<string, vector<string>> buses_stops;
    map<string, vector<string>> stops_busses;
    cin >> q;
    for (int i = 0; i < q; ++i)
    {
        string query;
        cin >> query;
        if (query == "NEW_BUS")
        {
            string bus_name, stop_name;
            int stop_count;
            cin >> bus_name >> stop_count;
            for (int i = 0; i < stop_count; ++i){
                cin >> stop_name;
                buses_stops[bus_name].push_back(stop_name);
                stops_busses[stop_name].push_back(bus_name);
            }
        }
        else if (query == "BUSES_FOR_STOP")
        {
            string stop;
            cin >> stop;
            if (stops_busses.count(stop) == 0){
                cout << "No stop\n";
            } else {
                for (string bus : stops_busses[stop]){
                    cout << bus << " ";
                }
                cout << "\n";
            }
        }
        else if (query == "STOPS_FOR_BUS")
        {
            string bus;
            cin >> bus;
            if (buses_stops.count(bus) == 0){
                cout << "No bus\n";
            } else {
                for (string stop : buses_stops[bus]){
                    cout << "Stop " << stop << ": ";
                    if (stops_busses[stop].size() == 1) {
                        cout << "no interchange\n";
                    } else {
                        for (string bus1 : stops_busses[stop]){
                            if (bus != bus1){
                                cout << bus1 << " ";
                            }
                        }
                        cout << "\n";
                    }
                }
            }
        }
        else if (query == "ALL_BUSES")
        {
            if (buses_stops.size() == 0){
                cout << "No buses\n";
            } else {
                for (auto item : buses_stops){
                    cout << "Bus " << item.first << ": ";
                    for (string stop : item.second){
                        cout << stop << " ";
                    }
                    cout << "\n";
                }
            }
        }
    }
    return 0;
}

/*
18
ALL_BUSES
BUSES_FOR_STOP Marushkino
STOPS_FOR_BUS 32K
NEW_BUS 32 3 Tolstopaltsevo Marushkino Vnukovo
NEW_BUS 32K 6 Tolstopaltsevo Marushkino Vnukovo Peredelkino Solntsevo Skolkovo
BUSES_FOR_STOP Vnukovo
NEW_BUS 950 6 Kokoshkino Marushkino Vnukovo Peredelkino Solntsevo Troparyovo
NEW_BUS 272 4 Vnukovo Moskovsky Rumyantsevo Troparyovo
NEW_BUS 1 3 Vnukovo Moskovsky Rumyantsevo
NEW_BUS 2 2 Vnukovo Moskovsky
STOPS_FOR_BUS 1
BUSES_FOR_STOP Tolstopaltsevo
BUSES_FOR_STOP Kokoshkino
BUSES_FOR_STOP Moskovsky
STOPS_FOR_BUS 32K
BUSES_FOR_STOP Solntsevo 
STOPS_FOR_BUS 950
ALL_BUSES

No buses
No stop
No bus
32 32K 
Stop Vnukovo: 32 32K 950 272 2 
Stop Moskovsky: 272 2 
Stop Rumyantsevo: 272 
32 32K 
950 
272 1 2 
Stop Tolstopaltsevo: 32 
Stop Marushkino: 32 950 
Stop Vnukovo: 32 950 272 1 2 
Stop Peredelkino: 950 
Stop Solntsevo: 950 
Stop Skolkovo: no interchange
32K 950 
Stop Kokoshkino: no interchange
Stop Marushkino: 32 32K 
Stop Vnukovo: 32 32K 272 1 2 
Stop Peredelkino: 32K 
Stop Solntsevo: 32K 
Stop Troparyovo: 272 
Bus 1: Vnukovo Moskovsky Rumyantsevo 
Bus 2: Vnukovo Moskovsky 
Bus 272: Vnukovo Moskovsky Rumyantsevo Troparyovo 
Bus 32: Tolstopaltsevo Marushkino Vnukovo 
Bus 32K: Tolstopaltsevo Marushkino Vnukovo Peredelkino Solntsevo Skolkovo 
Bus 950: Kokoshkino Marushkino Vnukovo Peredelkino Solntsevo Troparyovo 
*/