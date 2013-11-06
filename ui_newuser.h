/********************************************************************************
** Form generated from reading UI file 'newuser.ui'
**
** Created: Thu Nov 10 18:58:22 2011
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWUSER_H
#define UI_NEWUSER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QSlider>

QT_BEGIN_NAMESPACE

class Ui_newUser
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *enterNameLbl;
    QLineEdit *userNameEdit;
    QLabel *difficultyLbl;
    QSlider *difficultySlider;

    void setupUi(QDialog *newUser)
    {
        if (newUser->objectName().isEmpty())
            newUser->setObjectName(QString::fromUtf8("newUser"));
        newUser->resize(293, 157);
        buttonBox = new QDialogButtonBox(newUser);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(120, 120, 161, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        enterNameLbl = new QLabel(newUser);
        enterNameLbl->setObjectName(QString::fromUtf8("enterNameLbl"));
        enterNameLbl->setGeometry(QRect(10, 10, 91, 16));
        userNameEdit = new QLineEdit(newUser);
        userNameEdit->setObjectName(QString::fromUtf8("userNameEdit"));
        userNameEdit->setGeometry(QRect(110, 10, 113, 20));
        difficultyLbl = new QLabel(newUser);
        difficultyLbl->setObjectName(QString::fromUtf8("difficultyLbl"));
        difficultyLbl->setGeometry(QRect(10, 40, 91, 16));
        difficultySlider = new QSlider(newUser);
        difficultySlider->setObjectName(QString::fromUtf8("difficultySlider"));
        difficultySlider->setGeometry(QRect(110, 40, 81, 19));
        difficultySlider->setMinimum(1);
        difficultySlider->setMaximum(3);
        difficultySlider->setOrientation(Qt::Horizontal);

        retranslateUi(newUser);
        QObject::connect(buttonBox, SIGNAL(accepted()), newUser, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), newUser, SLOT(reject()));

        QMetaObject::connectSlotsByName(newUser);
    } // setupUi

    void retranslateUi(QDialog *newUser)
    {
        newUser->setWindowTitle(QApplication::translate("newUser", "Dialog", 0, QApplication::UnicodeUTF8));
        enterNameLbl->setText(QApplication::translate("newUser", "Enter your name:", 0, QApplication::UnicodeUTF8));
        difficultyLbl->setText(QApplication::translate("newUser", "Difficulty: Easy", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class newUser: public Ui_newUser {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWUSER_H
