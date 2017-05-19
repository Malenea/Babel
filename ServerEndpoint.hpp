#ifndef SERVER_ENDPOINT_HPP
# define SERVER_ENDPOINT_HPP

# include <QObject>
# include <QString>
# include <QTcpSocket>

class ServerEndpoint : public QObject {
	Q_OBJECT

	private:
		QTcpSocket sock_;

	private:
		void connectToServer(const QString& host, int port);

	public:
		ServerEndpoint() = delete;
		ServerEndpoint(const QString& host, int port);
		virtual ~ServerEndpoint() {}

		void sendData(const char *data);

	private slots:
		void onConnect();
		void onDataReceived();
		void onSocketError(QAbstractSocket::SocketError err);
};

#endif // !SERVER_ENDPOINT_HPP
