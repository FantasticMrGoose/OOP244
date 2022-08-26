#ifndef SDDS_LABEL_H
#define SDDS_LABEL_H
#include <iostream>
namespace sdds {

    class Label {
        char m_frame[9]; // frame will have only 9 characters
        char* m_labelText;
        int m_fillerSize;
        void setDefault();
        void setLabelText(const char* text);
    public:
        Label();
        Label(const char* frameArg);
        Label(const char* frameArg, const char* content);
        ~Label();
        void readLabel();
        std::ostream& printLabel()const;
    };
}
#endif // !SDDS_LABEL_H

