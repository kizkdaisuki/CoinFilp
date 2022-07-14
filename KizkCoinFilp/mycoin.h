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
    void changeFlg(int);

public:
    QString m_btnImgPath;
    bool m_flg;
    int m_i_l = 1; // 图片为金币
    int m_i_r = 8; // 图片为银币
    bool m_b_isAnimation = false;
    bool m_b_isWin = false;
    QTimer* timer1; // 正面 -> 反面
    QTimer* timer2; // 反面 -> 正面
    void mousePressEvent(QMouseEvent *e);



signals:



};

#endif // MYCOIN_H
