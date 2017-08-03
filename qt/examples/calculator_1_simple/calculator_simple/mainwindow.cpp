#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    //bool ok;
    //QString tempstr;
    //QString valuestr1=ui->lineEdit->text();
    //int valueint1=valuestr1.toInt(&ok);
}

void MainWindow::on_lineEdit_2_textChanged(const QString &arg1)
{
   // bool ok;
   // QString tempstr;
   // QString valuestr2=ui->lineEdit_2->text();
   // int valueint2=valuestr2.toInt(&ok);
}

void MainWindow::on_pushButton_clicked()
{
    bool ok;
    QString tempstr;
    QString valuestr1=ui->lineEdit->text();
    QString valuestr2=ui->lineEdit_2->text();
    int valueint1=valuestr1.toInt(&ok);
    int valueint2=valuestr2.toInt(&ok);
    int sum=valueint1+valueint2;
    ui->label->setText(tempstr.setNum(sum));
}
