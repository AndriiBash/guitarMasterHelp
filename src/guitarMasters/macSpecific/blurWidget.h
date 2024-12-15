#ifndef WIDGET_H
#define WIDGET_H

#include <QtWidgets>
#include <QWindow>
#include <QResizeEvent>


class BlurWidget : public QWidget
{

public:
    BlurWidget();
    ~BlurWidget() = default;

    void moveEvent(QMoveEvent *event) Q_DECL_OVERRIDE;
    void resizeEvent(QResizeEvent *event) Q_DECL_OVERRIDE;

private:
    void* effectsView = nullptr;
};



#endif // WIDGET_H
