#include "widget.h"
#include "./ui_widget.h"
#include "QMessageBox"
#include "qstring.h"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    Init();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::Init() {
    ui->pbBuyCoffee->setEnabled(false);
    ui->pbBuyTea->setEnabled(false);
    ui->pbBuyTang->setEnabled(false);
}


void Widget::ChangeMoney(int diff) {
    money +=diff;
    ui->lcdNumber->display(money);

    QMessageBox mb;
    mb.information(this, "show me the moneyyyyyyyyy", "changed" + QString::number(diff) + "\nleft : " + QString::number(money));

    ui->pbBuyTang->setEnabled(money >= 200);
    ui->pbBuyCoffee->setEnabled(money >= 150);
    ui->pbBuyTea->setEnabled(money >= 100);
    ui->pbReset->setEnabled(money > 0);
}

void Widget::on_pbCoin10_clicked()
{
    ChangeMoney(10);
}


void Widget::on_pbCoin50_clicked()
{
   ChangeMoney(50);
}


void Widget::on_pbCoin100_clicked()
{
    ChangeMoney(100);
}


void Widget::on_pbCoin500_clicked()
{
    ChangeMoney(500);
}


void Widget::on_pbBuyCoffee_clicked()
{
    ChangeMoney(-100);
}


void Widget::on_pbBuyTea_clicked()
{

    ChangeMoney(-150);
}


void Widget::on_pbBuyTang_clicked()
{

    ChangeMoney(-200);
}


void Widget::on_pbReset_clicked()
{
    int c500, c100, c50, c10;
    QMessageBox mb;

    c500 = money/500;
    money %= 500;
    c100 = money/100;
    money %= 100;
    c50 = money/50;
    money %=50;
    c10 = money/10;
    money %=10;

    mb.information(this, "money!", "500 : " + QString::number(c500) + "\n100 : " + QString::number(c100) + "\n50 : " + QString::number(c50) + "\n10 : " + QString::number(c10));

    ui->lcdNumber->display(money);
    Init();
}

