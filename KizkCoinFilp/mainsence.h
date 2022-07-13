#ifndef MAINSENCE_H
#define MAINSENCE_H

#include <QMainWindow>
#include "chooselevelsence.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainSence; }
QT_END_NAMESPACE

class MainSence : public QMainWindow
{
    Q_OBJECT

public:
    MainSence(QWidget *parent = nullptr);
    ~MainSence();
    void paintEvent(QPaintEvent *);
private:
    Ui::MainSence *ui;
    ChooseLevelSence* m_cls = NULL;
};
#endif // MAINSENCE_H
