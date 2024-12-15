#include "aboutappform.h"
#include "ui_aboutappform.h"

#include <QDesktopServices>

AboutAppForm::AboutAppForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AboutAppForm)
{
    ui->setupUi(this);

    setWindowTitle("Про застосунок");

    // THIS FORM NEED STATIC SIZE!!!
}

AboutAppForm::~AboutAppForm()
{
    delete ui;
}


// maybe get links from Firebase...
void AboutAppForm::on_pushButton_clicked()
{
    QDesktopServices::openUrl(QUrl("https://t.me/+XNvNqEbhWgo0ODgy"));
}


void AboutAppForm::on_pushButton_3_clicked()
{
    QDesktopServices::openUrl(QUrl("https://t.me/anbidexter"));
}

void AboutAppForm::on_pushButton_2_clicked()
{
    QDesktopServices::openUrl(QUrl("https://t.me/cyan_light"));
}


void AboutAppForm::on_pushButton_4_clicked()
{
    QDesktopServices::openUrl(QUrl("https://github.com/AndriiBash/guitarMasterHelp/tree/main"));
}

