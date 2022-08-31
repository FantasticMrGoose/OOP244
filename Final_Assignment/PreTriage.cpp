#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include "PreTriage.h"
#include "Time.h"
#include "utils.h"
#include "CovidPatient.h"
#include "TriagePatient.h"
namespace sdds
{
	void PreTriage::reg()
	{
		if (m_lineupSize == maxNoOfPatients)
		{
			std::cout << "Line up full!" << std::endl;
		}
		else
		{
			int selection;
			m_pMenu >> selection;
			if (selection == 1)
			{
				m_lineup[m_lineupSize] = new CovidPatient;
			}
			else if (selection == 2)
			{
				m_lineup[m_lineupSize] = new TriagePatient;
			}
			m_lineup[m_lineupSize]->setArrivalTime();
			std::cout << "Please enter patient information: " << std::endl;
			m_lineup[m_lineupSize]->read(std::cin);
			std::cout << std::endl;
			std::cout << "******************************************" << std::endl;
			m_lineup[m_lineupSize]->write(std::cout) << "Estimated Wait Time: "
				<< getWaitTime(*m_lineup[m_lineupSize]) << std::endl;
			std::cout << "******************************************" << std::endl << std::endl;
			m_lineupSize++;
		}
		return;
	}

	void PreTriage::admit()
	{
		int selection, index = -1;
		m_pMenu >> selection;
		if (selection == 1)
		{
			index = indexOfFirstInLine('C');
		}
		else if (selection == 2)
		{
			index = indexOfFirstInLine('T');
		}
		if (index == -1)
		{
			selection = 0; // exits loop
		}
		else
		{
			std::cout << std::endl;
			std::cout << "******************************************" << std::endl;
			m_lineup[index]->fileIO(false);
			std::cout << "Calling for ";
			m_lineup[index]->write(std::cout) <<
				"******************************************" << std::endl
				<< std::endl;
			setAverageWaitTime(*m_lineup[index]);
			removePatientFromLineup(index);
		}
		return;
	}

	const Time PreTriage::getWaitTime(const Patient& p) const
	{
		unsigned int numMatch = 0;
		int waitTime = 0;
		for (int i = 0; i < m_lineupSize; i++)
		{
			if (m_lineup[i]->type() == p.type()) {
				numMatch++;
			}
		}
		if (p.type() == 'C')
		{
			waitTime = m_averCovidWait * numMatch;
		}
		else if (p.type() == 'T')
		{
			waitTime = m_averTriageWait * numMatch;
		}
		return waitTime;
	}

	void PreTriage::setAverageWaitTime(const Patient& p)
	{
		if (p.type() == 'C')
		{
			m_averCovidWait = ((getTime() - (unsigned int)(Time)p) +
				(unsigned int)(m_averCovidWait) * (p.number() - 1)) / p.number();
		}
		else if (p.type() == 'T')
		{
			m_averTriageWait = ((getTime() - (unsigned int)(Time)p) +
				(unsigned int)(m_averTriageWait) * (p.number() - 1)) / p.number();
		}
		return;
	}

	void PreTriage::removePatientFromLineup(int index)
	{
		removeDynamicElement(m_lineup, index, m_lineupSize);
		return;
	}

	int PreTriage::indexOfFirstInLine(char type) const
	{
		int index = -1, stop = 0;

		for (int i = 0; i < m_lineupSize && stop != 1; i++)
		{
			if (m_lineup[i]->type() == type) {
				index = i;
				stop = 1;
			}
		}
		return index;
	}

	void PreTriage::load()
	{
		Patient* temp;
		char p_type;
		std::cout << "Loading data..." << std::endl;
		if (m_dataFilename != nullptr)
		{
			std::ifstream inFile(m_dataFilename);
			inFile >> m_averCovidWait;
			inFile.ignore();
			inFile >> m_averTriageWait;
			inFile.ignore();
			for (int i = 0; i < maxNoOfPatients && inFile >> p_type; i++)
			{
				inFile.ignore();
				if (p_type == 'C')
				{
					temp = new CovidPatient;
					temp->fileIO(true);
					temp->read(inFile);
					temp->fileIO(false);
					m_lineup[i] = temp;
					temp = nullptr;
					m_lineupSize++;
				}
				else if (p_type == 'T')
				{
					temp = new TriagePatient;
					temp->fileIO(true);
					temp->read(inFile);
					temp->fileIO(false);
					m_lineup[i] = temp;
					temp = nullptr;
					m_lineupSize++;
				}
			}
			if (m_lineupSize == maxNoOfPatients && !inFile.eof())
			{
				std::cout << "Warning: number of records exceeded " << maxNoOfPatients << std::endl;
			}
			else if (m_lineupSize == 0 && inFile.eof()) 
			{
				std::cout << "No data or bad data file!" << std::endl << std::endl;
			}
			if (m_lineupSize > 0)
			{
				std::cout << m_lineupSize << " Records imported..." << std::endl << std::endl;
			}
		}
		return;
	}

	PreTriage::PreTriage(const char* dataFilename)
		:m_appMenu("General Hospital Pre-Triage Application\n1- Register\n2- Admit", 2), 
		m_pMenu("Select Type of Admittance:\n1- Covid Test\n2- Triage", 2)
	{
		m_averCovidWait = 15;
		m_averTriageWait = 5;
		if (m_dataFilename != nullptr)
		{
			delete[] m_dataFilename;
		}
		m_dataFilename = dmaString(dataFilename);
		load();
	}

	PreTriage::~PreTriage()
	{
		if (m_dataFilename != nullptr)
		{
			std::ofstream saveFile(m_dataFilename);
			if (saveFile.is_open())
			{
				// prints out the following and save to file
				std::cout << "Saving Average Wait Times," << std::endl;
				std::cout << "   COVID Test: " << m_averCovidWait << std::endl;
				std::cout << "   Triage: " << m_averTriageWait << std::endl;
				std::cout << "Saving m_lineup..." << std::endl;
				saveFile << m_averCovidWait << "," << m_averTriageWait << std::endl;

				for (int i = 0; i < m_lineupSize; i++)
				{
					m_lineup[i]->csvWrite(saveFile);
					saveFile << std::endl;
					std::cout << i + 1 << "- ";
					m_lineup[i]->csvWrite(std::cout) << std::endl;
				}
			}
		}
		delete[] m_dataFilename;
		for (int i = 0; i < m_lineupSize; i++)
		{
			delete m_lineup[i];
		}
		std::cout << "done!" << std::endl;
	}

	void PreTriage::run(void)
	{
		int selection;
		do
		{
			m_appMenu >> selection;
			if (selection == 1)
			{
				reg();
			}
			else if (selection == 2)
			{
				admit();
			}
		} while (selection != 0);
		return;
	}
}