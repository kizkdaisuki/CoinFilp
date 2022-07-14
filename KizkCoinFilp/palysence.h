#ifndef PALYSENCE_H
#define PALYSENCE_H

#include <QMainWindow>
#include <QPainter>
#include <vector>
#include "dataconfig.h"
#include "mycoin.h"
namespace Ui {
class PalySence;
}

class PalySence : public QMainWindow
{
    Q_OBJECT

public:
    explicit PalySence(int id, QWidget *parent = nullptr);
//    PalySence(int id);
    ~PalySence();
    void initSence(int);
    void paintEvent(QPaintEvent *event);
    void initSenceBack();
    bool checkGameOver();
    void solve();
    void turn(int, int);
    template<typename T>
        T getMin(T a, T b);
private:
    Ui::PalySence *ui;
signals:
    void playSenceBack();
    void isPassed();
public:
    int g[10][10];
    int g1[10][10];
    int m_id;
    Mycoin* coinBtn[10][10];
private:
   const int Inf = 0x3f3f3f3f;
   int m_i_minOp;
};

#endif // PALYSENCE_H
