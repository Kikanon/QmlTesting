#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);//zagon aplikacije
    
    MainWindow w;//aplikaciji dodamo main window
    w.show();
    
    return a.exec();
}
