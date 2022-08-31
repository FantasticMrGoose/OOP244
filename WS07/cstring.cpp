#include "cstring.h"

namespace sdds{ 

    void strCpy(char* des, const char* src)
    {
        int i;

        for (i = 0; src[i] != '\0'; i++)
        {
            des[i] = src[i];
        }
        des[i] = '\0';

        return;
    }

    void strnCpy(char* des, const char* src, int len)
    {
        int i, numLetters = 0;

        for (i = 0; src[i] != '\0' && i < len; i++)
        {
            des[i] = src[i];
            numLetters++;
        }
        if (numLetters < len)
        {
            des[i] = '\0';
        }
        else
        {
            des[len] = '\0';
        }

        return;
    }

    int strCmp(const char* s1, const char* s2)
    {
        int i = 0, stop = 0, isSame = 0;

        while (stop == 0)
        {
            if (s1[i] == s2[i])
            {
                i++;
            }
            else if (s1[i] < s2[i])
            {
                isSame = -1;
                stop = 1;
            }
            else if (s1[i] > s2[i])
            {
                isSame = 1;
                stop = 1;
            }
        }
        return isSame;
    }

    int strnCmp(const char* s1, const char* s2, int len)
    {
        int i = 0, stop = 0, isSame = 0;

        while (stop == 0 && i < len)
        {
            if (s1[i] == s2[i])
            {
                i++;
            }
            else if (s1[i] < s2[i])
            {
                isSame = -1;
                stop = 1;
            }
            else if (s1[i] > s2[i])
            {
                isSame = 1;
                stop = 1;
            }
        }
        return isSame;
    }

    int strLen(const char* s)
    {
        int i, len = 0;

        //count number of characters
        for (i = 0; s[i] != '\0'; i++)
        {
            len++;
        }
        return len;
    }
    
    const char* strStr(const char* str1, const char* str2)
    {
        int i, match = 1;
        char* pointer = nullptr;
        for (i = 0; str1[i] != '\0' && match != 0; i++)
        {
            // returns '0' if match, then return address to main
            match = strnCmp(&str1[i], str2, strLen(str2));
            if (match == 0)
            {
                pointer = (char*)(str1 + i); 
            }
        }
        return pointer;
    } 

    void strCat(char* des, const char* src)
    {
        int i, len = 0;

        len = strLen(des);

        // appends source to the end of destination
        for (i = 0; src[i] != '\0'; i++)
        {
            des[len] = src[i];
            len++;
        }
        des[len] = '\0';
    }

}