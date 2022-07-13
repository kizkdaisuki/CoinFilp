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
    bool checkOver();
private:
    Ui::PalySence *ui;
signals:
    void playSenceBack();
public:
    int g[10][10];
    int m_id;
    Mycoin* coinBtn[4][4];


};

#endif // PALYSENCE_H
