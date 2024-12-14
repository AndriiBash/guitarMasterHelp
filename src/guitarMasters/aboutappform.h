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

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::AboutAppForm *ui;
};

#endif // ABOUTAPPFORM_H
