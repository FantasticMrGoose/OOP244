#include "Patient.h"
#include "utils.h"

#define MAX_NAME_LEN 25
#define OHIP_MIN 100000000
#define OHIP_MAX 999999999

namespace sdds
{
	Patient::Patient()
	{
		m_patientName = nullptr;
		m_fileIO = false;
	}

	Patient::Patient(int ticket = 0, bool fileIO) : m_ticket (ticket)
	{
		m_fileIO = fileIO;
	}

	Patient::~Patient()
	{
		delete[] m_patientName;
		m_patientName = nullptr;
	}

	bool Patient::fileIO() const
	{
		return m_fileIO;
	}

	const Patient& Patient::fileIO(bool setFileIO)
	{
		m_fileIO = setFileIO;
		return *this;
	}

	bool Patient::operator==(char rh) const
	{
		return (this->type() == rh);
	}

	bool Patient::operator==(const Patient& rh) const
	{
		return (this->type() == rh.type());
	}

	Patient& Patient::setArrivalTime()
	{
		m_ticket.resetTime();
		return *this;
	}

	Patient::operator Time() const
	{
		return Time(m_ticket);
	}

	int Patient::number() const
	{
		return m_ticket.number();
	}

	std::ostream& Patient::csvWrite(std::ostream& ostr) const
	{
		ostr << this->type() << "," << m_patientName << ","
			<< m_ohip << ",";
		m_ticket.csvWrite(ostr);
		return ostr;
	}

	std::istream& Patient::csvRead(std::istream& istr)
	{
		delete[] m_patientName;
		m_patientName = getcstr(nullptr, istr, ',');
		istr >> m_ohip;
		istr.ignore();
		m_ticket.csvRead(istr);
		return istr;
	}

	std::ostream& Patient::write(std::ostream& ostr) const
	{
		
		ostr << m_ticket << std::endl;
		for (int i = 0; i < MAX_NAME_LEN && m_patientName[i] != '\0'; i++)
		{
			ostr << m_patientName[i];
		}
		ostr << ", OHIP: " << m_ohip;
		return ostr;
	}

	std::istream& Patient::read(std::istream& istr)
	{
		std::cout << "Name: ";

		delete[] m_patientName;
		m_patientName = getcstr(nullptr, istr, '\n');
			
		std::cout << "OHIP: ";
		m_ohip = getInt(OHIP_MIN, OHIP_MAX, nullptr, "Invalid OHIP Number");
		return istr;
	}
}