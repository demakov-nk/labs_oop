#ifndef MY_STRING_HPP_
#define MY_STRING_HPP_

class MyString
{
private:
    char* string;

public:
    MyString();
    MyString(const char* str);
    MyString(const MyString& source);
    ~MyString();

    char get(int i) const;
    void set(int i, char c);
    void set_new_string(const char* str);
    void print() const;
    void read_line();

    const MyString& operator = (const MyString& str);
};


int strlen(const MyString& str);
void strcpy(MyString& dest, const MyString& source);

#endif // MY_STRING_HPP_
