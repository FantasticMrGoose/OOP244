#ifndef SDDS_POPULATION_H_
#define SDDS_POPULATION_H_
namespace sdds {

    struct popInfo
    {
        char m_postalCode[4] = "\0"; //using static, will always be 4 chars
        int m_pop;
    };
    void sort();
    bool load(popInfo& );
    bool load(const char filename[]);
    void display(const popInfo& postal);
    void display();
    void deallocateMemory();
}
#endif // SDDS_POPULATION_H_