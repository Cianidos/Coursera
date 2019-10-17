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
  if (lhs.GetYear() < rhs.GetYear()) {
    return true;
  } else if (lhs.GetYear() > rhs.GetYear()) {
    return false;
  } else if (lhs.GetMonth() < rhs.GetMonth()) {
    return true;
  } else if (lhs.GetMonth() > rhs.GetMonth()) {
    return false;
  } else if (lhs.GetDay() < rhs.GetDay()) {
    return true;
  } else {
    return false;
  }
}

class Database
{
  map<Date, set<string>> base;

public:
  void AddEvent(Date date, string event) { base[date].insert(event); }
  void DeleteEvent(const Date& date, const string& event)
  {
    string st;
    for (const auto& i : base.at(date)) {
      st += i;
    }
    if (st.find(event) != string::npos) {

      base.at(date).erase(event);
      cout << "Deleted successfully\n";

    } else {
      cout << "Event not found\n";
    }
  }

  void DeleteDate(const Date& date)
  {
    int n = base.at(date).size();
    base.erase(date);
    cout << "Deleted " << n << " events\n";
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
    for (auto const& d : base) {
      for (auto const& e : base.at(d.first)) {
        cout << d.first.toString() << " " << e << "\n";
      }
    }
  }
};

const bool
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

  if (!(stream >> d && d == '-')) {
    return 0;
  }

  if (!(stream >> i)) {
    return 0;
  }

  if (stream >> d) {
    return 0;
  }

  return 1;
}

const bool
is_date_correct(const Date& date)
{
  if (date.GetMonth() < 1 || date.GetMonth() > 12) {
    cout << "Month value is invalid: " << date.GetMonth() << '\n';
    return 0;
  }

  if (date.GetDay() < 1 || date.GetDay() > 31) {
    cout << "Day value is invalid: " << date.GetDay() << '\n';
    return 0;
  }
  return 1;
}

void
programm()
{
  Database db;
  string command;

  while (getline(cin, command)) {
    stringstream stream(command);
    string query;
    stream >> query;

    if (query == "Add") {

      string date, event;
      stream >> date;
      if (is_format_correct(date)) {
        if (is_date_correct(date)) {
          stream >> event;
          db.AddEvent(date, event);
        } else {
          continue;
        }
      } else {
        cout << "Wrong date format: " << date << '\n';
        continue;
      }

    } else if (query == "Del") {

      string s;
      s = stream.str();
      s = s.substr(4);
      if (s.find(' ') == string::npos) {
        if (is_format_correct(s)) {
          if (is_date_correct(s)) {
            db.DeleteDate(s);
          } else {
            continue;
          }
        } else {
          cout << "Wrong date format: " << s << '\n';
          continue;
        }
      } else {

        string date, event;
        stream >> date;
        if (is_format_correct(date)) {
          if (is_date_correct(date)) {
            stream >> event;
            db.DeleteEvent(date, event);
          } else {
            continue;
          }
        } else {
          cout << "Wrong date format: " << date << '\n';
          continue;
        }
      }
    } else if (query == "Find") {

      string date;
      stream >> date;

      if (is_format_correct(date)) {
        if (is_date_correct(date)) {
          db.Find(date);
        } else {
          continue;
        }
      } else {
        cout << "Wrong date format: " << date << '\n';
        continue;
      }
    } else if (query == "Print") {

      db.Print();

    } else {
      if (!query.empty()) {

        stringstream stream(command);
        string errc;
        stream >> errc;
        cout << "Unknown command: " << errc << '\n';
      }
    }
  }
}

int
main()
{
  programm();
  return 0;
}