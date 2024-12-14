#include "aboutappform.h"
#include "ui_aboutappform.h"

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
