#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include "TextFile.h"
#include "cstring.h"
using namespace std;
namespace sdds {
   Line::operator const char* () const {
      return (const char*)m_value;
   }

   Line& Line::operator=(const char* lineValue) {
      delete[] m_value;
      m_value = new char[strLen(lineValue) + 1];
      strCpy(m_value, lineValue);
      return *this;
   }

   Line::~Line() {
      delete[] m_value;
   }

   void TextFile::setFilename(const char* fname, bool isCopy)
   {
       if (isCopy)
       {
           m_filename = new char[strLen(fname) + 3];
           strCpy(m_filename, "C_");
           strCat(m_filename, fname);
       }
       else
       {
           m_filename = new char[strLen(fname) + 1];
           strCpy(m_filename, fname);
       }
       return;
   }

   void TextFile::setNoOfLines()
   {
       int numLines = 0;
       char ch;
       ifstream inFile(m_filename);
       if (inFile.is_open())
       {
           while (inFile.get(ch))
           {
               if (ch == '\n')
                   numLines++;
           }
       }
       if (numLines > 0)
       {
           numLines++;
           m_noOfLines = numLines;
       }
       else
       {
           setEmpty();
       }
       return;
   }

   void TextFile::loadText()
   {
       if (m_filename != nullptr)
       {
           int i = 0, numLines = 0;
           string line;
           delete[]  m_textLines;
           m_textLines = new Line[m_noOfLines];
           ifstream inFile(m_filename);
           if (inFile.is_open())
           {
               m_noOfLines = 0;
               while (std::getline(inFile, line, '\n'))
               {
                   m_textLines[i] = line.c_str();
                   i++;
                   numLines++;
               }
               m_noOfLines = numLines;
           }
       }
       return;
   }

   void TextFile::saveAs(const char* fileName) const
   {
       ofstream outFile(fileName);
       if (outFile.is_open())
       {
           for (int i = 0; i < (int)m_noOfLines; i++)
           {
               outFile << m_textLines[i] << endl;
           }
       }  
       return;
   }

   void TextFile::setEmpty()
   {
       delete[] m_textLines;
       m_textLines = nullptr;
       delete[] m_filename;
       m_filename = nullptr;
       m_noOfLines = 0;
   }

   TextFile::TextFile(unsigned pageSize)
   {
       setEmpty();
       m_pageSize = pageSize;
   }

   TextFile::TextFile(const char* filename, unsigned pageSize)
   {
       setEmpty();
       m_pageSize = pageSize;
       if (filename != nullptr)
       {
           setFilename(filename);
           setNoOfLines();
           loadText();
       }
   }

   TextFile::TextFile(const TextFile& rh)
   {
       this->m_pageSize = rh.m_pageSize;
       this->setEmpty();
       if (rh.m_textLines != m_textLines && rh.m_filename != nullptr)
       {           
           this->setFilename(rh.m_filename, true);
           rh.saveAs(this->m_filename);
           this->setNoOfLines();
           this->loadText();
       }
   }

   TextFile& TextFile::operator=(const TextFile& rh)
   {
       if (this != &rh && *this)
       {
           delete[] this->m_textLines;
           this->m_textLines = nullptr;
           rh.saveAs(this->m_filename);
           this->setNoOfLines();
           this->loadText();
       }
       return *this;
   }

   TextFile::~TextFile()
   {
       delete[] m_textLines;
       delete[] m_filename;
   }

   std::ostream& TextFile::view(std::ostream& ostr) const
   {
       if (m_noOfLines > 0)
       {
           ostr << m_filename << endl;
           for (int i = 0; i < strLen(m_filename); i++)
           {
               ostr << "=";
           }
           ostr << endl;
           for (int i = 1; i < (int)m_noOfLines + 1; i++)
           {
               ostr << m_textLines[i - 1] << endl;
               if (i % (m_pageSize) == 0)
               {
                   ostr << "Hit ENTER to continue...";
                   cin.get();
               }               
           }
       }
       return ostr;
   }

   std::istream& TextFile::getFile(std::istream& istr)
   {
       string filename;
       char* inFile = nullptr;
       istr >> filename;
       cin.ignore();
       inFile = new char[filename.length() + 1];
       strCpy(inFile, filename.c_str());
       setFilename(inFile);
       setNoOfLines();
       loadText();
       delete[] inFile;
       return istr;
   }

   TextFile::operator bool() const
   {
       bool state;
       if (m_textLines != nullptr && m_filename != nullptr 
           && m_noOfLines > 0)
       {
           state = true;
       }
       else
       {
           state = false;
       }
       return state;
   }

   unsigned TextFile::lines() const
   {
       return m_noOfLines;
   }

   const char* TextFile::name() const
   {
       return m_filename;
   }

   const char* TextFile::operator[](unsigned index) const
   {
       const char* a = m_textLines[index % (m_noOfLines)];
       const char* b = nullptr;
       return *this ? a : b;
   }

   std::ostream& operator<<(std::ostream& ostr, const TextFile& text)
   {
       text.view(ostr);
       return ostr;
   }

   std::istream& operator>>(std::istream& istr, TextFile& text)
   {
       text.getFile(istr);
       return istr;
   }
}