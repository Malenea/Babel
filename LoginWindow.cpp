#include <iostream>
#include "LoginWindow.hpp"

LoginWindow::LoginWindow(QObject *bbl, QWidget *parent) : QWidget(parent), bbl_(bbl) {
	setupUi(this);
	connect(loginButton, SIGNAL(clicked()), this, SLOT(checkCredentials()));
	connect(this, SIGNAL(userLoggedIn()), bbl_, SLOT(connectUser()));
}

LoginWindow::~LoginWindow() {
}

void LoginWindow::checkCredentials() {
	QString user = username->text();
	QString pwd = password->text();
	if (user == "" || pwd == "")
		return;
	std::cout << user.toStdString() << " " << pwd.toStdString() << std::endl;
	// check with the server to confirm user credentials, and only then emit sigal
	emit userLoggedIn();
}
