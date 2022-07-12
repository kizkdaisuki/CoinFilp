#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QPushButton>

class MyPushButton : public QPushButton
{
    Q_OBJECT
public:
//    explicit MyPushButton(QWidget *parent = nullptr);
    MyPushButton(QString normalImg, QString pressImg = "");
    void zoom(int);

public:
    QString m_s_normalImgPath;
    QString m_s_pressedImgPath;
signals:

};

#endif // MYPUSHBUTTON_H
