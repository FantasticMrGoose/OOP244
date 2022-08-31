#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Menu.h"
#include "utils.h"
using namespace std;
namespace sdds
{
	void Menu::display() const
	{
		std::cout << m_text << std::endl;
		std::cout << "0- Exit" << std::endl;
	}

	Menu::Menu()
	{
		m_text = nullptr;
		m_noOfSel = -1;
	}

	Menu::Menu(const char* MenuContent, int NoOfSelections)
	{
		m_text = nullptr;
		m_noOfSel = NoOfSelections;
		if (MenuContent != nullptr)
		{
			m_text = dmaString(MenuContent);
		}		
	}

	Menu::~Menu()
	{
		delete[] m_text;
		m_text = nullptr;
	}

	int& Menu::operator>>(int& Selection)
	{
		display();
		Selection = getInt((m_noOfSel - m_noOfSel), m_noOfSel, 
			"> ", nullptr, true);
		return Selection;
	}

	Menu::Menu(const Menu& rh)
	{
		m_text = nullptr;
		m_noOfSel = rh.m_noOfSel;
		if (rh.m_text != nullptr)
		{
			m_text = dmaString(rh.m_text);
		}
		else
		{
			m_text = nullptr;
		}
	}
}