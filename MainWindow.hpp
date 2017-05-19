#ifndef MAIN_WINDOW_HPP
# define MAIN_WINDOW_HPP

# include <QObject>
# include <QWidget>
# include "ServerEndpoint.hpp"

# include "ui_mainwindow.h"

class MainWindow : public QWidget, private Ui::MainWindow {
	Q_OBJECT

	private:
		QObject *bbl_;

	public:
		MainWindow(QObject *bbl, QWidget *parent = nullptr);
		virtual ~MainWindow();
};

#endif // !MAIN_WINDOW_HPP
