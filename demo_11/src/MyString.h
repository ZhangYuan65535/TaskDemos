#pragma once
#include <iostream>

class MyString
{
    using size_t = unsigned int;


public:
    MyString();
    MyString(const char* str);
    MyString(MyString &s);
    ~MyString();

    bool _expendCapacity(size_t capacity);

    bool insert(const char *str, size_t index);
    bool append(const char *str);
    bool remove(int begin, int end);
    int find(const char* str);
    void showValue();

    MyString operator+(const char* str);
    MyString operator+(const MyString &str);

public:
    char *m_ptr;

    size_t m_size;
    size_t m_capacity;
};

inline std::ostream& operator <<(std::ostream &out, MyString &str)
{
    out << str.m_ptr;
    return out;
}
