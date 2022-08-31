#include <iostream>
#include "MotorVehicle.h"
#include "Truck.h"
using namespace std;
namespace sdds
{
    bool Truck::withinCapacity(double cargo)
    {
        return ((cargo + m_currentLoad) <= m_capacity);
    }
    Truck::Truck(const char* plate, int year, double capacity,
        const char* address) :MotorVehicle(plate, year)
    {
        m_capacity = capacity;
        m_currentLoad = 0;
        MotorVehicle::moveTo(address);
    }
    bool Truck::addCargo(double cargo)
    {
        bool is_loaded = false;
        if (withinCapacity(cargo))
        {
            m_currentLoad += cargo;
            is_loaded = true;
        }
        else if (m_currentLoad < m_capacity)
        {
            m_currentLoad = m_capacity;
            is_loaded = true;
        }
        return is_loaded;
    }

    bool Truck::unloadCargo()
    {
        bool is_unloaded = false;
        if (m_currentLoad > 0)
        {
            m_currentLoad = 0;
            is_unloaded = true;
        }
        return is_unloaded;
    }
    std::ostream& Truck::write(std::ostream& os) const
    {
        MotorVehicle::write(os);
        os << " | ";
        os.setf(ios::fixed);
        os.precision(0);
        os << m_currentLoad << "/" << m_capacity;
        return os;
    }
    std::istream& Truck::read(std::istream& in)
    {
        MotorVehicle::read(in);
        cout << "Capacity: ";
        in >> m_capacity;
        cout << "Cargo: ";
        in >> m_currentLoad;
        return in;
    }


    std::ostream& operator<<(std::ostream& ostr, const Truck& Truck)
    {
        Truck.write(ostr);
        return ostr;
    }

    std::istream& operator>>(std::istream& istr, Truck& Truck)
    {
        Truck.read(istr);
        return istr;
    }

}