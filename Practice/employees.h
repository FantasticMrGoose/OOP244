#ifndef EMPLOYEES_H_
#define EMPLOYEES_H_
#include <iostream>
namespace sdds
{
	class Employee
	{
	public:
		virtual void setData() = 0;
		virtual void displayData() const = 0;
	};

	class Doctor : public Employee
	{
		char* m_specialization = nullptr;
		int m_empID;
	public:
		Doctor(int id, const char* spec);
		Doctor(const Doctor& doc) = delete;
		Doctor& operator=(const Doctor&);
		void setData();
		void displayData() const;
		~Doctor();
	};
}

#endif // !EMPLOYEES_H_
