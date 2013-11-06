#ifndef STARTUP_H
#define STARTUP_H

#include <QMainWindow>
#include "options.h"
#include "help.h"
#include "gamescreen.h"

namespace Ui {
    class startup;
}

class startup : public QMainWindow
{
    Q_OBJECT

public:
    explicit startup(QWidget *parent = 0);
    ~startup();
    void openNewUserWindow();

public slots:
    void saveGame();
    void loadGame();

private slots:
    void on_optionsBtn_clicked();
    void on_helpBtn_clicked();
    void on_newGameBtn_clicked();
    void restartGame();

    void on_loadGameBtn_clicked();

private:
    Ui::startup *ui;
    Options *optionsUi;
    help *helpUi;
    GameScreen *gameScreen;
};

#endif // STARTUP_H
