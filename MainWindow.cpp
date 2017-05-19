#include "MainWindow.hpp"

MainWindow::MainWindow(QObject *bbl, QWidget *parent) : QWidget(parent), bbl_(bbl) {
	setupUi(this);
}

MainWindow::~MainWindow() {
}
