#ifndef SDDS_RECTANGLE_H_
#define SDDS_RECTANGLE_H_
#include "LblShape.h"
namespace sdds
{
	class Rectangle : public LblShape
	{
		int m_width;
		int m_height;
	public:
		Rectangle();
		Rectangle(const char* label, int m_width, int m_height);
        void getSpecs(std::istream& istr);
        void draw(std::ostream& ostr) const;
	};

}

#endif // !SDDS_RECTANGLE_H_


