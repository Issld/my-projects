#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QIntValidator>
#include <QMessageBox>

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
  void Result();
  void Ask();
  void Clear();

  void on_size1_clicked();

  void on_size2_clicked();

  void on_size3_clicked();

  void on_type1_clicked();

  void on_radioButton_5_clicked();

  void on_type2_clicked();

private:
    Ui::MainWindow *ui;
    QIntValidator res;
};
#endif // MAINWINDOW_H
