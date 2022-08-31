#define _CRT_SECURE_NO_WARNINGS
#include "IOAble.h"
using namespace std;
namespace sdds
{
	std::ostream& operator<<(std::ostream& ostr, const IOAble& able)
	{
		able.write(ostr);
		return ostr;
	}
	std::istream& operator>>(std::istream& istr, IOAble& able)
	{
		able.read(istr);
		return istr;
	}
}
