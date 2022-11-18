#include <QDebug>
#include <QMap>

#include "student.h"

Student::Student(QString name, QString id, QMap<QString, int> score):
    m_name(name),
    m_id(id),
    m_score(score)
{

}

void Student::show() const
{
    qWarning() << "name:" << m_name;
    qWarning() << "id:" << m_id;
    qWarning() << "score:";

    QMap<QString, int>::const_iterator it;
    for (it = m_score.cbegin(); it != m_score.cend(); it++) {
        qWarning() << "    " << it.key() << ":" << it.value();
    }
}

bool Student::compare(BaseItem *item1, BaseItem *item2) const
{
    Student *s1 = dynamic_cast<Student*>(item1);
    Student *s2 = dynamic_cast<Student*>(item2);
    return s1->m_score["Math"] < s2->m_score["Math"];
}
