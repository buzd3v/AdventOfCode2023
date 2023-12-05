#include <fstream>
#include <iostream>
#include <map>
#include <sstream>

using namespace std;

bool isDigit(char c) { return '0' <= c && '9' >= c; }

string parseString(string &s) {
  map<string, string> m = {
      {"zero", "z0o"},  {"one", "o1e"},  {"two", "t2o"}, {"three", "t3e"},
      {"four", "f4r"},  {"five", "f5e"}, {"six", "s6x"}, {"seven", "s7n"},
      {"eight", "e8t"}, {"nine", "n9e"},
  };
  for (auto e : m) {
    // find and replace all
    while (s.find(e.first) != string::npos) {
      s.replace(s.find(e.first), e.first.size(), e.second);
    }
  }
  return s;
}

int findNumber(const std::string &str) {

  string sres;
  for (auto itr = str.begin(); itr != str.end(); itr++) {
    if (isDigit(*itr)) {
      sres += (*itr);
      break;
    }
  }
  for (auto itr = str.rbegin(); itr != str.rend(); itr++) {
    if (isDigit(*itr)) {
      sres += (*itr);
      break;
    }
  }

  return std::stoi(sres);
}

int main() {
  std::ifstream file("../../input.txt");
  if (!file.is_open()) {
    cout << "File not found" << endl;
  }
  string s;
  int res = 0;
  int number;
  while (file >> s) {
    parseString(s);
    number = findNumber(s);
    res += number;
  }
  file.close();
  std::cout << res << endl;
  return 0;
}