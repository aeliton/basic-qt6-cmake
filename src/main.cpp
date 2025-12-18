#include <QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);
  MainWindow window;

  QObject::connect(&window, &MainWindow::quit, &app,
                   &QApplication::quit);

  window.show();
  return app.exec();
}
