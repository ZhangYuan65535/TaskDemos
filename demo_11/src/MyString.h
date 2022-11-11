#pragma once
#include <iostream>
#include <QList>
#include <QDebug>

class MyString
{
    using size_t = unsigned int;
    friend std::ostream& operator <<(std::ostream &, MyString &);
    friend QDebug operator <<(QDebug, MyString &);

public:
    MyString();
    MyString(const char* str);
    MyString(MyString &str);
    MyString(MyString &str, size_t begin, size_t len);
    ~MyString();

    bool _expendCapacity(size_t capacity);

    bool insert(const char *str, size_t index);
    bool append(const char *str);
    bool remove(int begin, int end);
    int find(const char* str);
    int find(const char *str, size_t begin);
    void showValue();

    MyString operator+(const char* str);
    MyString operator+(const MyString &str);
    operator char*() const;

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

inline QDebug operator << (QDebug debug, MyString &str)
{
    debug << str.m_ptr;
    return debug;
}
