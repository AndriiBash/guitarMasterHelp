#include "mainwindow.h"

#include <QApplication>

#include <macSpecific/blurWidget.h>
#include <mainwindow.h>

#ifndef  Q_OS_MACOS

Widget::Widget() : QWidget(nullptr) {}
void Widget::moveEvent(QMoveEvent *event) { QWidget::moveEvent(event); }
void Widget::resizeEvent(QResizeEvent *event) { QWidget::resizeEvent(event); }

#endif


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

#ifdef Q_OS_WIN
    MainWindow w;
    w.show();
#elif defined(Q_OS_MACOS)
    BlurWidget blurWindow;
    blurWindow.layout()->setContentsMargins(0, 0, 0, 0);
    blurWindow.resize(300, 200);
    blurWindow.show();
#endif
    return a.exec();
}
