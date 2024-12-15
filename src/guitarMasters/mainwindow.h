#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

#include <aboutappform.h>
#include "MasterInfo.h"
#include "viewModel/CardMasterViewModel.h"

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

    void on_pushButton_2_clicked();

    void parseJson(const QString &jsonString);


private:
    Ui::MainWindow *ui;

    // getter's data from Firebase
    QNetworkAccessManager *networkManager;
    QNetworkReply *networkReply;

    // form's
    AboutAppForm *aboutAppForm;

    QList<MasterInfo> masters;
};

#endif // MAINWINDOW_H
