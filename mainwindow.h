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

public slots:
    void OpenStream();
    void SetOsd();
    void SetTime();
    void SyncTime();

private:
    Ui::MainWindow *ui;
    long userid;
};
#endif // MAINWINDOW_H
