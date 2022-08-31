#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>
#include "utils.h"
#include "Time.h"
using namespace std;
namespace sdds {
   bool debug = false;  
   int getTime() {  
      int mins = -1;
      if (debug) {
         Time t(0);
         cout << "Enter current time: ";
         do {
            cin.clear();
            cin >> t;   // needs extraction operator overloaded for Time
            if (!cin) {
               cout << "Invalid time, try agian (HH:MM): ";
               cin.clear();
            }
            else {
               mins = int(t);
            }
            cin.ignore(1000, '\n');
         } while (mins < 0);
      }
      else {
         time_t t = time(NULL);
         tm lt = *localtime(&t);
         mins = lt.tm_hour * 60 + lt.tm_min;
      }
      return mins;
   }

   int getInt(const char* prompt)
   {
       int i, retry = 0;
       if (prompt != nullptr)
       {
           cout << prompt;
       }
       do
       {
           cin >> i;
           if (cin.fail())
           {
               cerr << "Bad integer value, try again: ";
               cin.clear();
               cin.ignore(1000, '\n');
               retry = 1;
           }
           else if (char(cin.get()) != '\n') 
           {
               cerr << "Enter only an integer, try again: ";
               cin.clear();
               cin.ignore(2000, '\n');
               retry = 1;
           }
           else
           {
               retry = 0;
           }
       } while (retry == 1);
       return i;
   }

   int getInt(int min, int max, const char* prompt, const char* errorMessage, 
       bool showRangeAtError)
   {
       int i, retry = 0;
       i = getInt(prompt);
       do
       {      
           if (i < min || i > max)
           {
               if (errorMessage != nullptr)
               {
                   cerr << errorMessage;
               }
               if (showRangeAtError)
               {
                   cerr <<", " << "[" << min << " <= value <= " 
                       << max <<"]" << ": ";
               }       
               retry = 1;
               i = getInt();
           }
           else
           {
               retry = 0;
           }
       } while (retry == 1);
       return i;
   }

   char* getcstr(const char* prompt, std::istream& istr, char delimiter)
   {
       char* dma_string = nullptr;
       string message;
       if (prompt != nullptr)
       {
           cout << prompt;
       }
       getline(istr, message, delimiter);
       dma_string = new char[message.length() + 1];
       strcpy(dma_string, message.c_str());
       return dma_string;
   }

   char* dmaString(const char* src)
   {
       char* dma_string = nullptr;
       dma_string = new char[strlen(src) + 1];
       strcpy(dma_string, src);
       return dma_string;
   }
}