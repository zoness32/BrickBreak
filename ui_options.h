/********************************************************************************
** Form generated from reading UI file 'options.ui'
**
** Created: Tue Nov 15 21:20:26 2011
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPTIONS_H
#define UI_OPTIONS_H

#include <QtCore/QVariant>
#include <QAction>
#include <QApplication>
#include <QButtonGroup>
#include <QDialog>
#include <QDialogButtonBox>
#include <QHeaderView>
#include <QLabel>
#include <QSlider>

QT_BEGIN_NAMESPACE

class Ui_Options
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *difficultyLbl;
    QSlider *difficultySlider;

    void setupUi(QDialog *Options)
    {
        if (Options->objectName().isEmpty())
            Options->setObjectName(QString::fromUtf8("Options"));
        Options->resize(301, 151);
        buttonBox = new QDialogButtonBox(Options);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(110, 110, 171, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        difficultyLbl = new QLabel(Options);
        difficultyLbl->setObjectName(QString::fromUtf8("difficultyLbl"));
        difficultyLbl->setGeometry(QRect(10, 30, 91, 16));
        difficultySlider = new QSlider(Options);
        difficultySlider->setObjectName(QString::fromUtf8("difficultySlider"));
        difficultySlider->setGeometry(QRect(110, 30, 81, 19));
        difficultySlider->setMinimum(1);
        difficultySlider->setMaximum(3);
        difficultySlider->setOrientation(Qt::Horizontal);

        retranslateUi(Options);
        QObject::connect(buttonBox, SIGNAL(accepted()), Options, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Options, SLOT(reject()));

        QMetaObject::connectSlotsByName(Options);
    } // setupUi

    void retranslateUi(QDialog *Options)
    {
        Options->setWindowTitle(QApplication::translate("Options", "Difficulty", 0));
        difficultyLbl->setText(QApplication::translate("Options", "Difficulty: Easy", 0));
    } // retranslateUi

};

namespace Ui {
    class Options: public Ui_Options {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPTIONS_H
