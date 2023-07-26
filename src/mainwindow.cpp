#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::numKeyPressed()
{
    QString name;

    name = QObject::sender()->objectName();

    f_str = f_str + name[name.size() - 1];
    f_b = f_str.toFloat();
    f_str = QString::number(f_b);
    ui->lineEdit->setText(f_str);
}

void MainWindow::mathOperKeyPressed()
{
    QString name = QObject::sender()->objectName();

    if (name == "buttonAdd")
    {
        calculation();
        f_op = ADDITION;
        f_str = "";
    }
    else if (name == "buttonSub")
    {
        calculation();
        f_op = SUBSTRACTION;
        f_str = "";
    }
    else if (name == "buttonMult")
    {
        calculation();
        f_op = MULTIPLICATION;
        f_str = "";
    }
    else if (name == "buttonDiv")
    {
        calculation();
        f_op = DIVISION;
        f_str = "";
    }
    else if (name == "buttonPers")
    {
        f_b = f_a * f_b / 100;
        f_str = QString::number(f_b);
        ui->lineEdit->setText(f_str);
    }
}
void MainWindow::clearKeyPressed()
{
    QString name = QObject::sender()->objectName();

    if (name == "buttonClAll")
    {
        f_str = "0";
        f_a = f_b = 0;
        ui->lineEdit->setText(f_str);
    }
    else
    {
        f_str = "0";
        f_b = 0;
        ui->lineEdit->setText(f_str);
    }

}
void MainWindow::changeSignKeyPressed()
{
    f_b = 0 - ui->lineEdit->text().toFloat();
    ui->lineEdit->setText(QString::number(f_b));
}
void MainWindow::resultKeyPressed()
{
    calculation();
}
void MainWindow::dotKeyPressed()
{
    QString str = ui->lineEdit->text();

    if (str.indexOf(".") == -1)
        ui->lineEdit->setText(str + ".");
}

void MainWindow::calculation()
{
    if (f_str != "")
    {
        switch (f_op) {
        case ADDITION:
            f_a += f_b;
            f_str = QString::number(f_a);
            ui->lineEdit->setText(f_str);
            f_b = 0;
            break;
        case SUBSTRACTION:
            f_a -= f_b;
            f_str = QString::number(f_a);
            ui->lineEdit->setText(f_str);
            f_b = 0;
            break;
        case MULTIPLICATION:
            f_a *= f_b;
            f_str = QString::number(f_a);
            ui->lineEdit->setText(f_str);
            f_b = 0;
            break;
        case DIVISION:
            if (f_b != 0)
            {
                f_a /= f_b;
                f_str = QString::number(f_a);
                ui->lineEdit->setText(f_str);
                f_b = 0;
            }
            else
                ui->lineEdit->setText("ERROR. Division on zero");
            break;
        default:
            break;
        }
    }
}
