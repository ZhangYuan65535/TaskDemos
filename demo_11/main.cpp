#include <QDebug>
#include <iostream>
#include "MyString.h"
#include "kmp.h"

using namespace std;


int main(int argc, char **argv)
{
    MyString s("aaabaabc");
    qWarning() << s;
}
