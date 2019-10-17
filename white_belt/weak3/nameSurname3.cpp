#include <iostream>
#include <map>
#include <string>
#include <stack>

using namespace std;

// если имя неизвестно, возвращает пустую строку
string FindNameByYear(const map<int, string>& names, int year) {
  string name;  // изначально имя неизвестно
  
  // перебираем всю историю по возрастанию ключа словаря, то есть в хронологическом порядке
  for (const auto& item : names) {
    // если очередной год не больше данного, обновляем имя
    if (item.first <= year) {
      name = item.second;
    } else {
      // иначе пора остановиться, так как эта запись и все последующие относятся к будущему
      break;
    }
  }
  
  return name;
}

string FindNamesBeforYear(const map<int, string>& names, int year) {
  string result = "";
  string name = "";
  stack<string> temp;
  bool first = false;
  for (auto iter = names.rbegin(); iter != names.rend(); ++iter) {
    // если очередной год не больше данного, обновляем имя
    auto item = *iter;
    if (item.first <= year) {
      if (name != item.second) {
        if (first) {
          temp.push(item.second);
          result += (item.second + ", ");}
        name = item.second;
      }
      first = true;
    } else {
      // иначе пора остановиться, так как эта запись и все последующие относятся к будущему

    }
  }
  
  if (!result.empty()) {
    result.pop_back();
    result.pop_back();
  }
  return result;
}

class Person {
public:
  Person (string firstn, string lastn, int year) {
    burn_year = year;
    first_names[year] = firstn;
    last_names[year] = lastn;
  }
  void ChangeFirstName(int year, const string& first_name) {
    first_names[year] = first_name;
  }
  void ChangeLastName(int year, const string& last_name) {
    last_names[year] = last_name;
  }
  string GetFullName(int year) const {
    if (year < burn_year) {
      return "No person";
    }
    // получаем имя и фамилию по состоянию на год year
    const string first_name = FindNameByYear(first_names, year);
    const string last_name = FindNameByYear(last_names, year);
    
    // если и имя, и фамилия неизвестны
    if (first_name.empty() && last_name.empty()) {
      return "Incognito";
    
    // если неизвестно только имя
    } else if (first_name.empty()) {
      return last_name + " with unknown first name";
      
    // если неизвестна только фамилия
    } else if (last_name.empty()) {
      return first_name + " with unknown last name";
      
    // если известны и имя, и фамилия
    } else {
      return first_name + " " + last_name;
    }
  }
  string GetFullNameWithHistory(int year) const {
    if (year < burn_year) {
      return "No person";
    }
    const string first_name = FindNameByYear(first_names, year);
    const string last_name = FindNameByYear(last_names, year);
    
    string old_first_names = FindNamesBeforYear(first_names, year);
    string old_last_names = FindNamesBeforYear(last_names, year);



    if (first_name.empty() && last_name.empty()) {
      return "Incognito";

    } else if (first_name.empty() && old_last_names.empty()) {
      return last_name + " with unknown first name";

    } else if (first_name.empty()) {
      return last_name + " (" + old_last_names + ") with unknown first name";

    } else if (last_name.empty() && old_first_names.empty()) {
      return first_name + " with unknown last name";

    } else if (last_name.empty()) {
      return first_name + " (" + old_first_names + ") with unknown last name";

    } else if (old_last_names.empty() && old_first_names.empty()) {
      return first_name + " " + last_name;

    } else if (old_first_names.empty()) {
      return first_name + " " +
             last_name + " (" + old_last_names + ")";

    } else if (old_last_names.empty()) {
      return first_name + " (" + old_first_names + ") " +
             last_name;
    } else {
      return first_name + " (" + old_first_names + ") " +
             last_name + " (" + old_last_names + ")";
    }
  }

private:

  int burn_year;
  map<int, string> first_names;
  map<int, string> last_names;
};



int main() {
  Person person("Polina", "Sergeeva", 1960);
  for (int year : {1959, 1960}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }
  
  person.ChangeFirstName(1965, "Appolinaria");
  person.ChangeLastName(1967, "Ivanova");
  for (int year : {1965, 1967}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  return 0;
}