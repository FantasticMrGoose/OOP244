


#ifndef RAM_H_
#define RAM_H_
#include <iostream>
namespace sdds
{
	struct RAM
	{
		int size;
	};

	struct Memory
	{
		RAM* m_memory;
		int m_size;
		Memory(int numRam);
		void emptyState();
		Memory& operator +=(int rh);
		~Memory();
	};

	std::ostream& operator<<(std::ostream& ostr, const Memory&);
}

#endif // !RAM_H
