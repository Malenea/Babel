#ifndef COMMAND_MANAGER_HPP
# define COMMAND_MANAGER_HPP

# include <QObject>
# include <QString>
# include <QtNetwork>

class CommandManager : public QObject {
	Q_OBJECT

	public:
		CommandManager();
		virtual ~CommandManager();
};

#endif // !COMMAND_MANAGER_HPP
