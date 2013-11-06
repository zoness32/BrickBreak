/********************************************************************************
** Form generated from reading UI file 'changeuser.ui'
**
** Created: Tue Aug 7 00:47:15 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGEUSER_H
#define UI_CHANGEUSER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFormLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_changeUser
{
public:
    QWidget *centralwidget;
    QWidget *widget;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *usernameEdit;
    QLabel *label_2;
    QListWidget *userList;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_2;
    QWidget *widget1;
    QFormLayout *formLayout_2;
    QPushButton *okBtn;
    QPushButton *cancelBtn;

    void setupUi(QMainWindow *changeUser)
    {
        if (changeUser->objectName().isEmpty())
            changeUser->setObjectName(QString::fromUtf8("changeUser"));
        changeUser->resize(284, 255);
        centralwidget = new QWidget(changeUser);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 10, 258, 181));
        formLayout = new QFormLayout(widget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        usernameEdit = new QLineEdit(widget);
        usernameEdit->setObjectName(QString::fromUtf8("usernameEdit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, usernameEdit);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(3, QFormLayout::SpanningRole, label_2);

        userList = new QListWidget(widget);
        userList->setObjectName(QString::fromUtf8("userList"));

        formLayout->setWidget(4, QFormLayout::SpanningRole, userList);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout->setItem(1, QFormLayout::LabelRole, verticalSpacer);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout->setItem(2, QFormLayout::LabelRole, verticalSpacer_2);

        widget1 = new QWidget(centralwidget);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(110, 220, 158, 25));
        formLayout_2 = new QFormLayout(widget1);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        formLayout_2->setContentsMargins(0, 0, 0, 0);
        okBtn = new QPushButton(widget1);
        okBtn->setObjectName(QString::fromUtf8("okBtn"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, okBtn);

        cancelBtn = new QPushButton(widget1);
        cancelBtn->setObjectName(QString::fromUtf8("cancelBtn"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, cancelBtn);

        changeUser->setCentralWidget(centralwidget);

        retranslateUi(changeUser);

        QMetaObject::connectSlotsByName(changeUser);
    } // setupUi

    void retranslateUi(QMainWindow *changeUser)
    {
        changeUser->setWindowTitle(QApplication::translate("changeUser", "Change User", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("changeUser", "Enter your name:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("changeUser", "Or choose from the list below:", 0, QApplication::UnicodeUTF8));
        okBtn->setText(QApplication::translate("changeUser", "OK", 0, QApplication::UnicodeUTF8));
        cancelBtn->setText(QApplication::translate("changeUser", "Cancel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class changeUser: public Ui_changeUser {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGEUSER_H
