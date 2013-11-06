/********************************************************************************
** Form generated from reading UI file 'gamescreen.ui'
**
** Created: Tue Nov 15 21:20:26 2011
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMESCREEN_H
#define UI_GAMESCREEN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTextEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GameScreen
{
public:
    QWidget *centralwidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *levelLbl;
    QSpacerItem *horizontalSpacer;
    QLabel *scoreLbl;
    QSpacerItem *horizontalSpacer_2;
    QLabel *livesLbl;
    QSpacerItem *horizontalSpacer_3;
    QLabel *timeLbl;
    QFrame *bottomLine;
    QFrame *rightLine;
    QLabel *paddleSpeedLbl;
    QLineEdit *ballSpeedEdit;
    QLineEdit *paddleSpeedEdit;
    QLabel *ballSpeedLbl;
    QPushButton *ballSpeedBtn;
    QPushButton *paddleSpeedBtn;
    QLabel *infoLbl;
    QTextEdit *textEdit;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *GameScreen)
    {
        if (GameScreen->objectName().isEmpty())
            GameScreen->setObjectName(QString::fromUtf8("GameScreen"));
        GameScreen->resize(523, 559);
        centralwidget = new QWidget(GameScreen);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 510, 281, 22));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        levelLbl = new QLabel(horizontalLayoutWidget);
        levelLbl->setObjectName(QString::fromUtf8("levelLbl"));

        horizontalLayout->addWidget(levelLbl);

        horizontalSpacer = new QSpacerItem(18, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        scoreLbl = new QLabel(horizontalLayoutWidget);
        scoreLbl->setObjectName(QString::fromUtf8("scoreLbl"));

        horizontalLayout->addWidget(scoreLbl);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        livesLbl = new QLabel(horizontalLayoutWidget);
        livesLbl->setObjectName(QString::fromUtf8("livesLbl"));

        horizontalLayout->addWidget(livesLbl);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        timeLbl = new QLabel(horizontalLayoutWidget);
        timeLbl->setObjectName(QString::fromUtf8("timeLbl"));

        horizontalLayout->addWidget(timeLbl);

        bottomLine = new QFrame(centralwidget);
        bottomLine->setObjectName(QString::fromUtf8("bottomLine"));
        bottomLine->setGeometry(QRect(0, 500, 301, 2));
        bottomLine->setFrameShape(QFrame::HLine);
        bottomLine->setFrameShadow(QFrame::Sunken);
        rightLine = new QFrame(centralwidget);
        rightLine->setObjectName(QString::fromUtf8("rightLine"));
        rightLine->setGeometry(QRect(300, 0, 2, 500));
        rightLine->setFrameShape(QFrame::VLine);
        rightLine->setFrameShadow(QFrame::Sunken);
        paddleSpeedLbl = new QLabel(centralwidget);
        paddleSpeedLbl->setObjectName(QString::fromUtf8("paddleSpeedLbl"));
        paddleSpeedLbl->setGeometry(QRect(380, 120, 111, 16));
        ballSpeedEdit = new QLineEdit(centralwidget);
        ballSpeedEdit->setObjectName(QString::fromUtf8("ballSpeedEdit"));
        ballSpeedEdit->setGeometry(QRect(380, 60, 113, 20));
        paddleSpeedEdit = new QLineEdit(centralwidget);
        paddleSpeedEdit->setObjectName(QString::fromUtf8("paddleSpeedEdit"));
        paddleSpeedEdit->setGeometry(QRect(380, 140, 113, 20));
        ballSpeedLbl = new QLabel(centralwidget);
        ballSpeedLbl->setObjectName(QString::fromUtf8("ballSpeedLbl"));
        ballSpeedLbl->setGeometry(QRect(380, 40, 91, 16));
        ballSpeedBtn = new QPushButton(centralwidget);
        ballSpeedBtn->setObjectName(QString::fromUtf8("ballSpeedBtn"));
        ballSpeedBtn->setGeometry(QRect(420, 90, 75, 23));
        paddleSpeedBtn = new QPushButton(centralwidget);
        paddleSpeedBtn->setObjectName(QString::fromUtf8("paddleSpeedBtn"));
        paddleSpeedBtn->setGeometry(QRect(420, 170, 75, 23));
        infoLbl = new QLabel(centralwidget);
        infoLbl->setObjectName(QString::fromUtf8("infoLbl"));
        infoLbl->setGeometry(QRect(320, 10, 181, 16));
        QFont font;
        font.setPointSize(16);
        infoLbl->setFont(font);
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(310, 200, 201, 301));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Times New Roman"));
        font1.setPointSize(8);
        textEdit->setFont(font1);
        textEdit->setFocusPolicy(Qt::NoFocus);
        textEdit->setReadOnly(true);
        textEdit->setAcceptRichText(false);
        textEdit->setTextInteractionFlags(Qt::NoTextInteraction);
        GameScreen->setCentralWidget(centralwidget);
        menuBar = new QMenuBar(GameScreen);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 523, 21));
        GameScreen->setMenuBar(menuBar);

        retranslateUi(GameScreen);

        QMetaObject::connectSlotsByName(GameScreen);
    } // setupUi

    void retranslateUi(QMainWindow *GameScreen)
    {
        GameScreen->setWindowTitle(QApplication::translate("GameScreen", "Brick Break: Level 1", 0, QApplication::UnicodeUTF8));
        levelLbl->setText(QApplication::translate("GameScreen", "Level:", 0, QApplication::UnicodeUTF8));
        scoreLbl->setText(QApplication::translate("GameScreen", "Score:", 0, QApplication::UnicodeUTF8));
        livesLbl->setText(QApplication::translate("GameScreen", "Lives Left:", 0, QApplication::UnicodeUTF8));
        timeLbl->setText(QApplication::translate("GameScreen", "Time:", 0, QApplication::UnicodeUTF8));
        paddleSpeedLbl->setText(QApplication::translate("GameScreen", "Change Paddle Speed:", 0, QApplication::UnicodeUTF8));
        ballSpeedLbl->setText(QApplication::translate("GameScreen", "Change Ball Speed:", 0, QApplication::UnicodeUTF8));
        ballSpeedBtn->setText(QApplication::translate("GameScreen", "Submit", 0, QApplication::UnicodeUTF8));
        paddleSpeedBtn->setText(QApplication::translate("GameScreen", "Submit", 0, QApplication::UnicodeUTF8));
        infoLbl->setText(QApplication::translate("GameScreen", "Press 'C' To Exit", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class GameScreen: public Ui_GameScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMESCREEN_H
