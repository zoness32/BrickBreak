/********************************************************************************
** Form generated from reading UI file 'cheatmode.ui'
**
** Created: Tue Nov 15 21:20:26 2011
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHEATMODE_H
#define UI_CHEATMODE_H

#include <QtCore/QVariant>
#include <QAction>
#include <QApplication>
#include <QButtonGroup>
#include <QDialog>
#include <QDialogButtonBox>
#include <QHeaderView>
#include <QLabel>
#include <QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_CheatMode
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *paddleSpeedLbl;
    QLineEdit *paddleSpeedEdit;
    QLabel *ballSpeedLbl;
    QLineEdit *ballSpeedEdit;

    void setupUi(QDialog *CheatMode)
    {
        if (CheatMode->objectName().isEmpty())
            CheatMode->setObjectName(QString::fromUtf8("CheatMode"));
        CheatMode->resize(269, 117);
        buttonBox = new QDialogButtonBox(CheatMode);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(90, 70, 161, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        paddleSpeedLbl = new QLabel(CheatMode);
        paddleSpeedLbl->setObjectName(QString::fromUtf8("paddleSpeedLbl"));
        paddleSpeedLbl->setGeometry(QRect(10, 40, 111, 16));
        paddleSpeedEdit = new QLineEdit(CheatMode);
        paddleSpeedEdit->setObjectName(QString::fromUtf8("paddleSpeedEdit"));
        paddleSpeedEdit->setGeometry(QRect(130, 40, 113, 20));
        ballSpeedLbl = new QLabel(CheatMode);
        ballSpeedLbl->setObjectName(QString::fromUtf8("ballSpeedLbl"));
        ballSpeedLbl->setGeometry(QRect(10, 10, 91, 16));
        ballSpeedEdit = new QLineEdit(CheatMode);
        ballSpeedEdit->setObjectName(QString::fromUtf8("ballSpeedEdit"));
        ballSpeedEdit->setGeometry(QRect(130, 10, 113, 20));

        retranslateUi(CheatMode);

        QMetaObject::connectSlotsByName(CheatMode);
    } // setupUi

    void retranslateUi(QDialog *CheatMode)
    {
        CheatMode->setWindowTitle(QApplication::translate("CheatMode", "Dialog", 0));
        paddleSpeedLbl->setText(QApplication::translate("CheatMode", "Change Paddle Speed:", 0));
        ballSpeedLbl->setText(QApplication::translate("CheatMode", "Change Ball Speed:", 0));
    } // retranslateUi

};

namespace Ui {
    class CheatMode: public Ui_CheatMode {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHEATMODE_H
