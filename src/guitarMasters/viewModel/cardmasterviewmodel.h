#ifndef CARDMASTERVIEWMODEL_H
#define CARDMASTERVIEWMODEL_H

#include <QWidget>

namespace Ui {
class CardMasterViewModel;
}

class CardMasterViewModel : public QWidget
{
    Q_OBJECT

public:
    explicit CardMasterViewModel(QWidget *parent = nullptr);
    ~CardMasterViewModel();

private:
    Ui::CardMasterViewModel *ui;
};

#endif // CARDMASTERVIEWMODEL_H
