#ifndef LOADGAME_H
#define LOADGAME_H

#include <QDialog>

namespace Ui {
    class LoadGame;
}

class LoadGame : public QDialog
{
    Q_OBJECT

public:
    explicit LoadGame(QWidget *parent = 0);
    ~LoadGame();

private:
    Ui::LoadGame *ui;
};

#endif // LOADGAME_H
