#include <QFileDialog>
#include "addappdialog.h"
#include "ui_addappdialog.h"


AddAppDialog::AddAppDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddAppDialog)
{
    ui->setupUi(this);


}

AddAppDialog::~AddAppDialog()
{
    delete ui;
}

QList<QString> AddAppDialog::getInfo()
{
    QList<QString> list;
    list << ui->name->text();
    list << ui->iconPath->text();
    list << ui->runPath->text();
    return list;
}

void AddAppDialog::on_btn_icon_clicked()
{
    QString iconPath = QFileDialog::getOpenFileName(this,"选择图标","/.","images(*.png)");
    ui->iconPath->setText(iconPath);

}

void AddAppDialog::on_btn_run_clicked()
{
    QString runPath = QFileDialog::getOpenFileName(this,"选择图标","/.","All files(*.*)");
    ui->runPath->setText(runPath);
}
