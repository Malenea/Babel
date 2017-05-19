#include <QApplication>
#include "Babel.hpp"

int main(int ac, char **av) {
	QApplication a(ac, av);
	Babel babel;
	return a.exec();
}
