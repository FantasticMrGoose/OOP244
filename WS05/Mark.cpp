#define _CRT_SECURE_NO_WARNINGS
#include "Mark.h"

namespace sdds
{
    void Mark::setInvalid()
    {
        m_mark = 0;
        m_valid = false;
    }

    bool Mark::isValidEntry(int mark)
    {
        return(mark >= 0 && mark <= 100);
    }

    Mark::Mark()
    {
        setInvalid();
        m_valid = true;
    }

    Mark::Mark(int mark)
    {
        setInvalid();
        if (isValidEntry(mark)) {
            m_mark = mark;
            m_valid = true;
        }
    }

    Mark::operator int() const
    {
        return m_mark;
    }

    Mark& Mark::operator+=(int value)
    {
        if (m_valid)
        {
            m_mark += value;
            if (!isValidEntry(m_mark)) //ensure m_mark does not go over 100
            {
                setInvalid();
            }       
        }        
        return *this;
    }

    Mark& Mark::operator=(int value)
    {
        if (isValidEntry(value))
        {
            m_mark = value;
            m_valid = true;
        }
        else
        {
            setInvalid();
        }
        return *this;
    }

    Mark::operator double() const
    {
        double gpa = 0;
        if (m_mark < 50 || !m_valid)
        {
            gpa = 0;
        }
        else if (m_mark >= 50 && m_mark < 60)
        {
            gpa = 1;
        }
        else if (m_mark >= 60 && m_mark < 70)
        {
            gpa = 2;
        }
        else if (m_mark >= 70 && m_mark < 80)
        {
            gpa = 3;
        }
        else if (m_mark >= 80)
        {
            gpa = 4;
        }
        return gpa;
    }

    Mark::operator char() const
    {
        char letterGrade = 'X';
        if (!m_valid)
        {
            letterGrade = 'X';
        }
        else if (m_mark < 50)
        {
            letterGrade = 'F';
        }
        else if (m_mark >= 50 && m_mark < 60)
        {
            letterGrade = 'D';
        }
        else if (m_mark >= 60 && m_mark < 70)
        {
            letterGrade = 'C';
        }
        else if (m_mark >= 70 && m_mark < 80)
        {
            letterGrade = 'B';
        }
        else if (m_mark >= 80)
        {
            letterGrade = 'A';
        }
        return letterGrade;
    }

    Mark::operator bool() const
    {
        return m_valid;
    }

    int operator+=(int& value, const Mark& m)
    {
        if (bool(m))
        {
            value += int(m);
        }
        return value;
    }
}