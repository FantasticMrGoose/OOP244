#include <iostream>
#include "MotorVehicle.h"
#include "cstring.h"
using namespace std;
namespace sdds
{
    MotorVehicle::MotorVehicle(const char* plate, int year)
    {
        strCpy(m_vehLocation, "Factory");
        if (plate != nullptr && year > 0)
        {
            strCpy(m_licensePlate, plate);
            m_yearBuilt = year;
        }
    }

    void MotorVehicle::moveTo(const char* address)
    {
        if (strCmp(address, m_vehLocation) != 0)
        {
            cout << "|";
            cout.setf(ios::right);
            cout.width(8); 
            cout << m_licensePlate << "| |";
            cout.width(20);
            cout << m_vehLocation;
            cout << " ---> ";
            cout.width(20);
            cout.unsetf(ios::right);
            cout.setf(ios::left);
            cout << address << "|" << endl;
            strCpy(m_vehLocation, address);
        }
        return;
    }

    std::ostream& MotorVehicle::write(std::ostream& os) const
    {
        os << "| " << m_yearBuilt << " | " << m_licensePlate << " | "
            << m_vehLocation;
        return os;
    }

    std::istream& MotorVehicle::read(std::istream& in)
    {
        cout << "Built year: ";
        in >> m_yearBuilt;
        in.ignore(10000, '\n');
        in.clear();
        cout << "License plate: ";
        in.getline(m_licensePlate, 9, '\n');
        cout << "Current location: ";
        in.getline(m_vehLocation, 63, '\n');
        return in;
    }
    std::ostream& operator<<(std::ostream& ostr, const MotorVehicle& veh)
    {
        veh.write(ostr);
        return ostr;
    }
    std::istream& operator>>(std::istream& istr, MotorVehicle& veh)
    {
        veh.read(istr);
        return istr;
    }
}