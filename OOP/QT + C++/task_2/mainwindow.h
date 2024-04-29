#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QPixmap>
#include <QMessageBox>
#include <QAbstractButton>

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
  void Res_sub_1();
  void Res_sum_1();
  void Res_sub_2();
  void Res_sum_2();
  void Res();
  void on_checkBox_1_stateChanged();
  void on_checkBox_2_stateChanged();
  void on_checkBox_3_stateChanged();
  void on_checkBox_4_stateChanged();
  void on_checkBox_5_stateChanged();
  void on_checkBox_6_stateChanged();
  void on_checkBox_3_clicked();
  void on_checkBox_4_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
