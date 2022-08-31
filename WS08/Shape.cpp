#include "Shape.h"

namespace sdds
{
    std::ostream& operator<<(std::ostream& ostr, const Shape& shp)
    {
        shp.draw(ostr);
        return ostr;
    }
    std::istream& operator>>(std::istream& istr, Shape& shp)
    {
        shp.getSpecs(istr);
        return istr;
    }
}