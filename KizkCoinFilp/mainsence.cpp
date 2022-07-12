#include "mainsence.h"
#include "ui_mainsence.h"

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
}

MainSence::~MainSence()
{
    delete ui;
}

