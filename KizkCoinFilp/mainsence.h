#ifndef MAINSENCE_H
#define MAINSENCE_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainSence; }
QT_END_NAMESPACE

class MainSence : public QMainWindow
{
    Q_OBJECT

public:
    MainSence(QWidget *parent = nullptr);
    ~MainSence();

private:
    Ui::MainSence *ui;
};
#endif // MAINSENCE_H
