#ifndef BABEL_HPP
# define BABEL_HPP

# include <QObject>
# include <QWindow>
# include "MainWindow.hpp"
# include "LoginWindow.hpp"
# include "ClientConnection.hpp"
# include "ServerEndpoint.hpp"

class Babel : public QObject {
	Q_OBJECT

	private:
		ServerEndpoint *se_;
		ClientConnection *cc_;
		LoginWindow *login_window_;
		MainWindow *main_window_;

	public:
		Babel();
		virtual ~Babel();

	private slots:
		void connectUser();
};

#endif // !BABEL_HPP
