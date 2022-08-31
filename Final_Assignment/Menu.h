#ifndef SDDS_MENU_H_
#define SDDS_MENU_H_
namespace sdds{
    class Menu
    {
        char* m_text; 
        int m_noOfSel;  
        void display()const;
    public:
        Menu();
        Menu(const char* MenuContent, int NoOfSelections);
        virtual ~Menu();
        int& operator>>(int& Selection);
        Menu(const Menu&);
        Menu& operator=(const Menu&) = delete; //assignment prohibited
    };
}

#endif // !SDDS_MENU_H
