#include <iostream>
#include "cstring.h"
#include "CalorieList.h"
using namespace std;
namespace sdds{

    void CalorieList::setEmpty() {
        m_foodItems = nullptr;
        m_numOfFood = 0;
        return;
    }

    bool CalorieList::isValid()const {
        bool valid = false;
        int stop = 0;
        for (int i = 0; i < m_numOfFood && stop == 0; i++)
        {
            if (!(valid = m_foodItems[i].isValid()))
            {
                stop = 1;
            }
        }
        return valid;
    }

    int CalorieList::totalCalories()const {
        int totalCalories = 0;
        for (int i = 0; i < m_numOfFood; i++)
        {
            totalCalories += m_foodItems[i].calories();
        }
        return totalCalories;
    }

    void CalorieList::Title()const {
        cout << "+----------------------------------------------------+" << endl;
        if (isValid())
        {
            cout << "|  Daily Calorie Consumption                         |" << endl;
        }
        else
        {
            cout << "| Invalid Calorie Consumption list                   |" << endl;
        }
        cout << "+--------------------------------+------+------------+" << endl;
        cout << "| Food name                      | Cals | When       |" << endl;
        cout << "+--------------------------------+------+------------+" << endl;
    }

    void CalorieList::footer()const {
        cout << "+--------------------------------+------+------------+" << endl;
        if (isValid())
        {
            cout << "|    Total Calories for today:";
            cout.width(9), cout.setf(ios::right);
            cout << totalCalories();
            cout << " |            |" << endl;
        }
        else
        {
            cout << "|    Invalid Calorie Consumption list                |" << endl;
        }
        cout << "+----------------------------------------------------+" << endl;
    }

    void CalorieList::init(int size) {
        if (size > 0)
        {
            m_numOfFood = size;
            m_foodsAdded = 0;
            m_foodItems = new Food[m_numOfFood];
            for (int i = 0; i < m_numOfFood; i++)
            {
                // ensure dynamically allocated variables are set to empty
                m_foodItems[i].setEmpty(); 
            }
        }
        else
        {
            setEmpty();
        }
        return;
    }

    bool CalorieList::add(const char* item_name, int calories, int when) {
        bool isAdded = false;
        if (m_foodsAdded < m_numOfFood)
        {
            m_foodItems[m_foodsAdded].set(item_name, calories, when);
            m_foodsAdded++;
            isAdded = true;
        }
        return isAdded;
    }

    void CalorieList::display()const {
        Title();
        for (int i = 0; i < m_numOfFood; i++)
        {
            m_foodItems[i].display();
        }
        footer();
    }

    void CalorieList::deallocate() {
        for (int i = 0; i < m_numOfFood; i++)
        {
            m_foodItems[i].deallocate();
        }
        delete[] m_foodItems;
        m_foodItems = nullptr;
    }
}