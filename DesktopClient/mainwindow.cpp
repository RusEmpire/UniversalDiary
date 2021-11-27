#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    bool ok = true;
    ok &= static_cast<bool>(QObject::connect(ui->About, SIGNAL(triggered()),
                                             this, SLOT(OnAbout())));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::OnAbout(){

}
