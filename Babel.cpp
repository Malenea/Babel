#include <iostream>
#include "Babel.hpp"

Babel::Babel() : login_window_(new LoginWindow(this)), main_window_(new MainWindow(this)) {
	// ServerEndpoint se("10.12.180.240", 4242);
	se_ = new ServerEndpoint("127.0.0.1", 4242);
	cc_ = new ClientConnection();
	// cc_->setPeer("10.12.179.9", 5555);
	cc_->bind("0.0.0.0", 5555);
	// cc_->sendPacket("this is a test");
	login_window_->show();
	// se.sendData("con toto online\n");
}

Babel::~Babel() {
	delete se_;
	delete cc_;
	delete login_window_;
	delete main_window_;
}

void Babel::connectUser() {
	login_window_->hide();
	main_window_->show();
}
