#include "mypushbutton.h"
#include <QPainter>
#include <QDebug>
#include <QPropertyAnimation>
//MyPushButton::MyPushButton(QWidget *parent) :QPushButton(parent)
//{

//}

MyPushButton::MyPushButton(QString normalImg, QString pressImg){
    this->m_s_normalImgPath = normalImg;
    this->m_s_pressedImgPath = pressImg;

    QPixmap pix;
    bool flg = pix.load(this->m_s_normalImgPath);
    if(!flg)
    {
        qDebug() << "图片加载失败";
        return;
    }
    // 设定图片固定尺寸
    this->setFixedSize(pix.width(), pix.height());
    // 设定不规则图片样式表
    this->setStyleSheet("QPushButton{border:0px;}");
    // 设置图标
    this->setIcon(pix);
    //设置图标大小
    this->setIconSize(QSize(pix.width(), pix.height()));

}

void MyPushButton::zoom(int k){ // k == 1往上, k == 0 往下
    //创建动画对象
   QPropertyAnimation * animation1 = new QPropertyAnimation(this,"geometry");
   //设置时间间隔，单位毫秒
   animation1->setDuration(200);
   //创建起始位置
   animation1->setStartValue(QRect(this->x(),this->y() + k * 10,this->width(),this->height()));
   //创建结束位置
   animation1->setEndValue(QRect(this->x(),this->y()+10 - k * 10,this->width(),this->height()));
//   设置缓和曲线，QEasingCurve::OutBounce 为弹跳效果
   animation1->setEasingCurve(QEasingCurve::OutBounce);
   //开始执行动画
   animation1->start(QAbstractAnimation::DeleteWhenStopped);

}
