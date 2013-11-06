/********************************************************************************
** Form generated from reading UI file 'quittomainmenu.ui'
**
** Created: Tue Nov 15 21:20:26 2011
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QUITTOMAINMENU_H
#define UI_QUITTOMAINMENU_H

#include <QtCore/QVariant>
#include <QAction>
#include <QApplication>
#include <QButtonGroup>
#include <QDialog>
#include <QDialogButtonBox>
#include <QHeaderView>
#include <QLabel>

QT_BEGIN_NAMESPACE

class Ui_QuitToMainMenu
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;

    void setupUi(QDialog *QuitToMainMenu)
    {
        if (QuitToMainMenu->objectName().isEmpty())
            QuitToMainMenu->setObjectName(QString::fromUtf8("QuitToMainMenu"));
        QuitToMainMenu->resize(227, 66);
        buttonBox = new QDialogButtonBox(QuitToMainMenu);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(60, 30, 161, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::No|QDialogButtonBox::Yes);
        label = new QLabel(QuitToMainMenu);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 211, 20));
        QFont font;
        font.setFamily(QString::fromUtf8("MS Shell Dlg 2"));
        font.setPointSize(11);
        font.setBold(false);
        font.setWeight(50);
        label->setFont(font);

        retranslateUi(QuitToMainMenu);
        QObject::connect(buttonBox, SIGNAL(accepted()), QuitToMainMenu, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), QuitToMainMenu, SLOT(reject()));

        QMetaObject::connectSlotsByName(QuitToMainMenu);
    } // setupUi

    void retranslateUi(QDialog *QuitToMainMenu)
    {
        QuitToMainMenu->setWindowTitle(QApplication::translate("QuitToMainMenu", "Dialog", 0));
        label->setText(QApplication::translate("QuitToMainMenu", "Are you sure you want to quit?", 0));
    } // retranslateUi

};

namespace Ui {
    class QuitToMainMenu: public Ui_QuitToMainMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QUITTOMAINMENU_H
