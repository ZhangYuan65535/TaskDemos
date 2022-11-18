#include <QDebug>

#include "student.h"
#include "model.h"

int main()
{
    Model model;

    QMap<QString, int> m1{{"Math",88}, {"English",80}};
    Student s1("LiHua", "1001", m1);

    model.addItem(&s1);
    model.show();
}
