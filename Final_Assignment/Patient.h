#ifndef SDDS_PATIENT_H_
#define SDDS_PATIENT_H_
#include "IOAble.h"
#include "Ticket.h"
namespace sdds
{
	class Patient:public IOAble
	{
		char* m_patientName = nullptr;
		int m_ohip = -1;
		Ticket m_ticket = 0;
		bool m_fileIO;
	public:
		Patient();
		Patient(int ticket, bool fileIO = false);
		~Patient();
		//copy constructor and assignment prohibit
		Patient(const Patient&) = delete;
		Patient& operator=(const Patient&) = delete;
		virtual char type()const = 0;
		bool fileIO() const;
		const Patient& fileIO(bool setFileIO);
		bool operator==(char rh) const;
		bool operator==(const Patient&) const;
		Patient& setArrivalTime();
		operator Time ()const;
		int number() const;
		std::ostream& csvWrite(std::ostream& ostr)const;
		std::istream& csvRead(std::istream& istr);
		std::ostream& write(std::ostream& ostr)const;
		std::istream& read(std::istream& istr);
	};
}
#endif