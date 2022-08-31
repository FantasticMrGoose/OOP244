#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "employees.h"
using namespace std;
namespace sdds
{
	Doctor::Doctor(int id, const char* spec)
	{
		if (spec != nullptr && id > 0)
		{
			int m_empID = id;
			m_specialization = new char[strlen(spec) + 1];
			strcpy(m_specialization, spec);
		}
	}

	Doctor& Doctor::operator=(const Doctor& rh)
	{
		if (this != &rh && rh.m_specialization != nullptr)
		{
			delete[] m_specialization;
			m_specialization = new char[strlen(rh.m_specialization) + 1];
			strcpy(m_specialization, rh.m_specialization);
			this->m_empID = rh.m_empID;
		}
		return *this;
	}

	void Doctor::setData()
	{
		char spec[101];
		int id;
		cout << "Specialization: ";
		cin.getline(spec, 100, '\n');
		cout << "ID: ";
		cin >> m_empID;
		if (m_specialization != nullptr)
		{
			delete[] m_specialization;
		}
		m_specialization = new char[strlen(spec) + 1];
		strcpy(m_specialization, spec);
	}

	void Doctor::displayData() const
	{
		cout << m_empID << endl;
		cout << m_specialization << endl;
	}

	Doctor::~Doctor()
	{
		delete[] m_specialization;
	}

}