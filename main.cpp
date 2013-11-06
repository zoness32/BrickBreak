#include <QApplication>
#include "startup.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    startup w;
    w.show();

    return a.exec();
}
