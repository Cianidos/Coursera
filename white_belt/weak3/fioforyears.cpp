#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct Person
{
public:
    void ChangeFirstName(int year, const string &first_name)
    {
        year_name[year] = first_name;
    }
    void ChangeLastName(int year, const string &last_name)
    {
        year_surname[year] = last_name;
    }
    string GetFullName(int year)
    {
        bool i_name = false, i_sur = false;
        string name1 = "", name2 = "";

        for (auto i : year_name)
        {
            if (i.first <= year)
            {
                i_name = true;
                name1 = i.second;
            }
        }
        for (auto i : year_surname)
        {
            if (i.first <= year)
            {
                i_sur = true;
                name2 = i.second;
            }
        }
        if (i_name && i_sur)
        {
            return (name1 + " " + name2);
        }
        else if (i_name)
        {
            return (name1 + " with unknown last name");
        }
        else if (i_sur)
        {
            return (name2 + " with unknown first name");
        }
        else
        {
            return "Incognito";
        }
    }
    string GetFullNameWithHistory(int year)
    {
        bool i_name = false, i_sur = false, i_n_cop = false, i_s_cop = false;
        string name1 = "", name2 = "", result = "";
        vector<string> nas, surs;

        for (auto i : year_name)
        {
            if (i.first <= year)
            {
                name1 = i.second;
                if (i_name){
                if (nas[nas.size() - 1] != name1) {
                    nas.push_back(name1);
                }
                }
                i_name = true;
            }
        }
        for (auto i : year_surname)
        {
            if (i.first <= year)
            {
                name2 = i.second;
                if (i_sur){
                if (surs[surs.size() - 1] != name2) {
                    surs.push_back(name2);
                }
                }
                i_sur = true;
            }
        }
        reverse(nas.begin(), nas.end());
        reverse(surs.begin(), surs.end());
        
        if (i_name && i_sur)
        {
            result += name1;
            if (nas.size() > 1){
                result += " (";
                nas.erase(nas.begin());
                for (string i: nas) {
                    result += i;
                    result += ",";
                }
                result.erase(result.end());
                result += ")";
            }
            result += " ";
            result += name2;
            if (surs.size() > 1){
                result += " (";
                surs.erase(surs.begin());
                for (string i: surs) {
                    result += i;
                    result += ",";
                }
                result.erase(result.end());
                result += ")";
            }
            return result;
        }
        else if (i_name)
        {
            result += name1;
            if (nas.size() > 1){
                result += " (";
                nas.erase(nas.begin());
                for (string i: nas) {
                    result += i;
                    result += ",";
                }
                result.erase(result.end());
                result += ")";
            }
            return (result + " with unknown last name");
        }
        else if (i_sur)
        {
            result += name2;
            if (surs.size() > 1){
                result += " (";
                surs.erase(surs.begin());
                for (string i: surs) {
                    result += i;
                    result += ",";
                }
                result.erase(result.end());
                result += ")";
            }
            return (result + " with unknown first name");
        }
        else
        {
            return "Incognito";
        }
    }

private:
    string current_name, current_surname;
    map<int, string> year_name;
    map<int, string> year_surname;
};

int main() {
  Person person;

  person.ChangeFirstName(1900, "Eugene");
  person.ChangeLastName(1900, "Sokolov");
  person.ChangeLastName(1910, "Sokolov");
  person.ChangeFirstName(1920, "Evgeny");
  person.ChangeLastName(1930, "Sokolov");
  cout << person.GetFullNameWithHistory(1940) << endl;
  
  return 0;
}