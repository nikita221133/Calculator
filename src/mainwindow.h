#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{

    Q_OBJECT

    enum operation
    {
        ADDITION,
        SUBSTRACTION,
        MULTIPLICATION,
        DIVISION,
        PERSENTEGE
    };

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void numKeyPressed();
    void mathOperKeyPressed();
    void clearKeyPressed();
    void changeSignKeyPressed();
    void resultKeyPressed();
    void dotKeyPressed();

private:



    Ui::MainWindow *ui;
    QString f_str = "0";
    float f_a = 0, f_b = 0;
    operation f_op;

    void calculation();
};
#endif // MAINWINDOW_H
