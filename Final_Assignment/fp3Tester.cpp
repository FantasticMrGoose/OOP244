// Final Project Tester
// file: fp3Tester.cpp
// Version: 1.0
// Date: 2021-06-23
// Author: Fardad
// Description:
// This file tests the Final project with
// records more than the capcity of PriTirage
/////////////////////////////////////////////
#include <iostream>
#include <fstream>
#include "PreTriage.h"
#include "utils.h"

using namespace sdds;
using namespace std;

void displayFile(const char* fname) {
   ifstream fin(fname);
   char ch;
   cout << endl << "******  Content of file: \"" << fname << "\":" << endl;
   while (fin.get(ch)) cout << ch;
   cout << "***************************************************" << endl << endl;
}
void copyFile(const char* des, const char* src) {
   ifstream s(src);
   ofstream d(des);
   char ch = 0;
   while (s.get(ch) && d << ch);
}

int main() {
   sdds::debug = true;
   copyFile("bigdata.csv", "bigdata.csv.bak");
   PreTriage P("bigdata.csv");
   P.run();
   return 0;
}

