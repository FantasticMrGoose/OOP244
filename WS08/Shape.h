#ifndef SDDS_SHAPE_H_
#define SDDS_SHAPE_H_
#include <iostream>
namespace sdds
{
	class Shape
	{
	public:
		virtual void draw(std::ostream& ostr) const = 0;
		virtual void getSpecs(std::istream& istr) = 0;
        virtual ~Shape() {};
	};
    std::ostream& operator<<(std::ostream& ostr, const Shape&);
    std::istream& operator>>(std::istream& istr, Shape&);
}

#endif // !SDDS_SHAPE_H_
