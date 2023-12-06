#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>

using namespace std;

const int RED_CUBE = 12;
const int GREEN_CUBE = 13;
const int BLUE_CUBE = 14;

bool isValid(std::string &s) {

  string toReplace = ",";
  string toReplacez = ";";
  string temp = " ";
  while (s.find(toReplace) != string::npos) {
    s.replace(s.find(toReplace), toReplace.size(), temp);
  }

  while (s.find(toReplacez) != string::npos) {
    s.replace(s.find(toReplacez), toReplacez.size(), temp);
  }

  stringstream ss(s);
  int number;
  string type;
  ss >> type >> type;

  while (ss >> number >> type) {
    if (type == "red") {
      if (number > RED_CUBE)
        return false;
    } else if (type == "blue") {
      if (number > BLUE_CUBE)
        return false;
    } else if (type == "green") {
      if (number > GREEN_CUBE)
        return false;
    }
  }
  return true;
}

int powerOfSet(std::string &s) {

  string toReplace = ",";
  string toReplacez = ";";
  string temp = " ";
  while (s.find(toReplace) != string::npos) {
    s.replace(s.find(toReplace), toReplace.size(), temp);
  }

  while (s.find(toReplacez) != string::npos) {
    s.replace(s.find(toReplacez), toReplacez.size(), temp);
  }

  stringstream ss(s);
  int number;
  string type;

  int maxRed = 0;
  int maxBlue = 0;
  int maxGreen = 0;

  // ignore "Game 1:" and so on
  ss >> type >> type;

  // parsing
  while (ss >> number >> type) {
    if (type == "red") {
      if (maxRed < number)
        maxRed = number;
    } else if (type == "blue") {
      if (number > maxBlue)
        maxBlue = number;
    } else if (type == "green") {
      if (number > maxGreen)
        maxGreen = number;
    }
  }
  return maxBlue * maxGreen * maxRed;
}

int main() {
  std::ifstream file("../../day2.txt");
  if (!file.is_open()) {
    cout << "File not found" << endl;
  }
  string s;
  int res = 0;
  int count = 1;
  // part 1
  //   while (!file.eof()) {
  //     std::getline(file, s);
  //     if (isValid(s)) {
  //       res += count;
  //     }
  //     count++;
  //   }

  // part 2
  while (!file.eof()) {
    std::getline(file, s);
    res += powerOfSet(s);
  }
  file.close();
  std::cout << res << endl;
  return 0;
}