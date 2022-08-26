#ifndef SDDS_FOOD_H
#define SDDS_FOOD_H
namespace sdds{

    class Food{
        char m_foodName[31];
        int m_calories;
        int m_mealCode;
        char* m_mealType;
        void setName(const char* name);
        void mealType();
    public:
        void setEmpty();
        void set(const char* name, int calories, int mealCode);
        void display()const;
        bool isValid()const;
        int calories()const;
        void deallocate();
    };
}
#endif // !SDDS_FOOD_H
