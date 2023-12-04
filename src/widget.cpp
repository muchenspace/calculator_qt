#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->lineEdit->setValidator(new QIntValidator(ui->lineEdit));//只允许输入整形

}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_onebutton_clicked()
{
    edittext+="1";
    ui->lineEdit->setText(edittext);
}


void Widget::on_twobutton_clicked()
{
    edittext+="2";
    ui->lineEdit->setText(edittext);
}


void Widget::on_threebutton_clicked()
{
    edittext+="3";
    ui->lineEdit->setText(edittext);
}


void Widget::on_fourbutton_clicked()
{
    edittext+="4";
    ui->lineEdit->setText(edittext);
}


void Widget::on_fivebutton_clicked()
{
    edittext+="5";
    ui->lineEdit->setText(edittext);
}


void Widget::on_sixbutton_clicked()
{
    edittext+="6";
    ui->lineEdit->setText(edittext);
}


void Widget::on_sevenbutton_clicked()
{
    edittext+="7";
    ui->lineEdit->setText(edittext);
}


void Widget::on_enghtbutton_clicked()
{
    edittext+="8";
    ui->lineEdit->setText(edittext);
}


void Widget::on_ninebutton_clicked()
{
    edittext+="9";
    ui->lineEdit->setText(edittext);
}


void Widget::on_zerobutton_clicked()
{
    edittext+="0";
    ui->lineEdit->setText(edittext);
}


void Widget::on_clebutton_clicked()
{
    edittext.clear();
    ui->lineEdit->clear();
}


void Widget::on_delbutton_clicked()
{
    edittext.chop(1);
    ui->lineEdit->setText(edittext);
}


void Widget::on_addbutton_clicked()
{
    edittext+="+";
    ui->lineEdit->setText(edittext);
}


void Widget::on_subbutton_clicked()
{
    edittext+="-";
    ui->lineEdit->setText(edittext);
}


void Widget::on_mubutton_clicked()
{
    edittext+="*";
    ui->lineEdit->setText(edittext);
}


void Widget::on_divbutton_clicked()
{
    edittext+="/";
    ui->lineEdit->setText(edittext);
}


void Widget::on_leftbutton_clicked()
{
    edittext+="(";
    ui->lineEdit->setText(edittext);
}


void Widget::on_rightbutton_clicked()
{
    edittext+=")";
    ui->lineEdit->setText(edittext);
}

int Widget::priority(char op)
{
    if(op == '+'|| op == '-')
        return 1;
    if(op == '*'|| op == '/')
        return 2;
    return 0;
}

int Widget::applyOp(int a, int b, char op)
{
    switch(op)
    {
    case '+': return a + b;
    case '-': return a - b;
    case '*': return a * b;
    case '/': return a / b;
    }
}



int Widget::evaluate(std::string tokens)
{
    int i;
    std::stack <int> values;
    std::stack <char> ops;
    for(i = 0; i < tokens.length(); i++){
        if(tokens[i] == ' ')
            continue;
        else if(tokens[i] == '('){
            ops.push(tokens[i]);
        }
        else if(isdigit(tokens[i])){
            int val = 0;
            while(i < tokens.length() && isdigit(tokens[i])){
                val = (val*10) + (tokens[i]-'0');
                i++;
            }
            values.push(val);
            i--;
        }
        else if(tokens[i] == ')'){
            while(!ops.empty() && ops.top() != '('){
                int val2 = values.top();
                values.pop();
                int val1 = values.top();
                values.pop();
                char op = ops.top();
                ops.pop();
                values.push(applyOp(val1, val2, op));
            }
            if(!ops.empty())
                ops.pop();
        }
        else{
            while(!ops.empty() && priority(ops.top()) >= priority(tokens[i])){
                int val2 = values.top();
                values.pop();
                int val1 = values.top();
                values.pop();
                char op = ops.top();
                ops.pop();
                values.push(applyOp(val1, val2, op));
            }
            ops.push(tokens[i]);
        }
    }
    while(!ops.empty()){
        int val2 = values.top();
        values.pop();
        int val1 = values.top();
        values.pop();
        char op = ops.top();
        ops.pop();
        values.push(applyOp(val1, val2, op));
    }
    return values.top();
}

void Widget::on_tobutton_clicked()
{
    //edittext是一个QSring对象，evaluate接收string,需要转换为string
    //ui->lineEdit->clear();
    std::string newedittext=edittext.toStdString();
    int num = evaluate(newedittext);
    edittext=QString::number(num);
    ui->lineEdit->setText(edittext);
    //edittext.clear();
}

void Widget::on_lineEdit_textChanged(const QString &arg1)//当文本改变会执行此函数，argl是新文本
{
    QString newtext = arg1;
    edittext=newtext;
}

