#ifndef DETAILWINDOW_H
#define DETAILWINDOW_H

#include <QWidget>
#include <QtWidgets>

class DetailWindow : public QWidget
{
    Q_OBJECT
public:
    explicit DetailWindow(QWidget *parent = nullptr);
    void initData();
    void initGUI();

private:
    QTableView *m_tableView;
    QStandardItemModel *m_model;

    QList<QString> m_icons;
    QList<QString> m_names;
    QList<double> m_prices;
};

#endif // DETAILWINDOW_H
