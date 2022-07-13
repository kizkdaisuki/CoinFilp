#ifndef MYCOIN_H
#define MYCOIN_H

#include <QPushButton>

class Mycoin : public QPushButton
{
    Q_OBJECT
public:
//    explicit Mycoin(QWidget *parent = nullptr);
    Mycoin(QString btnImg);
    void setImg(QString);
    void turnCoin(int, int);
    void turn(int, int);
    void changeFlg(int);
public:
    QString m_btnImgPath;
    bool m_flg;
    int m_x;
    int m_y;
    int min = 1; // 图片为金币
    int max = 8; // 图片为银币
    bool isAnimation = false;
    bool notPress = false;
    QTimer* timer1; // 正面 -> 反面
    QTimer* timer2; // 反面 -> 正面
    void mousePressEvent(QMouseEvent *e);
signals:

};

#endif // MYCOIN_H
