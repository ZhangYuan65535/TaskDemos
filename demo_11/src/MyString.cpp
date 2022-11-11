#include <QDebug>
#include <iostream>

#include "MyString.h"
#include "kmp.h"

using namespace std;

MyString::MyString():
    m_ptr(nullptr),
    m_size(0),
    m_capacity(0)
{

}

MyString::MyString(const char *str):
    m_ptr(nullptr),
    m_size(0),
    m_capacity(0)
{
    this->insert(str, 0);
}

MyString::MyString(MyString &s):
    m_ptr(nullptr),
    m_size(0),
    m_capacity(0)
{
    _expendCapacity(s.m_size);
    m_size = m_capacity;
    strncpy(m_ptr, s.m_ptr, m_size);
}

MyString::~MyString()
{
    delete m_ptr;
}

/**
 * @brief MyString::_expendCapacity 扩充容量
 * 由于分配内存的动作可能会失败，所以做判断
 * @param capacity 扩充后的容量大小
 * @return true 扩容成功，false 扩容失败
 */
bool MyString::_expendCapacity(MyString::size_t capacity)
{
    char *oldPtr = m_ptr;
    m_ptr = (char*)malloc(capacity + 1);
    if (!m_ptr) {
        return false;
    }
    if (oldPtr) {
        strncpy(m_ptr, oldPtr, m_size);
        delete oldPtr;
    }
    m_capacity = capacity;
    return true;
}

/**
 * @brief MyString::insert 插入字符串
 * @param str 待插入的字符串
 * @param index 要插入的位置
 * @return true 插入成功，
 */
bool MyString::insert(const char *str, MyString::size_t index)
{
    size_t size = m_size + strlen(str);
    if (size > m_capacity && _expendCapacity(size * 1.5) == false) {
        return false;
    }

    char *tmp = (char*)malloc(m_size - index + 1);
    if (!tmp) {
        return false;
    }
    strncpy(tmp, m_ptr + index, m_size - index + 1);
    strncpy(m_ptr + index, str, strlen(str));
    strncpy(m_ptr + index + strlen(str), tmp, m_size - index + 1);
    m_size = size;
    return true;
}

/**
 * @brief MyString::append 追加字符串
 */
bool MyString::append(const char *str)
{
    return insert(str, m_size);
}

/**
 * @brief MyString::remove 删除子串
 * @param begin 子串起点
 * @param end 子串终点
 * @return false 删除失败
 */
bool MyString::remove(int begin, int end)
{
    if (0 <= begin && begin <= end && end <= m_size) {
        strncpy(m_ptr + begin, m_ptr + end + 1, m_size - end + 1);
        m_size -= (end - begin + 1);
    }
    return false;
}

int MyString::find(const char *str)
{
    return searchChildByKmp(this->m_ptr, str);
}

void MyString::showValue()
{
    qWarning() << this->m_ptr;
}

MyString MyString::operator+(const char *str)
{
    MyString tmp(*this);
    tmp.append(str);
    return tmp;
}

MyString MyString::operator+(const MyString &str)
{
    this->append(str.m_ptr);
    return *this;
}








