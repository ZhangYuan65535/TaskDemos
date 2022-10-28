#ifndef TEMPDELEGATE_H
#define TEMPDELEGATE_H

#include <QStyledItemDelegate>

class TempDelegate:public QStyledItemDelegate
{
public:
    TempDelegate(QObject *parent = nullptr);

    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;

    QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const;
};

#endif // TEMPDELEGATE_H
