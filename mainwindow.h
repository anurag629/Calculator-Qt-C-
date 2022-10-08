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

private:
    Ui::MainWindow *ui;
// on calling the signal the respective slots assigned, do the task
private slots:
    void digit_pressed();

    void on_pushButton_decimal_released();

    void unary_operation_pressed();

    void on_pushButton_Cancel_released();
    void on_pushButton_equal_released();

    void binary_operation_pressed();
};

#endif // MAINWINDOW_H
