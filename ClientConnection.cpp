#include <iostream>
#include "ClientConnection.hpp"

ClientConnection::ClientConnection() : peer_host_(QHostAddress::Null), peer_port_(0) {
	connect(&sock_, SIGNAL(readyRead()), this, SLOT(onDataReceived()));
	connect(&sock_, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(onSocketError(QAbstractSocket::SocketError)));
}

void ClientConnection::setPeer(const QString& host, quint16 port) {
	std::cout << "setting peer: " << host.toStdString() << ":" << port << "..." << std::endl;
	peer_host_ = QHostAddress(host);
	peer_port_ = port;
}

void ClientConnection::bind(const QString& host, quint16 port) {
	std::cout << "binding upd socket: " << host.toStdString() << ":" << port << "..." << std::endl;
	sock_.bind(QHostAddress(host), port);
}

void ClientConnection::sendPacket(const char *data) {
	if (peer_host_ == QHostAddress::Null || peer_port_ == 0)
		return;
	sock_.writeDatagram(data, peer_host_, peer_port_);
}

/*
** Slots
*/

void ClientConnection::onDataReceived() {
	while (sock_.hasPendingDatagrams()) {
		QByteArray datagram;
		datagram.resize(sock_.pendingDatagramSize());
		QHostAddress sender;
		quint16 senderPort;
		sock_.readDatagram(datagram.data(), datagram.size(), &sender, &senderPort);
        // process the datagram
        std::cout << "received datagram : " << datagram.data() << std::endl;
    }
}

void ClientConnection::onSocketError(QAbstractSocket::SocketError err) {
	std::cerr << "Socket error: " << sock_.errorString().toStdString() << std::endl;
}
