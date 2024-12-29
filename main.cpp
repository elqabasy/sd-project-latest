#include <QApplication>
#include <QPushButton>
#include "temp/home.temp.h"
int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    Home home;
    home.show();
    return QApplication::exec();
}
