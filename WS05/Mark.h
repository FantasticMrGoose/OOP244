#ifndef SDDS_MARK_H
#define SDDS_MARK_H
#include <iostream>
namespace sdds
{
    class Mark
    {
        int m_mark;
        bool m_valid;
        void setInvalid();
        bool isValidEntry(int mark);
    public:
        Mark();
        Mark(int mark);
        operator int() const;
        Mark& operator+=(int value);
        Mark& operator=(int value);
        operator double() const;
        operator char() const;
        operator bool() const;
    };
    int operator+=(int& value, const Mark& m);
}

#endif // !SDDS_MARK_H
