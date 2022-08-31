#include <string>
#include <cstring>
#include "Line.h"
namespace sdds
{
    Line::Line() :LblShape()
    {
        m_length = 0;
    }

    Line::Line(const char* label, int length) :LblShape(label)
    {
        m_length = length;
    }

    void Line::getSpecs(std::istream& istr)
    {
        LblShape::getSpecs(istr);
        istr >> m_length;
        istr.ignore(10000, '\n');
        return;
    }

    void Line::draw(std::ostream& ostr) const
    {
        if (m_length > 0 && LblShape::label() != nullptr)
        {
            ostr << LblShape::label() << std::endl;
            for (int i = 0; i < m_length; i++)
            {
                ostr << "=";
            }
        }

        return;
    }


}
