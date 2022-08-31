#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <cstring>
#include "LblShape.h"
namespace sdds
{
    char* LblShape::label() const
    {
        return m_label;
    }

    LblShape::LblShape() {}

    LblShape::LblShape(const char* label)
    {
        if (m_label != nullptr)
        {
            delete[] m_label;
            m_label = nullptr;
        }
        m_label = new char[std::strlen(label) + 1];
        std::strcpy(m_label, label);
    }

    LblShape::~LblShape()
    {
        delete[] m_label;
        m_label = nullptr;
    }
    void LblShape::getSpecs(std::istream& istr)
    {
        std::string tempLabel;
        std::getline(istr, tempLabel, ',');

        if (m_label != nullptr)
        {
            delete[] m_label;
            m_label = nullptr;
        }

        m_label = new char[tempLabel.length() + 1];
        strcpy(m_label, tempLabel.c_str());

        return;
    }
}