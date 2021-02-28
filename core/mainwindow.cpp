#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QCoreApplication>

#include <QScreen>
#include <QPixmap>

namespace Core {

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

/**
 * @brief 初始化所有
 */
void MainWindow::initAll()
{
    initMenu();

    initWidget();
}

void MainWindow::slotScreenshotTriggered()
{
    RScreenshotTool * screenshot = new RScreenshotTool();
    screenshot->setScreenshotSize(this->x(), this->y(), this->width(), this->height());
}

/**
 * @brief 初始化菜单栏
 */
void MainWindow::initMenu()
{
    m_fileMenu = new QMenu(tr("文件"));

    m_toolMenu = new QMenu(tr("工具"));

    m_screenshotAct = new QAction(tr("截图"));
    connect(m_screenshotAct, SIGNAL(triggered()), this, SLOT(slotScreenshotTriggered()));
    m_toolMenu->addAction(m_screenshotAct);

    m_helpMenu = new QMenu(tr("帮助"));

    ui->menubar->addMenu(m_fileMenu);
    ui->menubar->addMenu(m_toolMenu);
    ui->menubar->addMenu(m_helpMenu);
}

/**
 * @brief 初始化窗口
 */
void MainWindow::initWidget()
{

}

}//namespace Core
