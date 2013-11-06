#ifndef GAMESCREEN_H
#define GAMESCREEN_H

#include <QMainWindow>
#include "timer.h"
#include "Label.h"
#include <QStringList>
#include "quittomainmenu.h"

class Label;
class Timer;

namespace Ui {
    class GameScreen;
}

class GameScreen : public QMainWindow
{
    enum col {BLUE, GREEN, RED, PURPLE};
    enum direction { NORTHEAST, EAST, SOUTHEAST, SOUTHWEST, WEST, NORTHWEST };
    enum difficulty { EASY, MEDIUM, HARD };

    Q_OBJECT

public:
    explicit GameScreen(QWidget *parent = 0);
    ~GameScreen();
    QLine *rtLine;
    bool getSpacePressed();
    QString getEventLog();
    void setEventLog(QString);
    void appendEventLog(QString);
    Label *ball, *paddle;
    int timeLeft, numLives, level, score;
    bool cheatModeActive, spacePressed;
    Timer *time;
    void setLivesText(int i);
    void setScoreText(int i);
    void setLevelText(int i);
    void setTimeText(int i);
    void incScore(int i);
    void decScore(int i);

signals:
    void eventTriggered(QString);
    void gameEnded();

public slots:
    void writeEvent(QString);

private slots:
    void returnToMenu();
    void quitToMenu();
    void keyPressEvent(QKeyEvent *);
    void keyReleaseEvent(QKeyEvent *);
    void mousePressEvent(QMouseEvent *);
    void on_ballSpeedBtn_clicked();
    void on_paddleSpeedBtn_clicked();
    void decrementTimer();
    void gameOver();
    void decrementLives();
    void gameIsWon();
    void saveAndQuit();
    void nextLevel();
    void restartLevel();
    void newLevel(int);

private:
    Ui::GameScreen *ui;
    QMainWindow *tmp;
    QAction *quit, *save;
    QStringList eventList;
    QAbstractItemModel *model;
    void createActions();
    void createMenus();
    void createBall();
    void createPaddle();
    void createBlocks();
    void restartLevel(int);
    void createRow(QPushButton*[], int, int, int);
    void toggleCheatMode(bool);
    void pause();
    void unpause();
    void hideCheatMode();
    const QPoint *eventLogFullSizePos;
    const QPoint *eventLogHalfSizePos;
    QPixmap *paddleIcon, *ballIcon, *gameOverIcon, *gameOverlay, *gameWonIcon;
    QLabel *overlayLbl, *gameOverLbl, *gameWonLbl;
    QPushButton *restart, *returnToMainMenu, *saveAndQuitBtn, *nextLvlBtn, *restartBtn, *mainMenuBtn;
    QuitToMainMenu *menu;
    int rowCount, blocksPerRow, ballSpeed, paddleSpeed;
    difficulty diff;
};

#endif // GAMESCREEN_H
