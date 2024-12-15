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

#ifdef Q_OS_WIN
    ui->centralwidget->setStyleSheet("QWidget#centralwidget"
                                     "{"
                                     "}");
#endif
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

        parseJson(responseString);

        qDebug() << "Data received:" << networkReply->readAll();
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    aboutAppForm->close();
    aboutAppForm->show();
}

void MainWindow::parseJson(const QString &jsonString)
{
    QJsonDocument doc = QJsonDocument::fromJson(jsonString.toUtf8());

    if (doc.isArray())
    {
        QJsonArray jsonArray = doc.array();
        masters.clear();

        QWidget* containerWidget = new QWidget();
        QGridLayout* layout = new QGridLayout(containerWidget);
        layout->setSpacing(0);
        layout->setContentsMargins(0, 0, 0, 0);
        int row = 0, col = 0;
        const int itemsPerRow = 6;

        const int maxWidth = 200;
        const int maxHeight = 300;
        const int minWidth = 150;
        const int minHeight = 250;

        for (const QJsonValue &value : jsonArray)
        {
            if (value.isObject())
            {
                QJsonObject jsonObj = value.toObject();

                if (!jsonObj.isEmpty())
                {
                    MasterInfo masterInfo;
                    masterInfo.setDataJson(jsonObj);
                    masters.append(masterInfo);

                    CardMasterViewModel* cardMaster = new CardMasterViewModel(masterInfo);
                    cardMaster->setMaximumSize(maxWidth, maxHeight);
                    cardMaster->setMinimumSize(minWidth, minHeight);

                    layout->addWidget(cardMaster, row, col);

                    ++col;
                    if (col == itemsPerRow)
                    {
                        col = 0;
                        ++row;
                    }
                }
            }
        }

        containerWidget->setLayout(layout);

        ui->scrollArea->setWidget(containerWidget);
        ui->scrollArea->setWidgetResizable(true);
        ui->scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    }
    else
    {
        qDebug() << "Error: JSON not a array";
    }
}



// ADD METHOD WHEN CLOSE MAIN WINDOW, ALL WINDOW'S TOO CLOSE

