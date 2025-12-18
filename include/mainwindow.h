#ifndef ALVENA_MAINWINDOW_H
#define ALVENA_MAINWINDOW_H

#include <QMainWindow>

class QTabWidget;
class QGraphicsView;
class QGraphicsScene;

class MainWindow : public QMainWindow {
  Q_OBJECT
public:
  MainWindow();
  virtual ~MainWindow();

signals:
  void quit();

private:
  void setMenus();
  void setToolbars();
  QTabWidget *tabs;
};

#endif
