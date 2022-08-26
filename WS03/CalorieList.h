#ifndef SDDS_CALORIELIST_H
#define SDDS_CALORIELIST_H
#include "Food.h"
namespace sdds{
    class CalorieList{
        Food* m_foodItems;
        int m_numOfFood;
        int m_foodsAdded;
        void setEmpty();
        bool isValid()const;
        int totalCalories()const;
        void Title()const;
        void footer()const;
    public:
        void init(int size);
        bool add(const char* item_name, int calories, int when);
        void display()const;
        void deallocate();
    };
}
#endif // !SDDS_CALORIELIST_H
