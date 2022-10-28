#ifndef ADDAPPDIALOG_H
#define ADDAPPDIALOG_H

#include <QDialog>
#include <QDebug>

namespace Ui {
class AddAppDialog;
}

class AddAppDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddAppDialog(QWidget *parent = nullptr);
    ~AddAppDialog();

    QList<QString> getInfo();

private slots:
    void on_btn_icon_clicked();

    void on_btn_run_clicked();

private:
    Ui::AddAppDialog *ui;
};

#endif // ADDAPPDIALOG_H
