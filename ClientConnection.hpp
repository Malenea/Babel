#ifndef CLIENT_CONNECTION_HPP
# define CLIENT_CONNECTION_HPP

# include <QObject>
# include <QtNetwork>

class ClientConnection : public QObject {
	Q_OBJECT

	private:
		QUdpSocket sock_;
		QHostAddress peer_host_;
		quint16 peer_port_;

	public:
		ClientConnection();
		virtual ~ClientConnection() {}

		void setPeer(const QString& host, quint16 port);
		void bind(const QString& host, quint16 port);
		void sendPacket(const char *data);

	private slots:
		void onDataReceived();
		void onSocketError(QAbstractSocket::SocketError err);
};

#endif // !CLIENT_CONNECTION_HPP
