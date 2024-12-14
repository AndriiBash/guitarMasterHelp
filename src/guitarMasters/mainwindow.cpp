#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle("GuitarMaster");

    networkManager = new QNetworkAccessManager(this);
    networkReply = networkManager->get(QNetworkRequest(QUrl("https://qtdatabaseguitar-default-rtdb.europe-west1.firebasedatabase.app/mainTable.json")));

    connect(networkReply, &QNetworkReply::readyRead, this, &MainWindow::networkReplyReadyRead);


    aboutAppForm = new AboutAppForm();
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    if (networkReply)
    {
        networkReply->abort();
        networkReply->deleteLater();
        networkReply = nullptr;
    }

    // Include new request
    networkReply = networkManager->get(QNetworkRequest(QUrl("https://qtdatabaseguitar-default-rtdb.europe-west1.firebasedatabase.app/mainTable.json")));

    // Include new signal for new obj
    connect(networkReply, &QNetworkReply::readyRead, this, &MainWindow::networkReplyReadyRead);
    connect(networkReply, &QNetworkReply::finished, this, [this]()
    {
        qDebug() << "Request finished.";
        networkReply->deleteLater();
        networkReply = nullptr;
    });
}


void MainWindow::networkReplyReadyRead()
{
    if (networkReply)
    {
        QByteArray responseData = networkReply->readAll();
        QString responseString = QString::fromUtf8(responseData);

        ui->label->setText(responseString);

        qDebug() << "Data received:" << networkReply->readAll();
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    aboutAppForm->close();
    aboutAppForm->show();
}

// ADD METHOD WHEN CLOSE MAIN WINDOW, ALL WINDOW'S TOO CLOSE

