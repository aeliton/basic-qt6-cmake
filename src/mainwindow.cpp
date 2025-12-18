#include "mainwindow.h"
#include <QAction>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <QMenuBar>
#include <QStatusBar>
#include <QTabWidget>
#include <QToolBar>

MainWindow::MainWindow()
    : QMainWindow(), tabs(new QTabWidget(this)) {
  setMenus();

  setToolbars();

  statusBar()->showMessage("Alvena Version 0.0.1");
}

MainWindow::~MainWindow() {}

void MainWindow::setMenus() {
  auto filemenu = menuBar()->addMenu("&File");
  auto quit = filemenu->addAction("&Quit");

  connect(quit, &QAction::triggered, this, &MainWindow::quit);
}

void MainWindow::setToolbars() {
  auto left = new QToolBar();
  addToolBar(Qt::ToolBarArea::LeftToolBarArea, left);
  left->addAction("Task");
}
