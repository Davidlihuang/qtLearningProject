#include "qwdilogmanual.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWDilogManual w;
    w.show();
    return a.exec();
}
