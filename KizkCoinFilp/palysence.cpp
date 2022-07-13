#include "palysence.h"
#include "ui_palysence.h"
#include "mypushbutton.h"
#include "mycoin.h"
#include <QTimer>
#include <QDebug>
#include <QPushButton>

PalySence::PalySence(int id, QWidget *parent)  :
    QMainWindow(parent),
    ui(new Ui::PalySence)
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
    qDebug() << "back";
    closeBtn->move(this->width() - closeBtn->width(), this->height() - closeBtn->height());
    connect(closeBtn, &QPushButton::clicked, [=](){
        QTimer::singleShot(100, this,[=](){
            emit this->playSenceBack();
        });
    });
    initSenceBack();
    initSence(id);
}

PalySence::~PalySence()
{
    delete ui;
}

void PalySence::initSence(int id){

    int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

    dataConfig dataMap;
    for(int i = 0; i < 4; i ++)
        for(int j = 0; j < 4; j ++)
           g[i][j] = dataMap.mData[id][i][j];
    for(int i = 0; i < 4; i ++)
       for(int j = 0; j < 4; j ++)
       {
           QString str = "";
           if(this->g[i][j])
               str = ":/res/Coin0001.png";
           else str = ":/res/Coin0008.png";
           Mycoin* coinBtn = new Mycoin(str);
           coinBtn->setParent(this);
           coinBtn->move(60 + 50 * i, 200 + 50 * j);
           coinBtn->m_flg = g[i][j];
           this->coinBtn[i][j] = coinBtn;
           connect(coinBtn, &QPushButton::clicked, [=](){
               qDebug() << "click the coin";
               this->coinBtn[i][j]->changeFlg(40);
               g[i][j] ^= 1;
               for(int k = 0; k < 4; k ++)
               {
                   int a = dx[k] + i, b = dy[k] + j;
                   if(a < 0 || b < 0 || a > 4 || b > 4)
                       continue;
                   g[a][b] ^= 1;
                   this->coinBtn[a][b]->changeFlg(40);
               }
           });
       }
}

void PalySence::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/MenuSceneBg.png");
    painter.drawPixmap(0, 0, this->width(), this->height(), pix);

}

void PalySence::initSenceBack(){
    for(int i = 0; i < 4; i ++)
        for(int j = 0; j < 4; j ++)
        {
            MyPushButton* gameBtn = new MyPushButton(":/res/BoardNode.png");
            gameBtn->setParent(this);
            int i_width = gameBtn->width(), i_height = gameBtn->height();
            gameBtn->move(60 + i_width * i, 200 + j * i_height);

        }
}


bool PalySence::checkOver(){
    return true;
}
