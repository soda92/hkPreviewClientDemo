#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "client.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->open_stream, &QPushButton::clicked, this, &MainWindow::OpenStream);
    connect(ui->set_osd, &QPushButton::clicked, this, &MainWindow::SetOsd);
    connect(ui->set_time, &QPushButton::clicked, this, &MainWindow::SetTime);
    connect(ui->sync_time, &QPushButton::clicked, this, &MainWindow::SyncTime);
}

void MainWindow::OpenStream()
{
    auto ip = ui->ip->text();
    this->userid = preview(ip.toStdString().c_str(), ui->label_show->winId());
    std::stringstream ss;
    ss << this->userid;
    ui->userid->setText(QString::fromStdString(ss.str()));
}

void MainWindow::SetOsd()
{
    set_osd(this->userid,
            ui->speed->text().toStdString().c_str(),
            ui->distance->text().toStdString().c_str(),
            ui->train_order->text().toStdString().c_str(),
            ui->train_number->text().toStdString().c_str(),
            ui->location->text().toStdString().c_str(),
            ui->driver_number->text().toStdString().c_str(),
            ui->is_record->isChecked(),
            ui->is_usb->isChecked());
}

void MainWindow::SetTime()
{
    set_time(this->userid,
             std::stoi(ui->year->text().toStdString()),
             std::stoi(ui->month->text().toStdString()),
             std::stoi(ui->day->text().toStdString()),
             std::stoi(ui->hour->text().toStdString()),
             std::stoi(ui->minute->text().toStdString()),
             std::stoi(ui->second->text().toStdString())
            );
}

void MainWindow::SyncTime()
{
    sync_time(this->userid);
}

MainWindow::~MainWindow()
{
    delete ui;
}

