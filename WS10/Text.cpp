#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <cstring>
#include <cstring>
#include "Text.h"
using namespace std;
namespace sdds {

   int Text::getFileLength() const {
      int len = 0;
      ifstream fin(m_filename);
      while (fin) {
         fin.get();
         len += !!fin;
      }
      return len;
   }

   const char& Text::operator[](int index) const
   {
       return m_content[index];
   }

   Text::Text(const char* filename)
   {
       if (filename != nullptr)
       {
           m_filename = new char[strlen(filename) + 1];
           strcpy(m_filename, filename);
           read();
       }
   }

   Text::Text(const Text& text)
   {
       if (text.m_filename && text.m_content) {
           delete[] m_filename;
           delete[] m_content;
           m_filename = nullptr;
           m_content = nullptr;
           m_filename = new char[strlen(text.m_filename) + 1];
           m_content = new char[strlen(text.m_content) + 1];
           strcpy(m_filename, text.m_filename);
           strcpy(m_content, text.m_content);
       }
   }

   Text& Text::operator=(const Text& rh)
   {
       if (this != &rh && rh.m_content != nullptr)
       {
           delete[] m_filename;
           delete[] m_content;
           m_filename = new char[strlen(rh.m_filename) + 1];
           strcpy(m_filename, rh.m_filename);
           m_content = new char[strlen(rh.m_content) + 1];
           strcpy(m_content, rh.m_content);
       }
       return *this;
   }

   Text::~Text()
   {
       delete[] m_filename;
       delete[] m_content;
   }

   void Text::read()
   {
       if (m_filename != nullptr)
       {
           int i = 0;
           m_content = new char[getFileLength() + 1];
           ifstream fin(m_filename);
           while (fin)
           {
               m_content[i] = fin.get();
               i++;
           }
           m_content[getFileLength()] = '\0';
       }
   }

   void Text::write(std::ostream& os) const
   {
       if (m_content != nullptr)
       {
           os << m_content;
       }
   }

   std::ostream& operator<<(std::ostream& ostr, const Text& text)
   {
       text.write(ostr);
       return ostr;
   }

}