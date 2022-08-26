#include "LabelMaker.h"
using namespace std;
namespace sdds{
    LabelMaker::LabelMaker(int noOfLabels) {
        m_label = nullptr;
        m_numLabels = 0;
        m_labelQue = 0;
        if (noOfLabels > 0)
        { 
            m_label = new Label[noOfLabels];
            m_numLabels = noOfLabels;
        }
    }

    LabelMaker::~LabelMaker() {
        delete[] m_label;
        m_label = nullptr;
    }

    void LabelMaker::readLabels() {
        m_labelQue = 0;
        cout << "Enter " << m_numLabels << " labels:" << endl;
        for (int i = 0; i < m_numLabels; i++, m_labelQue++)
        {
            cout << "Enter label number " << m_labelQue + 1 << endl;
            cout << "> ";
            m_label[m_labelQue].readLabel();
        }
        return;
    }

    void LabelMaker::printLabels() {
        m_labelQue = 0;
        for (int i = 0; i < m_numLabels; i++, m_labelQue++)
        {
            m_label[m_labelQue].printLabel();
            cout << endl;
        }
        return;
    }
}
