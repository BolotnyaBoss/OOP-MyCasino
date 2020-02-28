#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_spinBox_valueChanged(int arg1);

    int on_one_pressed();

    int on_two_pressed();

    int on_three_pressed();

    int on_four_pressed();

    int on_five_pressed();

    int on_six_pressed();

    void on_pushButton_7_pressed();

    void on_pushButton_8_pressed();

    void on_pushButton_9_pressed();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
