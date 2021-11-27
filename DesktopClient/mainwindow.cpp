#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // fill info about new session
    // when open app
    DebugInfo::Debug()->WriteToLog("New Session", INFO);

    bool ok = true;
    ok &= static_cast<bool>(QObject::connect(ui->About, SIGNAL(triggered()),
                                             this, SLOT(OnAbout())));

    DebugInfo::Debug()->CheckConnect(ok, QString("MainWindow"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::OnAbout(){
    About* about = new About();
    about->show();
}
