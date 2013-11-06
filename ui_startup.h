/********************************************************************************
** Form generated from reading UI file 'startup.ui'
**
** Created: Tue Nov 15 21:20:26 2011
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STARTUP_H
#define UI_STARTUP_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFormLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_startup
{
public:
    QWidget *centralWidget;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QPushButton *newGameBtn;
    QPushButton *optionsBtn;
    QPushButton *helpBtn;
    QPushButton *loadGameBtn;
    QPushButton *quitBtn;
    QLabel *label;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *startup)
    {
        if (startup->objectName().isEmpty())
            startup->setObjectName(QString::fromUtf8("startup"));
        startup->resize(397, 380);
        centralWidget = new QWidget(startup);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        formLayoutWidget = new QWidget(centralWidget);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(110, 260, 160, 61));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        formLayout->setContentsMargins(0, 0, 0, 0);
        newGameBtn = new QPushButton(formLayoutWidget);
        newGameBtn->setObjectName(QString::fromUtf8("newGameBtn"));

        formLayout->setWidget(0, QFormLayout::LabelRole, newGameBtn);

        optionsBtn = new QPushButton(formLayoutWidget);
        optionsBtn->setObjectName(QString::fromUtf8("optionsBtn"));

        formLayout->setWidget(1, QFormLayout::LabelRole, optionsBtn);

        helpBtn = new QPushButton(formLayoutWidget);
        helpBtn->setObjectName(QString::fromUtf8("helpBtn"));

        formLayout->setWidget(0, QFormLayout::FieldRole, helpBtn);

        loadGameBtn = new QPushButton(formLayoutWidget);
        loadGameBtn->setObjectName(QString::fromUtf8("loadGameBtn"));

        formLayout->setWidget(1, QFormLayout::FieldRole, loadGameBtn);

        quitBtn = new QPushButton(centralWidget);
        quitBtn->setObjectName(QString::fromUtf8("quitBtn"));
        quitBtn->setGeometry(QRect(150, 320, 77, 23));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(90, 30, 211, 211));
        label->setPixmap(QPixmap(QString::fromUtf8("mainscreen.jpg")));
        startup->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(startup);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 397, 21));
        startup->setMenuBar(menuBar);

        retranslateUi(startup);
        QObject::connect(quitBtn, SIGNAL(clicked()), startup, SLOT(close()));

        QMetaObject::connectSlotsByName(startup);
    } // setupUi

    void retranslateUi(QMainWindow *startup)
    {
        startup->setWindowTitle(QApplication::translate("startup", "Brick Break", 0, QApplication::UnicodeUTF8));
        newGameBtn->setText(QApplication::translate("startup", "New Game", 0, QApplication::UnicodeUTF8));
        optionsBtn->setText(QApplication::translate("startup", "Difficulty", 0, QApplication::UnicodeUTF8));
        helpBtn->setText(QApplication::translate("startup", "Instructions", 0, QApplication::UnicodeUTF8));
        loadGameBtn->setText(QApplication::translate("startup", "Load Game", 0, QApplication::UnicodeUTF8));
        quitBtn->setText(QApplication::translate("startup", "Quit", 0, QApplication::UnicodeUTF8));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class startup: public Ui_startup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STARTUP_H
