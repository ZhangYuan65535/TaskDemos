#include "MyString.h"
#include <gtest/gtest.h>

class TestMyString : public testing::Test
{
public:
    TestMyString():
        m_mystring(new MyString)
    {
    }

    virtual ~TestMyString(){ delete m_mystring; }

protected:
    MyString *m_mystring;

};

TEST_F(TestMyString, insert)
{
    m_mystring->insert("aaa", 0);
    int res = strncmp(m_mystring->m_ptr, "aaa", 3);
    EXPECT_EQ(res, 0);
    EXPECT_EQ(m_mystring->m_size, 3);
}

TEST_F(TestMyString, remove)
{
    m_mystring->append("0123");
    m_mystring->remove(1, 2);
    int res = strncmp(m_mystring->m_ptr, "03", 2);
    EXPECT_EQ(res, 0);
}

TEST_F(TestMyString, find)
{
    m_mystring->append("AABABCABC");
    int res1 = m_mystring->find("ABC");
    EXPECT_EQ(res1, 3);
    int res2 = m_mystring->find("ABC",5);
    EXPECT_EQ(res2, 6);
}

TEST_F(TestMyString, operator_add)
{
    MyString s1("abc");
    MyString s2("def");
    MyString s3 = s1 + s2;
    int res = strncmp(s3, "abcdef", 6);
    EXPECT_EQ(res, 0);
}
