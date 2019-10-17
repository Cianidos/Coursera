#include <algorithm>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;
struct Date
{
  int year, month, day;
  Date()
  {
    year = 0;
    month = 0;
    day = 0;
  }
  Date(string datestr)
  {
    if (!datestr.empty()) {
      char dash1, dash2;
      if ((datestr[0] < '0' || datestr[0] > '9') &&
          (datestr[0] != '-' && datestr[0] != '+'))
        throw invalid_argument("Wrong date format: " + datestr);
      istringstream ss(datestr);
      ss >> year;
      if (ss.eof())
        throw invalid_argument("Wrong date format: " + datestr);
      ss >> dash1;
      if (ss.eof())
        throw invalid_argument("Wrong date format: " + datestr);
      istringstream::pos_type monthbegin = ss.tellg();
      ss >> month;
      if (ss.eof())
        throw invalid_argument("Wrong date format: " + datestr);
      istringstream::pos_type monthend = ss.tellg();
      ss >> dash2;
      if (ss.eof())
        throw invalid_argument("Wrong date format: " + datestr);
      if (ss.tellg() == datestr.length())
        throw invalid_argument("Wrong date format: " + datestr);
      istringstream::pos_type daybegin = ss.tellg();
      ss >> day;
      if (!ss.eof())
        throw invalid_argument("Wrong date format: " + datestr);
      if (dash1 != '-' || dash2 != '-')
        throw invalid_argument("Wrong date format: " + datestr);
      if (month < 1 || month > 12) {
        string serr = datestr.substr(monthbegin, monthend - monthbegin);
        // ostringstream serr;
        // serr << month;
        throw invalid_argument("Month value is invalid: " + serr);
      }

      if (day < 1 || day > 31) {
        string serr = datestr.substr(daybegin);
        // ostringstream serr;
        // serr << day;
        throw invalid_argument("Day value is invalid: " + serr);
      }
    } else {
      year = 0;
      month = 0;
      day = 0;
    }
  }

  bool isSet() { return year != 0 || month != 0 || day != 0; }

  string ToString() const
  {
    ostringstream ss;
    ss << year << "-" << month << "-" << day;
    return ss.str();
  }
  int julianDay() const { return year * 365 + month * 30 + day; }
};


class DataBase
{
  map<Date, set<string>> _events;

public:
  DataBase() {}

public:
  void Add(Date date, string event) { _events[date].insert(event); }
  void Del(Date date, string event, ostream& cout)
  {
    if (!event.empty()) {
      if (_events[date].count(event) == 0)
        throw invalid_argument(
          "Event not found"); // '" + event + "' at date" + date.ToString());
      _events[date].erase(event);
      if (_events[date].size() == 0)
        _events.erase(date);
      cout << "Deleted successfully" << endl;
    } else { // remove all event for the date -> remvoe the date
      cout << "Deleted " << _events[date].size() << " events" << endl;
      _events.erase(date);
    }
  }
  void Find(Date date, ostream& cout)
  {
    bool isFirst = true;
    for (auto e : _events[date]) {
      if (isFirst)
        isFirst = false;
      else
        cout << " ";
      cout << e;
    }
    if (!isFirst)
      cout << endl;
  }

  void Print(ostream& out)
  {
    for (auto day : _events) {
      for (auto event : day.second) {
        out << setfill('0') << setw(4) << day.first.year << "-" << setw(2)
            << day.first.month << "-" << setw(2) << day.first.day;
        out << " " << event << endl;
      }
    }
  }

public:
};

struct Command
{
  string command;
  Date date;
  string event;
  Command(string commandline) { parseCommand(commandline); }
  void parseCommand(string commandline)
  {
    size_t command_delimiter = commandline.find(' ');
    if (command_delimiter != string::npos) {
      command = commandline.substr(0, command_delimiter);
      string origcommand = command;
      transform(command.begin(), command.end(), command.begin(), ::toupper);
      if (command != "ADD" && command != "DEL" && command != "FIND" &&
          command != "PRINT")
        throw invalid_argument("Unknown command: " + origcommand);

      string datedata = commandline.substr(command_delimiter + 1);
      string datestr;
      size_t date_delimiter = datedata.find(' ');
      if (date_delimiter == string::npos) {
        datestr = datedata;
      } else {
        datestr = datedata.substr(0, date_delimiter);
        event = datedata.substr(date_delimiter + 1);
      }
      date = Date(datestr);
    } else {
      command = commandline;
      transform(command.begin(), command.end(), command.begin(), ::toupper);
    }
  }
};

bool
processCommand(const Command& command, DataBase& db, ostream& cout)
{
  if (command.command == "ADD")
    db.Add(command.date, command.event);
  else if (command.command == "DEL")
    db.Del(command.date, command.event, cout);
  else if (command.command == "FIND")
    db.Find(command.date, cout);
  else if (command.command == "PRINT")
    db.Print(cout);
  else
    throw invalid_argument("Unknown command: " + command.command);
  return true;
}
// < operator for Date structure:
bool
operator<(const Date& l, const Date& r)
{
  return l.julianDay() < r.julianDay();
}
void
Program(istream& cin, ostream& cout)
{
  DataBase db;
  while (!cin.eof()) {
    string commandline;
    getline(cin, commandline);
    if (commandline.empty()) {
      continue;
    }
    try {
      Command command = Command(commandline);
      processCommand(command, db, cout);
    } catch (invalid_argument& e) {
      cout << e.what() << endl;
    }
  }
}

int
main(int argc, const char* argv[])
{
  Program(cin, cout);
  return 0;
}