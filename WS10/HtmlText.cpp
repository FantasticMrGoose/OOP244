#define _CRT_SECURE_NO_WARNINGS
#include "HtmlText.h"

using namespace std;
namespace sdds
{

	HtmlText::HtmlText(const char* filename, const char* title) :Text(filename)
	{
		m_title = nullptr;
		if (title != nullptr)
		{
			m_title = new char[strlen(title) + 1];
			strcpy(m_title, title);
		}
	}

	HtmlText& HtmlText::operator=(const HtmlText& rh)
	{
		if (this != &rh)
		{
			Text::operator=(rh);
			delete[] m_title;
			m_title = new char[strlen(rh.m_title) + 1];
			strcpy(m_title, rh.m_title);
		}
		return *this;
	}

	HtmlText::HtmlText(const HtmlText& rh) :Text(rh)
	{
		if (rh.m_title) {
			delete[] m_title;
			m_title = nullptr;
			m_title = new char[strlen(rh.m_title) + 1];
			strcpy(m_title, rh.m_title);
		}
	}

	HtmlText::~HtmlText()
	{
		delete[] m_title;
	}

	void HtmlText::write(std::ostream& os) const
	{
		bool MS = false;
		int i = 0;
		os << "<html><head><title>";
		if (m_title != nullptr)
		{
			os << m_title;
		}
		else
		{
			os << "No Title";
		}
		os << "</title></head>" << endl << "<body>" << endl;
		if (m_title != nullptr)
		{
			os << "<h1>" << m_title << "</h1>" << endl;
		}
		while (this->operator[](i) != '\0') {
			switch (this->operator[](i)) {
			case ' ':
				if (MS) {
					os << "&nbsp;";
				}
				else {
					MS = true;
					os << " ";
				}
				break;
			case '<':
				os << "&lt;";
				MS = false;
				break;
			case '>':
				os << "&gt;";
				MS = false;
				break;
			case '\n':
				os << "<br />\n";
				MS = false;
				break;
			default:
				os << Text::operator[](i);
				MS = false;
				break;
			}
			i++;
		}
		os << "</body>\n</html>";
	}
}