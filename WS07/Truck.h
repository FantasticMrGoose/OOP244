#ifndef SDDS_TRUCK_H_
#define SDDS_TRUCK_H_
#include "MotorVehicle.h"
namespace sdds
{
	class Truck : public MotorVehicle
	{
		double m_capacity;
		double m_currentLoad;
		bool withinCapacity(double cargo);
	public:
        Truck(const char* plate, int year, double capacity,
            const char* address);
        bool addCargo(double cargo);
        bool unloadCargo();
        std::ostream& write(std::ostream& os) const;
        std::istream& read(std::istream& in);
	};

    std::ostream& operator<<(std::ostream& ostr, const Truck& Truck);
    std::istream& operator>>(std::istream& istr, Truck& Truck);

}
#endif // !SDDS_TRUCK_H_
