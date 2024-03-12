#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    int money{0};
    ~Widget();


private slots:
    void Init();
    void ChangeMoney(int diff);
    void on_pbCoin10_clicked();

    void on_pbCoin50_clicked();

    void on_pbCoin100_clicked();

    void on_pbCoin500_clicked();

    void on_pbBuyCoffee_clicked();

    void on_pbBuyTea_clicked();

    void on_pbBuyTang_clicked();

    void on_pbReset_clicked();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
