#include "mycoin.h"
#include <QPainter>
#include <QDebug>
#include <QTimer>

Mycoin::Mycoin(QString btnImg){
    this->setImg(btnImg);


    // 初始化定时器
       timer1 = new QTimer(this);
       timer2 = new QTimer(this);

       // 金币翻成银币
       connect(timer1, &QTimer::timeout, [=](){
           QString str = QString(":/res/Coin000%1.png").arg(this->min++);

           QPixmap pix;
           pix.load(str);

           this->setFixedSize(pix.width(), pix.height());

           this->setStyleSheet("QPushButton{border:0px;}");
           this->setIcon(pix);
           this->setIconSize(QSize(pix.width(), pix.height()));

           if(this->min > this->max){
               this->min = 1;
               this->isAnimation = false;
               timer1->stop();
           }
       });

       // 银币翻成金币
       connect(timer2, &QTimer::timeout, [=](){
           QString str = QString(":/res/Coin000%1.png").arg(this->max--);

           QPixmap pix;
           pix.load(str);

           this->setFixedSize(pix.width(), pix.height());

           this->setStyleSheet("QPushButton{border:0px;}");
           this->setIcon(pix);
           this->setIconSize(QSize(pix.width(), pix.height()));

           //if(this->max == 0){
           if(this->max < this->min){
               this->max = 8;
               this->isAnimation = false;
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

void Mycoin::turn(int posX, int posY){

}

void Mycoin::changeFlg(int ms){
    if(this->m_flg){
            timer1->start(ms);
            //timer1->start(500);
            this->isAnimation = true;
            this->m_flg = false;
        }else{
            timer2->start(ms);
            //timer2->start(500);
            this->isAnimation = true;
            this->m_flg = true;
    }
}

void Mycoin::mousePressEvent(QMouseEvent *e){
    if(this->isAnimation || this->notPress){
            return;
        }
        QPushButton::mousePressEvent(e);
}

void Mycoin::turnCoin(int posX, int posY){
//    int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
//    for(int i = 0; i < 4; i ++)
//    {
//        int a = dx[i] + posX, b = posY + dy[i];
//        if(a < 0 || a >= 4 || b < 0 || b >= 4)
//            continue;
//        turn(a, b);
//    }
}



