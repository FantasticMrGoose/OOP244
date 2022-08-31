#ifndef SDDS_LBLSHAPE_H
#define SDDS_LBLSHAPE_H
#include "Shape.h"

namespace sdds
{
	class LblShape : public Shape
	{
        char* m_label = nullptr;
    protected:
        char* label() const;
	public:
        LblShape();
        LblShape(const char* label);
        ~LblShape();
        LblShape(const LblShape&) = delete;
        LblShape& operator=(const LblShape&) = delete;
        void getSpecs(std::istream& istr);
        virtual void draw(std::ostream& ostr) const = 0;
	};
}

#endif