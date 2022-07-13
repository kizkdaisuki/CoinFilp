#include "mainsence.h"
#include "ui_mainsence.h"
#include <QPainter>
#include <QDebug>
#include <QPushButton>
#include <QTimer>
#include "mypushbutton.h"
#include "chooselevelsence.h"
MainSence::MainSence(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainSence)
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

    // 画开始按钮
    MyPushButton* startBtn = new MyPushButton(":/res/MenuSceneStartButton.png");
    startBtn->setParent(this);
    startBtn->move(this->width() * 0.5 - startBtn->width() * 0.5, this->height() * 0.7);

    // 跳到选择关卡场景
    m_cls = new ChooseLevelSence;
    connect(startBtn, &QPushButton::clicked, [=](){
        qDebug() << "clicked";
        startBtn->zoom(0);
        startBtn->zoom(1);
        // 延时进入到选择关卡中
        QTimer::singleShot(300,this,[=](){
            this->hide();
            m_cls->show();
        });

    });
    connect(m_cls, &ChooseLevelSence::chooseSceneBack, [=](){
        m_cls->hide();
        this->show();
    });

}

MainSence::~MainSence()
{
    delete ui;
}

void MainSence::paintEvent(QPaintEvent *){
    // 画背景
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/PlayLevelSceneBg.png");
    painter.drawPixmap(0, 0,this->width(), this->height(), pix);
    // 画背景图标
    pix.load(":res/Title.png");
    pix = pix.scaled(pix.width() * 0.5, pix.height() * 0.5); // 缩放
    painter.drawPixmap(10, 30, pix);

}

