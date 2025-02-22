#include "my_string.hpp"

#include <iostream>
#include <cstring>

using namespace std;

/* PUBLIC */

MyString::MyString()
{
    string = nullptr;
}

MyString::MyString(const char* str)
{
    if (str)
    {
        string = new char[strlen(str) + 1];
        strcpy(string, str);
    }
    else string = nullptr;
}

MyString::MyString(const MyString& source)
{
    string = nullptr;
    if (source.get(0)) strcpy(*this, source);
}

MyString::~MyString()
{
    if (string) delete [] string;
    string = nullptr;
}

char MyString::get(int i) const
{
    if (string != "" && string && i >= 0 && i < strlen(string)) return string[i];
    return '\0';
}

void MyString::set(int i, char c)
{
    /**
     * Задает элемент строки по указанному индексу.
     * При необходимости размер строки увеличивается.
     * Если указан индекс, превосходящий текущий размер строки, 
     * то "пустые" ячейки заполняются пробелами.
     */
    int str_len;
    if (!string) str_len = 0;
    else str_len = strlen(string);
    if (i >= 0)
    {
        if (i >= str_len)
        {
            int new_str_len = i + 1;
            char* new_string = new char[new_str_len + 1];
            new_string[new_str_len] = '\0';
            if (string)
            {
                // strcpy(new_string, string);
                for (int j = 0; j < str_len; j++) new_string[j] = string[j];
                for (int j = str_len; j < i; j++) new_string[j] = ' ';
                delete [] string;
            }
            new_string[i] = c;
            // for (int j = str_len; j < new_str_len; j++)
            // {
            //     if (j == i) new_string[j] = c;
            //     else new_string[j] = ' ';
            // }
            string = new_string;
        }
        string[i] = c;
    }
}

void MyString::set_new_string(const char* str)
{
    if (string) delete [] string;
    string = new char[strlen(str) + 1];
    strcpy(string, str);
}

void MyString::print() const
{
    if (!string) return;
    for (int i = 0; i < strlen(string); i++) cout << string[i];
}

void MyString::read_line()
{
    int str_len = 0;
    char* str = new char[1];
    str[0] = '\0';
    char c;
    cin.get(c);
    while (c != '\n')
    {
        char* new_str = new char[str_len + 2];
        new_str[str_len + 1] = '\0';
        strcpy(new_str, str);
        new_str[str_len] = c;
        
        delete [] str;
        str = new_str;
        str_len++;

        cin.get(c);
    }

    set_new_string(str);
    delete [] str;
}

const MyString& MyString::operator = (const MyString& str)
{
    if (&str == this) return *this;

    if (string) delete [] string;
    if (str.get(0))
    {
        strcpy(*this, str);
    }
    else string = nullptr;

    return *this;
}

/* Внешние функции */

int strlen(const MyString& str)
{
    int len = 0;
    while (str.get(len)) len++;
    return len;
}

void strcpy(MyString& dest, const MyString& source)
{
    if (&source == &dest || strlen(dest) >= strlen(source)) return;

    char buffer[strlen(source) + 1];
    for (int i = 0; i <= strlen(source); i++) // включая нулевой байт
    {
        buffer[i] = source.get(i);
    }
    dest.set_new_string(buffer);
}
