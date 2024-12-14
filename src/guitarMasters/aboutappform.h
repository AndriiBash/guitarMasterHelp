#ifndef ABOUTAPPFORM_H
#define ABOUTAPPFORM_H

#include <QWidget>

namespace Ui {
class AboutAppForm;
}

class AboutAppForm : public QWidget
{
    Q_OBJECT

public:
    explicit AboutAppForm(QWidget *parent = nullptr);
    ~AboutAppForm();

private:
    Ui::AboutAppForm *ui;
};

#endif // ABOUTAPPFORM_H
