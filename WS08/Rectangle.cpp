#include <string>
#include <cstring>
#include "Rectangle.h"
namespace sdds
{
    Rectangle::Rectangle() :LblShape()
    {
        m_width = 0;
        m_height = 0;
    }

    Rectangle::Rectangle(const char* label, int width, int height) 
        :LblShape(label)
    {
        m_width = width;
        m_height = height;
    }
    void Rectangle::getSpecs(std::istream& istr)
    {
        LblShape::getSpecs(istr);
        char comma;
        istr >> m_width >> comma >> m_height;
        istr.ignore(10000, '\n');
        return;
    }

    void Rectangle::draw(std::ostream& ostr) const
    {
        if ((m_width - 2) > 0 && (m_height - 2)> 0)
        {
            ostr << "+";
            for (int i = 0; i < (m_width - 2); i++)
            {
                ostr << "-";
            }
            ostr << "+" << std::endl;
            ostr << "|";
            ostr.width(m_width - 2);
            ostr.setf(std::ios::left);
            ostr << LblShape::label();
            ostr << "|" << std::endl;

            for (int i = 0; i < (m_height - 3); i++)
            {
                ostr << "|";
                for (int j = 0; j < (m_width - 2); j++)
                {
                    ostr << " ";
                }
                ostr << "|" << std::endl;
            }

            ostr << "+";
            for (int i = 0; i < (m_width - 2); i++)
            {
                ostr << "-";
            }
            ostr << "+";
        }
        return;
    }
}