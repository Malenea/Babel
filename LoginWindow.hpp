#ifndef LOGIN_WINDOW_HPP
# define LOGIN_WINDOW_HPP

# include <QObject>
# include <QWidget>
# include "ServerEndpoint.hpp"

# include "ui_loginwindow.h"

class LoginWindow : public QWidget, private Ui::LoginWindow {
	Q_OBJECT

	private:
		QObject *bbl_;

	public:
		LoginWindow(QObject *bbl, QWidget *parent = nullptr);
		virtual ~LoginWindow();

	signals:
		void userLoggedIn();

	private slots:
		void checkCredentials();
};

#endif // !LOGIN_WINDOW_HPP
