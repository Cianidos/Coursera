#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class Date
{
  int year;
  int month;
  int day;

public:
  Date()
  {
    year = 0;
    month = 0;
    day = 0;
  }
  Date(const Date& d)
  {
    year = d.year;
    month = d.month;
    day = d.day;
  }
  Date(string date)
  {
    stringstream s(date);
    char d;
    s >> year >> d >> month >> d >> day;
  }
  int GetYear() const { return year; }
  int GetMonth() const { return month; }
  int GetDay() const { return day; }
  string toString() const
  {
    stringstream s;
    s << setfill('0') << setw(4) << year;
    s << '-';
    s << setfill('0') << setw(2) << month;
    s << '-';
    s << setfill('0') << setw(2) << day;
    return s.str();
  }
};
bool
operator<(const Date& lhs, const Date& rhs)
{
  if (lhs.GetYear() != rhs.GetYear()) {
    return lhs.GetYear() < rhs.GetYear();
  }
  if (lhs.GetMonth() != rhs.GetMonth()) {
    return lhs.GetMonth() < rhs.GetMonth();
  }
  if (lhs.GetDay() != rhs.GetDay()) {
    return lhs.GetDay() < rhs.GetDay();
  }
  return false;
}
class Database
{
  map<Date, set<string>> base;

public:
  void AddEvent(Date date, string event) { base[date].insert(event); }
  bool DeleteEvent(const Date& date, const string& event)
  {
    if (base.count(date) && base.at(date).count(event)) {
      base.at(date).erase(event);
      return true;
    };
    return false;
  }
  int DeleteDate(const Date& date)
  {
    if (base.count(date)) {
      int n = base.at(date).size();
      base.erase(date);
      return n;
    }
    return 0;
  }
  void Find(const Date& date) const
  {
    try {
      for (auto const& e : base.at(date)) {
        cout << e << "\n";
      }
    } catch (exception& ex) {
    }
  }
  void Print() const
  {
    for (auto const& date : base) {
      for (auto const& event : date.second) {
        cout << date.first.toString() << " " << event << "\n";
      }
    }
  }
};
const int
is_format_correct(const string& date)
{
  stringstream stream(date);
  char d;
  int i;
  if (!(stream >> i)) {
    return 0;
  }
  if (!(stream >> d && d == '-')) {
    return 0;
  }
  if (!(stream >> i)) {
    return 0;
  }
  if (i < 1 || i > 12) {
    cout << "Month value is invalid: " << i << '\n';
    return 2;
  }
  if (!(stream >> d && d == '-')) {
    return 0;
  }
  if (!(stream >> i)) {
    return 0;
  }
  if (i < 1 || i > 31) {
    cout << "Day value is invalid: " << i << '\n';
    return 3;
  }
  if (stream >> d) {
    return 0;
  }
  return 1;
}
int
main()
{
  Database db;
  string command;
  while (getline(cin, command)) {
    stringstream stream(command);
    string query, date, event;
    stream >> query;
    if (query == "" || query == " " || query == "\n") {
      continue;
    }
    if (query == "Print") {
      db.Print();
      continue;
    }
    stream >> date;
    switch (is_format_correct(date)) {
      case 0:
        cout << "Wrong date format: " << date << '\n';
        break;
      case 2:
        break;
      case 3:
        break;
      case 1:
        if (!(stream >> event)) {
          if (query == "Find") {
            db.Find(date);
            continue;
          }
          if (query == "Del") {
            cout << "Deleted " << db.DeleteDate(date) << " events" << '\n';
            continue;
          }
        } else {
          if (query == "Add") {
            db.AddEvent(date, event);
            continue;
          }
          if (query == "Del") {
            if (db.DeleteEvent(date, event)) {
              cout << "Deleted successfully" << '\n';
            } else {
              cout << "Event not found" << '\n';
            }
            continue;
          }
        }
        cout << "Unknown command: " << query << '\n';
    }
  }
  return 0;
}