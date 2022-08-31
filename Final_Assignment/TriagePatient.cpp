#include "TriagePatient.h"
#include "utils.h"
namespace sdds {
   int nextTriageTicket = 1;

   TriagePatient::TriagePatient() : Patient(nextTriageTicket)
   {
	   m_symptoms = nullptr;
	   nextTriageTicket++;
   }

   char TriagePatient::type() const
   {
	   return 'T';
   }

   std::ostream& TriagePatient::csvWrite(std::ostream& ostr) const
   {
	   Patient::csvWrite(ostr);
	   ostr << ',' << m_symptoms;
	   return ostr;
   }

   std::istream& TriagePatient::csvRead(std::istream& istr)
   {
	   delete[] m_symptoms;
	   Patient::csvRead(istr);
	   istr.ignore();
	   m_symptoms = getcstr(nullptr, istr, '\n');
	   nextTriageTicket = Patient::number() + 1;
	   return istr;
   }

   std::ostream& TriagePatient::write(std::ostream& ostr) const
   {
	   if (Patient::fileIO())
	   {
		   TriagePatient::csvWrite(ostr);
	   }
	   else
	   {
		   ostr << "TRIAGE" << std::endl;
		   Patient::write(ostr) << std::endl;
		   ostr << "Symptoms: " << m_symptoms << std::endl;
	   }
	   return ostr;
   }

   std::istream& TriagePatient::read(std::istream& istr)
   {
	   if (Patient::fileIO())
	   {
		   TriagePatient::csvRead(istr);
	   }
	   else
	   {
		   delete[] m_symptoms;
		   Patient::read(istr);
		   m_symptoms = getcstr("Symptoms: ", istr, '\n');
	   }
	   return istr;
   }

   TriagePatient::~TriagePatient()
   {
	   delete[] m_symptoms;
	   m_symptoms = nullptr;
   }
}