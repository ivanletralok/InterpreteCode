#include "mainwindow.h"
#include <QApplication>
#include <parser.h>

int globalValue = 434;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);  
    a.setStyle("fusion");
    MainWindow w;
    //w.setWindowFlags(Qt::Window | Qt::WindowMinimizeButtonHint | Qt::WindowMaximizeButtonHint);

    QPalette palette;
    palette.setColor(QPalette::Window, QColor(53,53,53));
    palette.setColor(QPalette::WindowText, Qt::white);
    palette.setColor(QPalette::Base, QColor(53,53,53));
    palette.setColor(QPalette::AlternateBase, QColor(53,53,53));
    palette.setColor(QPalette::ToolTipBase, Qt::white);
    palette.setColor(QPalette::ToolTipText, Qt::white);
    palette.setColor(QPalette::Text, Qt::white);
    palette.setColor(QPalette::Button, QColor(53,53,53));
    palette.setColor(QPalette::ButtonText, Qt::white);
    palette.setColor(QPalette::BrightText, Qt::red);
    palette.setColor(QPalette::Highlight, QColor(102,102,75));
    palette.setColor(QPalette::HighlightedText, Qt::white);

    w.setPalette(palette);
    w.setWindowTitle("LessText for .code");
    w.show();

    return a.exec();
}
