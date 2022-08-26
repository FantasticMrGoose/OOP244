#include "Label.h"
#include "cstring.h"
#define MAX_LABEL_SIZE 70
using namespace std;
namespace sdds
{
    void Label::setDefault(){
        strCpy(m_frame, "+-+|+-+|");
        m_labelText = nullptr;
        m_fillerSize = 0;
    }

    void Label::setLabelText(const char* text){
        if (text != nullptr)
        {
            char tempText[MAX_LABEL_SIZE + 1];
            int textLen = 0;

            strnCpy(tempText, text, MAX_LABEL_SIZE);
            textLen = strLen(tempText) + 1;
            delete[] m_labelText;
            m_labelText = nullptr;
            m_labelText = new char[textLen];
            strCpy(m_labelText, tempText);

            //used to print label empty spaces
            m_fillerSize = textLen + 2;
        }
        return;
    }

    Label::Label(){
        setDefault();
    }

    Label::Label(const char* frameArg){
        setDefault();
        if (strLen(frameArg) == 8) {// safeguard against bad input
            strCpy(m_frame, frameArg);
        }
    }

    Label::Label(const char* frameArg, const char* content)
    {
        setDefault();
        setLabelText(content);
        if (strLen(frameArg) == 8) {
            strCpy(m_frame, frameArg);
        }
    }

    Label::~Label() {
        delete[] m_labelText;
        m_labelText = nullptr;
    }

    void Label::readLabel() {
        char label[MAX_LABEL_SIZE + 1] = {'\0'};
        cin.getline(label, MAX_LABEL_SIZE + 1);
        
        // if more than 70 characters are read, keeps what is read
        // and discards the remaining characters
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(10000, '\n');
        }
        setLabelText(label);        
    }
    
    std::ostream& Label::printLabel()const {
        if (m_labelText != nullptr)
        {
            cout << m_frame[0];
            for (int i = 1; i < m_fillerSize; i++)
            {
                cout << m_frame[1];
            }
            cout << m_frame[2] << endl;
            cout << m_frame[7];

            cout.width(m_fillerSize);
            cout.fill(' ');
            cout << m_frame[3] << endl;
            cout << m_frame[7] << " ";
            cout << m_labelText << " " << m_frame[3] << endl;
            cout << m_frame[7];
            cout.width(m_fillerSize);
            cout.fill(' ');

            cout << m_frame[3] << endl;
            cout << m_frame[6];
            for (int i = 1; i < m_fillerSize; i++)
            {
                cout << m_frame[5];
            }
            cout << m_frame[4];
        }        
        return cout;
    }
}
