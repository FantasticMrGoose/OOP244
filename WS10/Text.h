#ifndef SDDS_TEXT_H__
#define SDDS_TEXT_H__
#include <iostream>
namespace sdds {
   class Text {
      char* m_filename{} ;
      char* m_content{} ;
      int getFileLength()const;
   protected:
      const char& operator[](int index)const;
   public:
      Text(const char* filename = nullptr);
      Text(const Text& text);
      Text& operator=(const Text&);
      ~Text();
      virtual void read();
      virtual void write(std::ostream& os)const;
   };
   std::ostream& operator<<(std::ostream& ostr, const Text&);
}
#endif // !SDDS_PERSON_H__

