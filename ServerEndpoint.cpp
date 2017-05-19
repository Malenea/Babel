#include <iostream>
#include "ServerEndpoint.hpp"

ServerEndpoint::ServerEndpoint(const QString& host, int port) {
	connect(&sock_, SIGNAL(connected()), this, SLOT(onConnect()));
	connect(&sock_, SIGNAL(readyRead()), this, SLOT(onDataReceived()));
	connect(&sock_, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(onSocketError(QAbstractSocket::SocketError)));

	connectToServer(host, port);
}

void ServerEndpoint::connectToServer(const QString& host, int port) {
	sock_.abort();
	std::cout << "connecting to: " << host.toStdString() << ":" << port << "..." << std::endl;
	sock_.connectToHost(host, port);
}

void ServerEndpoint::sendData(const char *data) {
	sock_.write(data, strlen(data));
}

/*
** Slots
*/

void ServerEndpoint::onConnect() {
	std::cout << "connected!" << std::endl;
}

void ServerEndpoint::onDataReceived() {
	QString data = sock_.readAll();
	std::cout << "data received : " << data.toStdString() << std::endl;
}

void ServerEndpoint::onSocketError(QAbstractSocket::SocketError err) {
	switch (err) {
	case QAbstractSocket::HostNotFoundError:
		std::cerr << "Host not found" << std::endl;
		break;
	case QAbstractSocket::ConnectionRefusedError:
		std::cerr << "Connection refused" << std::endl;
		break;
	default:
		std::cerr << "Socket error: " << sock_.errorString().toStdString() << std::endl;
	}
}
