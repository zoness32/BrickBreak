/********************************************************************************
** Form generated from reading UI file 'help.ui'
**
** Created: Tue Nov 15 21:20:26 2011
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HELP_H
#define UI_HELP_H

#include <QtCore/QVariant>
//#include <QtGui/QAction>
#include <QApplication>
#include <QButtonGroup>
#include <QDialog>
#include <QHeaderView>
#include <QPushButton>

QT_BEGIN_NAMESPACE

class Ui_help
{
public:
    QPushButton *okayBtn;

    void setupUi(QDialog *help)
    {
        if (help->objectName().isEmpty())
            help->setObjectName(QString::fromUtf8("help"));
        help->resize(400, 300);
        okayBtn = new QPushButton(help);
        okayBtn->setObjectName(QString::fromUtf8("okayBtn"));
        okayBtn->setGeometry(QRect(310, 260, 75, 23));

        retranslateUi(help);

        QMetaObject::connectSlotsByName(help);
    } // setupUi

    void retranslateUi(QDialog *help)
    {
        help->setWindowTitle(QApplication::translate("help", "Instructions", 0));
        okayBtn->setText(QApplication::translate("help", "OK", 0));
    } // retranslateUi

};

namespace Ui {
    class help: public Ui_help {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HELP_H
