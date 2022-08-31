#include "Time.h"
#include "utils.h"
using namespace std;
namespace sdds {
	Time& Time::setToNow()
	{
		this->m_min = getTime();
		return *this;
	}

	Time::Time(unsigned int min)
	{
		m_min = min;
	}

	std::ostream& Time::write(std::ostream& ostr) const
	{
		int hour, minute;
		hour = this->m_min / 60;
		minute = this->m_min % 60;
		ostr.width(2);
		ostr.fill('0');
		ostr << hour << ":";
		ostr.width(2);
		ostr.fill('0');
		ostr << minute;
		return ostr;
	}

	std::istream& Time::read(std::istream& istr)
	{
		int hour = 0, minute = 0;
		char separator = ' ';
		istr >> hour >> separator >> minute;
		if (hour < 0 || separator != ':' || minute < 0)
		{
			istr.setstate(ios::failbit);
		}
		else
		{
			this->m_min = (hour * 60) + minute;
		}
		return istr;
	}

	Time& Time::operator-=(const Time& D)
	{
		if (this->m_min >= D.m_min)
		{
			this->m_min -= D.m_min;
		}
		else
		{
			int minutes_of_day = D.m_min % 1440; //find time of day in minutes
			this->m_min = (this->m_min + 1440) - minutes_of_day;
		}
		return *this;
	}

	Time Time::operator-(const Time& D) const
	{
		Time temp;
		if (this->m_min >= D.m_min)
		{
			temp.m_min = this->m_min - D.m_min;
		}
		else
		{
			int minutes_of_day = D.m_min % 1440;
			temp.m_min = (this->m_min + 1440) - minutes_of_day;
		}
		return temp;
	}
	
	Time& Time::operator+=(const Time& D)
	{
		this->m_min += D.m_min;
		return *this;
	}

	Time Time::operator+(const Time& D) const
	{
		Time temp = this->m_min + D.m_min;
		return temp;
	}

	Time& Time::operator=(unsigned int val)
	{
		this->m_min = val;
		return *this;
	}

	Time& Time::operator*=(unsigned int val)
	{
		this->m_min *= val;
		return *this;
	}

	Time Time::operator*(unsigned int val) const
	{
		Time temp = this->m_min * val;
		return temp;
	}

	Time& Time::operator/=(unsigned int val)
	{
		this->m_min /= val;
		return *this;
	}

	Time Time::operator/(unsigned int val) const
	{
		Time temp = this->m_min / val;
		return temp;
	}

	Time::operator unsigned int() const
	{
		return m_min;
	}

	Time::operator int() const
	{
		int min = m_min;
		return min;
	}

	std::ostream& operator<<(std::ostream& ostr, const Time& D)
	{
		D.write(ostr);
		return ostr;
	}

	std::istream& operator>>(std::istream& istr, Time& D)
	{
		D.read(istr);
		return istr;
	}
}