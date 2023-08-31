/********************************************************************************
** Form generated from reading UI file 'buttongroup.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BUTTONGROUP_H
#define UI_BUTTONGROUP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "mybutton.h"

QT_BEGIN_NAMESPACE

class Ui_ButtonGroup
{
public:
    QVBoxLayout *verticalLayout;
    QStackedWidget *stackedWidget;
    QWidget *startPage;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    MyButton *startGame;
    QSpacerItem *horizontalSpacer_2;
    QWidget *playPage1;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_9;
    MyButton *playHand1;
    QSpacerItem *horizontalSpacer_10;
    QWidget *playPage2;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_5;
    MyButton *pass;
    MyButton *playHand2;
    QSpacerItem *horizontalSpacer_6;
    QWidget *betPage;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_7;
    MyButton *giveup;
    MyButton *bet1;
    MyButton *bet2;
    MyButton *bet3;
    QSpacerItem *horizontalSpacer_8;
    QWidget *nullPage;

    void setupUi(QWidget *ButtonGroup)
    {
        if (ButtonGroup->objectName().isEmpty())
            ButtonGroup->setObjectName(QString::fromUtf8("ButtonGroup"));
        ButtonGroup->resize(429, 50);
        verticalLayout = new QVBoxLayout(ButtonGroup);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        stackedWidget = new QStackedWidget(ButtonGroup);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        startPage = new QWidget();
        startPage->setObjectName(QString::fromUtf8("startPage"));
        horizontalLayout = new QHBoxLayout(startPage);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(126, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        startGame = new MyButton(startPage);
        startGame->setObjectName(QString::fromUtf8("startGame"));

        horizontalLayout->addWidget(startGame);

        horizontalSpacer_2 = new QSpacerItem(126, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        stackedWidget->addWidget(startPage);
        playPage1 = new QWidget();
        playPage1->setObjectName(QString::fromUtf8("playPage1"));
        horizontalLayout_5 = new QHBoxLayout(playPage1);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalSpacer_9 = new QSpacerItem(126, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_9);

        playHand1 = new MyButton(playPage1);
        playHand1->setObjectName(QString::fromUtf8("playHand1"));

        horizontalLayout_5->addWidget(playHand1);

        horizontalSpacer_10 = new QSpacerItem(126, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_10);

        stackedWidget->addWidget(playPage1);
        playPage2 = new QWidget();
        playPage2->setObjectName(QString::fromUtf8("playPage2"));
        horizontalLayout_3 = new QHBoxLayout(playPage2);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);

        pass = new MyButton(playPage2);
        pass->setObjectName(QString::fromUtf8("pass"));

        horizontalLayout_3->addWidget(pass);

        playHand2 = new MyButton(playPage2);
        playHand2->setObjectName(QString::fromUtf8("playHand2"));

        horizontalLayout_3->addWidget(playHand2);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_6);

        stackedWidget->addWidget(playPage2);
        betPage = new QWidget();
        betPage->setObjectName(QString::fromUtf8("betPage"));
        horizontalLayout_4 = new QHBoxLayout(betPage);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_7);

        giveup = new MyButton(betPage);
        giveup->setObjectName(QString::fromUtf8("giveup"));

        horizontalLayout_4->addWidget(giveup);

        bet1 = new MyButton(betPage);
        bet1->setObjectName(QString::fromUtf8("bet1"));

        horizontalLayout_4->addWidget(bet1);

        bet2 = new MyButton(betPage);
        bet2->setObjectName(QString::fromUtf8("bet2"));

        horizontalLayout_4->addWidget(bet2);

        bet3 = new MyButton(betPage);
        bet3->setObjectName(QString::fromUtf8("bet3"));

        horizontalLayout_4->addWidget(bet3);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_8);

        stackedWidget->addWidget(betPage);
        nullPage = new QWidget();
        nullPage->setObjectName(QString::fromUtf8("nullPage"));
        stackedWidget->addWidget(nullPage);

        verticalLayout->addWidget(stackedWidget);


        retranslateUi(ButtonGroup);

        stackedWidget->setCurrentIndex(4);


        QMetaObject::connectSlotsByName(ButtonGroup);
    } // setupUi

    void retranslateUi(QWidget *ButtonGroup)
    {
        ButtonGroup->setWindowTitle(QCoreApplication::translate("ButtonGroup", "Form", nullptr));
        startGame->setText(QCoreApplication::translate("ButtonGroup", "\345\274\200\345\247\213\346\270\270\346\210\217", nullptr));
        playHand1->setText(QCoreApplication::translate("ButtonGroup", "\345\207\272\347\211\214", nullptr));
        pass->setText(QCoreApplication::translate("ButtonGroup", "\344\270\215 \350\246\201", nullptr));
        playHand2->setText(QCoreApplication::translate("ButtonGroup", "\345\207\272 \347\211\214", nullptr));
        giveup->setText(QCoreApplication::translate("ButtonGroup", "\344\270\215 \345\217\253", nullptr));
        bet1->setText(QCoreApplication::translate("ButtonGroup", "1 \345\210\206", nullptr));
        bet2->setText(QCoreApplication::translate("ButtonGroup", "2 \345\210\206", nullptr));
        bet3->setText(QCoreApplication::translate("ButtonGroup", "3 \345\210\206", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ButtonGroup: public Ui_ButtonGroup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BUTTONGROUP_H
