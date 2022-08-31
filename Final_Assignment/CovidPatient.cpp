#include "CovidPatient.h"
namespace sdds {
   int nextCovidTicket = 1;

   CovidPatient::CovidPatient() : Patient(nextCovidTicket)
   {
	   nextCovidTicket++;
   }

   char CovidPatient::type() const
   {
	   return 'C';
   }

   std::istream& CovidPatient::csvRead(std::istream& istr)
   {
	   Patient::csvRead(istr);
	   nextCovidTicket = Patient::number() + 1;
	   istr.ignore();
	   return istr;
   }

   std::ostream& CovidPatient::write(std::ostream& ostr) const
   {
	   if (Patient::fileIO())
	   {
		   Patient::csvWrite(ostr);
	   }
	   else
	   {
		   ostr << "COVID TEST" << std::endl;
		   Patient::write(ostr) << std::endl;
	   }
	   return ostr;
   }

   std::istream& CovidPatient::read(std::istream& istr)
   {
	   if (Patient::fileIO())
	   {
		   CovidPatient::csvRead(istr);
	   }
	   else
	   {
		   Patient::read(istr);
	   }
	   return istr;
   }

}