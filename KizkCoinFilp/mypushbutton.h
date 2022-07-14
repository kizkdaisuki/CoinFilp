#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QPushButton>
#include <QMouseEvent>

class MyPushButton : public QPushButton
{
    Q_OBJECT
public:
//    explicit MyPushButton(QWidget *parent = nullptr);
    MyPushButton(QString normalImg, QString pressImg = "");
    // 弹跳特效
    void zoom(int k, int v = 10, int s = 200);
    // 重写鼠标事件
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
    void setImg(QString str);

public:
    QString m_s_normalImgPath;
    QString m_s_pressedImgPath;

signals:

};

#endif // MYPUSHBUTTON_H
