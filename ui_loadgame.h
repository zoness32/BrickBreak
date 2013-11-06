/********************************************************************************
** Form generated from reading UI file 'loadgame.ui'
**
** Created: Fri Nov 11 11:43:42 2011
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOADGAME_H
#define UI_LOADGAME_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHeaderView>
#include <QtGui/QScrollArea>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoadGame
{
public:
    QDialogButtonBox *buttonBox;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;

    void setupUi(QDialog *LoadGame)
    {
        if (LoadGame->objectName().isEmpty())
            LoadGame->setObjectName(QString::fromUtf8("LoadGame"));
        LoadGame->resize(390, 245);
        buttonBox = new QDialogButtonBox(LoadGame);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(200, 200, 171, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        scrollArea = new QScrollArea(LoadGame);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(20, 20, 351, 151));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 349, 149));
        scrollArea->setWidget(scrollAreaWidgetContents);

        retranslateUi(LoadGame);
        QObject::connect(buttonBox, SIGNAL(accepted()), LoadGame, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), LoadGame, SLOT(reject()));

        QMetaObject::connectSlotsByName(LoadGame);
    } // setupUi

    void retranslateUi(QDialog *LoadGame)
    {
        LoadGame->setWindowTitle(QApplication::translate("LoadGame", "Load Game", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class LoadGame: public Ui_LoadGame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOADGAME_H
