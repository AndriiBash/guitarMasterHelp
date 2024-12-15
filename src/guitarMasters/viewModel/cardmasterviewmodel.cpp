#include "cardmasterviewmodel.h"
#include "ui_cardmasterviewmodel.h"

CardMasterViewModel::CardMasterViewModel(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CardMasterViewModel)
{
    ui->setupUi(this);
}

CardMasterViewModel::~CardMasterViewModel()
{
    delete ui;
}
