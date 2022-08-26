#ifndef SDDS_LABELMAKER_H
#define SDDS_LABELMAKER_H
#include "Label.h"
namespace sdds {
    class LabelMaker {
        Label* m_label;
        int m_numLabels;
        int m_labelQue;
    public:
        LabelMaker(int noOfLabels);
        ~LabelMaker();
        void readLabels();
        void printLabels();
    };
}
#endif // !SDDS_LABEL_H
