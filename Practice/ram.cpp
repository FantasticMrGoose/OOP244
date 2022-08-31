


#include "ram.h"
using namespace std;
namespace sdds
{
	Memory::Memory(int numRam)
	{
		if (numRam > 0)
		{
			m_memory = new RAM[numRam];
			m_size = numRam;
			for (int i = 0; i < m_size; i++)
			{
				m_memory[i].size = 0;
			}
;		}
		else
		{
			emptyState();
		}
	}
	void Memory::emptyState()
	{
		if (m_memory != nullptr)
		{
			delete[] m_memory;
			m_memory = nullptr;
		}
		m_size = 0;
	}

	Memory& Memory::operator+=(int rh)
	{

		for (int i = 0; i < m_size; i++)
		{
			m_memory[i].size += rh;
		}
		return *this;
	}
	Memory::~Memory()
	{
		emptyState();
	}

	std::ostream& operator<<(std::ostream& ostr, const Memory& mem)
	{
		
		if (mem.m_memory != nullptr)
		{
			for (int i = 0; i < mem.m_size; i++) {

				ostr << "This ram has: " << mem.m_memory[i].size << "bytes" << endl;
			}
		}
		return ostr;
	}
}