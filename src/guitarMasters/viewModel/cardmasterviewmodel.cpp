#include "cardmasterviewmodel.h"
#include "ui_cardmasterviewmodel.h"


CardMasterViewModel::CardMasterViewModel(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CardMasterViewModel)
{
    ui->setupUi(this);

    ui->FIOMaster->setText(masterInfo.getFIO());
    ui->Region->setText(masterInfo.getRegion());
}

CardMasterViewModel::~CardMasterViewModel()
{
    delete ui;
}

void CardMasterViewModel::on_pushButton_clicked()
{
    // open full content master
}

