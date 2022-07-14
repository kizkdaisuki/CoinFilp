#include "mycoin.h"
#include <QPainter>
#include <QDebug>
#include <QTimer>
#include <cstring>

Mycoin::Mycoin(QString btnImg){
    this->setImg(btnImg);


    // 初始化定时器
       timer1 = new QTimer(this);
       timer2 = new QTimer(this);

       // 金币翻成银币
       connect(timer1, &QTimer::timeout, [=](){
           QString str = QString(":/res/Coin000%1.png").arg(this->m_i_l++);
           setImg(str);
           if(this->m_i_l > this->m_i_r){
               this->m_i_l = 1;
               this->m_b_isAnimation = false;
               timer1->stop();
           }
       });

       // 银币翻成金币
       connect(timer2, &QTimer::timeout, [=](){
           QString str = QString(":/res/Coin000%1.png").arg(this->m_i_r--);
           setImg(str);
           //if(this->max == 0){
           if(this->m_i_r < this->m_i_l){
               this->m_i_r = 8;
               this->m_b_isAnimation = false;
               timer2->stop();
           }
       });
   }



void Mycoin::setImg(QString str){

    QPixmap pix;
    bool flg = pix.load(str);
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

void Mycoin::changeFlg(int ms){
    if(this->m_flg)
    { // 1代表金币
            timer1->start(ms);
            //timer1->start(500);
            this->m_b_isAnimation = true;
            this->m_flg = false;
    }
    else
    {
            timer2->start(ms);
            //timer2->start(500);
            this->m_b_isAnimation = true;
            this->m_flg = true;
    }
}



void Mycoin::mousePressEvent(QMouseEvent *e){
    if(this->m_b_isAnimation || this->m_b_isWin){
            return;
        }
    QPushButton::mousePressEvent(e);
}




