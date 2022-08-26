#include <iostream>
#include "Population.h"
#include "File.h"
#include "cstring.h"

using namespace std;
namespace sdds {

    int numOfPostals;
    int totalPop;
    popInfo* postalPop;

    void sort() {
        int i, j;
        popInfo temp;
        for (i = numOfPostals - 1; i > 0; i--) {
            for (j = 0; j < i; j++) {
                if (postalPop[j].m_pop > postalPop[j + 1].m_pop) {
                    temp = postalPop[j];
                    postalPop[j] = postalPop[j + 1];
                    postalPop[j + 1] = temp;
                }
            }
        }
    }

    bool load(popInfo& postalPop)
    {
        bool ok = false;

        if (read(postalPop.m_postalCode) && read(postalPop.m_pop))
        {
            ok = true;
            totalPop += postalPop.m_pop;
        }
        return ok;
    }

    bool load(const char filename[])
    {
        bool ok = false;
        int i = 0, numReads = 0;

        if (openFile(filename))
        {
            numOfPostals = noOfRecords();
            postalPop = new popInfo[numOfPostals]; //set dynamic memory


            for (i = 0; i < numOfPostals; i++)
            {
                if ((ok = load(postalPop[i])))
                {
                    numReads++;
                }
            }
            if (numReads != numOfPostals)
            {
                cout << "Error: incorrect number of records read; the data is possibly corrupted" << endl;
                ok = false;
            }
        }
        else
        {
            cout << "Could not open data file: " << filename << endl;
        }
        closeFile();
        return ok;
    }

    void display(const popInfo& postalPop)
    {
        cout << postalPop.m_postalCode << ":  " << postalPop.m_pop << endl;
    }

    void display()
    {
        int i;
        cout << "Postal Code: population" << endl;
        cout << "-------------------------" << endl;
        sort();
        for (i = 1; i <= numOfPostals; i++)
        {
            cout << i << "- ";
            display(postalPop[i - 1]);
        }
        cout << "-------------------------" << endl;
        cout << "Population of Canada: " << totalPop << endl;
        return;
    }

    void deallocateMemory()
    {
        delete[] postalPop;
        postalPop = nullptr;
    }
}