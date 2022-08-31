#ifndef SDDS_MOTORVEHICLE_H_
#define SDDS_MOTORVEHICLE_H_

namespace sdds
{
	class MotorVehicle
	{
		char m_licensePlate[10] = { '\0' };
		char m_vehLocation[64] = { '\0' };
		int m_yearBuilt;
	public:
		MotorVehicle(const char* plate, int year);
		void moveTo(const char* address);
		std::ostream& write(std::ostream& os) const;
		std::istream& read(std::istream& in);
	};
	std::ostream& operator<<(std::ostream& ostr, const MotorVehicle& veh);
	std::istream& operator>>(std::istream& istr, MotorVehicle& veh);
}
#endif // !SDDS_MOTORVEHICLE_H_
