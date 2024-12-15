#ifndef CARDMASTERVIEWMODEL_H
#define CARDMASTERVIEWMODEL_H

#include <QWidget>
#include "MasterInfo.h"

namespace Ui {
class CardMasterViewModel;
}

class CardMasterViewModel : public QWidget
{
    Q_OBJECT

public:
    explicit CardMasterViewModel(const MasterInfo &masterInfo, QWidget *parent = nullptr);
    ~CardMasterViewModel();

private slots:
    void on_pushButton_clicked();

private:
    Ui::CardMasterViewModel *ui;
    MasterInfo masterInfo;
};

#endif // CARDMASTERVIEWMODEL_H
