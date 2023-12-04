#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QString>
#include <QStack>
#include <iostream>
#include <stack>
#include <string>

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
    ~Widget();

private slots:
    void on_onebutton_clicked();

    void on_twobutton_clicked();

    void on_threebutton_clicked();

    void on_fourbutton_clicked();

    void on_fivebutton_clicked();

    void on_sixbutton_clicked();

    void on_sevenbutton_clicked();

    void on_enghtbutton_clicked();

    void on_ninebutton_clicked();

    void on_zerobutton_clicked();

    void on_clebutton_clicked();

    void on_delbutton_clicked();

    void on_addbutton_clicked();

    void on_subbutton_clicked();

    void on_mubutton_clicked();

    void on_divbutton_clicked();

    void on_leftbutton_clicked();

    void on_rightbutton_clicked();


    void on_tobutton_clicked();

private:
    Ui::Widget *ui;
    QString edittext;
    int applyOp(int a, int b, char op);
    int priority(char op);
    int evaluate(std::string tokens);
};
#endif // WIDGET_H
