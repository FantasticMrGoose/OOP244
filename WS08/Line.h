#include "LblShape.h"
#ifndef SDDS_LINE_H_
#define SDDS_LINE_H_
namespace sdds
{
	class Line : public LblShape
	{
        int m_length;
	public:
        Line();
        Line(const char* label, int length);
        void getSpecs(std::istream& istr);
        void draw(std::ostream& ostr) const;
	};

}

#endif // !SDDS_LINE_H_
