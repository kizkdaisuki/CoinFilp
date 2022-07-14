#include "chooselevelsence.h"
#include "ui_chooselevelsence.h"
#include <QPainter>
#include "mypushbutton.h"
#include <QTimer>
#include <QLabel>
#include <QDebug>
#include <QFont>
#include <QPalette>
ChooseLevelSence::ChooseLevelSence(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ChooseLevelSence)
{
    ui->setupUi(this);
    // 设置固定大小 标题 图标
    this->setFixedSize(320, 588);
    this->setWindowIcon(QIcon(":/res/Coin0001.png"));
    this->setWindowTitle("KIZK");
    // 设置点击退出
    connect(ui->actionquit, &QAction::triggered, [=](){
        this->close();
    });
    // 返回按钮
    MyPushButton* closeBtn = new MyPushButton(":/res/BackButton.png",":/res/BackButtonSelected.png");
    closeBtn->setParent(this);
    // 移到最右下角
    closeBtn->move(this->width() - closeBtn->width(), this->height() - closeBtn->height());
    connect(closeBtn, &QPushButton::clicked, [=](){
        QTimer::singleShot(100, this,[=](){
            this->hide();
            emit this->chooseSceneBack();
        });

    });
   // this->createButton(); // 创建20个关卡
    for(int i = 0 ; i < 20;i++)
    {
        MyPushButton * menuBtn = new MyPushButton(":/res/LevelIcon.png");
        menuBtn->setParent(this);
        menuBtn->move(25 + (i % 4) * 70 , 130+ (i / 4) * 70);
        connect(menuBtn, &QPushButton::clicked, [=](){
            QString str = QString("你选择的是第%1关").arg(i + 1);
            qDebug().noquote() << str;
            this->hide();
            m_pls = new PalySence(i + 1);
            m_pls->show();
            auto outer = this;
            connect(m_pls, &PalySence::isPassed, [=](){
                QLabel * label = new QLabel;

                label->setParent(outer);
                label->setFixedSize(menuBtn->width(), menuBtn->height());
                label->setText("√");
                label->setStyleSheet("color:green; font-size:30px; font: bold 30px;");
                label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter); //设置居中
                label->move(25 + (i % 4) * 70 , 130 + (i / 4) * 70);
                label->setAttribute(Qt::WA_TransparentForMouseEvents,true);
            });
            connect(m_pls, &PalySence::playSenceBack, [=](){
                this->show();
                m_pls->hide();
                delete m_pls;
                m_pls = NULL;
            });

        });

        //按钮上显示的文字
        QLabel * label = new QLabel;
        label->setParent(this);
        label->setFixedSize(menuBtn->width(), menuBtn->height());
        label->setText(QString::number(i + 1));
        label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter); //设置居中
        label->move(25 + (i % 4) * 70 , 130 + (i / 4) * 70);
        label->setAttribute(Qt::WA_TransparentForMouseEvents,true);  //鼠标事件穿透 51号属
    }


}

ChooseLevelSence::~ChooseLevelSence()
{
    delete ui;
}

void ChooseLevelSence::paintEvent(QPaintEvent *){
    // 画背景
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/OtherSceneBg.png");
    painter.drawPixmap(0, 0,this->width(), this->height(), pix);
    // 画背景图标
    pix.load(":res/Title.png");
    pix = pix.scaled(pix.width(), pix.height()); // 缩放
    painter.drawPixmap(10, 30, pix);

}

void ChooseLevelSence::createButton(){
    //创建关卡按钮


}

