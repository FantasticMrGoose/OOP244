
#include <iostream>
#include "cstring.h"
#include "Food.h"
using namespace std;
namespace sdds{

    void Food::setName(const char* name) {
        strnCpy(m_foodName, name, 30);
        return;
    }

    void Food::setEmpty() {
        m_foodName[0] = '\0';
        m_calories = 0;
        m_mealCode = 0;
        m_mealType = nullptr;
        return;
    }

    void Food::set(const char* name, int calories, int mealCode) {
        if (name == nullptr || calories < 0 || calories > 3000 ||
            mealCode < 1 || mealCode > 4)
        {
            setEmpty();
        }
        else
        {
            setName(name);
            m_calories = calories;
            m_mealCode = mealCode;
            mealType();
        }
        return;
    }

    void Food::display()const {
        if (isValid())
        {
            cout << "| ";
            cout.width(30), cout.fill('.');
            cout.setf(ios::left);
            cout << m_foodName << " | ";
            cout.width(4), cout.fill(' ');
            cout.unsetf(ios::left);
            cout << m_calories << " | ";
            cout.width(9), cout.setf(ios::left);
            cout << m_mealType << "  |" <<endl;

        }
        else
        {
            cout << "| xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx | xxxx | xxxxxxxxxx |" << endl;
        }
        return;
    }

    bool Food::isValid()const {
        bool valid = false;
        if (m_foodName[0] != '\0' && m_calories >= 0 && m_calories <= 3000 && 
            m_mealCode > 0 && m_mealCode <= 4)
        {
            valid = true;
        }
        return valid;
    }

    int Food::calories()const {
        return m_calories;
    }

    void Food::mealType(){
        char mealType[21];
        int mealTypeLen = 0;

        if (m_mealCode == 1)
        {
            // setting dynamic memory
            strCpy(mealType, "Breakfast");
            mealTypeLen = strLen(mealType) + 1;
            m_mealType = new char[mealTypeLen];
            strCpy(m_mealType, mealType);
        }
        else if (m_mealCode == 2)
        {
            strCpy(mealType, "Lunch");
            mealTypeLen = strLen(mealType) + 1;
            m_mealType = new char[mealTypeLen];
            strCpy(m_mealType, mealType);
        }
        else if (m_mealCode == 3)
        {
            strCpy(mealType, "Dinner");
            mealTypeLen = strLen(mealType) + 1;
            m_mealType = new char[mealTypeLen];
            strCpy(m_mealType, mealType);
        }
        else if (m_mealCode == 4)
        {
            strCpy(mealType, "Snack");
            mealTypeLen = strLen(mealType) + 1;
            m_mealType = new char[mealTypeLen];
            strCpy(m_mealType, mealType);
        }
        return;
    }

    void Food::deallocate() {
        delete[] m_mealType;
        m_mealType = nullptr;
    }
}