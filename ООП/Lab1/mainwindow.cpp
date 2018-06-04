#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->checkBox, &QCheckBox::toggled, [=](bool isbold) {
        QFont f = ui->label->font();
        f.setBold(isbold);
        ui->label->setFont(f);
    });
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setBold(bool isbold) {
    return;
}
