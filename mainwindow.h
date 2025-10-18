#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_Num_0_clicked();

    void on_Num_1_clicked();

    void on_Num_2_clicked();

    void on_Num_3_clicked();

    void on_Num_4_clicked();

    void on_Num_5_clicked();

    void on_Num_6_clicked();

    void on_Num_7_clicked();

    void on_Num_8_clicked();

    void on_Num_9_clicked();

    void on_Divide_clicked();

    void on_Multiply_clicked();

    void on_Subtract_clicked();

    void on_Add_clicked();

    void on_Equals_clicked();

    void on_Parenthesis_clicked();

    void on_point_clicked();

    void on_AC_clicked();

    void on_Delete_clicked();

    void on_Switch_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
