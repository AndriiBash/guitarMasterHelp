#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void networkReplyReadyRead();

private slots:
    void on_pushButton_clicked();


private:
    Ui::MainWindow *ui;

    QNetworkAccessManager *networkManager;
    QNetworkReply *networkReply;
};
#endif // MAINWINDOW_H
