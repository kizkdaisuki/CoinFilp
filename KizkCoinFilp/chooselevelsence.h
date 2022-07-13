#ifndef CHOOSELEVELSENCE_H
#define CHOOSELEVELSENCE_H

#include <QMainWindow>
#include "palysence.h"

namespace Ui {
class ChooseLevelSence;
}

class ChooseLevelSence : public QMainWindow
{
    Q_OBJECT

public:
    explicit ChooseLevelSence(QWidget *parent = nullptr);
    ~ChooseLevelSence();
    void paintEvent(QPaintEvent *);
    void createButton();
private:
    Ui::ChooseLevelSence *ui;
public:
    PalySence* m_pls = NULL;
signals:
    void chooseSceneBack();
};

#endif // CHOOSELEVELSENCE_H
