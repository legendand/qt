/********************************************************************************
** Form generated from reading UI file 'scorepanel.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCOREPANEL_H
#define UI_SCOREPANEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ScorePanel
{
public:
    QWidget *gridWidget;
    QGridLayout *gridLayout;
    QLabel *fen2;
    QLabel *fen3;
    QLabel *me;
    QLabel *left;
    QLabel *right;
    QLabel *fen1;
    QLabel *meScore;
    QLabel *leftScore;
    QLabel *rightScore;

    void setupUi(QWidget *ScorePanel)
    {
        if (ScorePanel->objectName().isEmpty())
            ScorePanel->setObjectName(QString::fromUtf8("ScorePanel"));
        ScorePanel->resize(251, 144);
        gridWidget = new QWidget(ScorePanel);
        gridWidget->setObjectName(QString::fromUtf8("gridWidget"));
        gridWidget->setGeometry(QRect(90, 10, 161, 131));
        gridLayout = new QGridLayout(gridWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        fen2 = new QLabel(gridWidget);
        fen2->setObjectName(QString::fromUtf8("fen2"));

        gridLayout->addWidget(fen2, 2, 2, 1, 1);

        fen3 = new QLabel(gridWidget);
        fen3->setObjectName(QString::fromUtf8("fen3"));

        gridLayout->addWidget(fen3, 3, 2, 1, 1);

        me = new QLabel(gridWidget);
        me->setObjectName(QString::fromUtf8("me"));

        gridLayout->addWidget(me, 1, 0, 1, 1);

        left = new QLabel(gridWidget);
        left->setObjectName(QString::fromUtf8("left"));

        gridLayout->addWidget(left, 2, 0, 1, 1);

        right = new QLabel(gridWidget);
        right->setObjectName(QString::fromUtf8("right"));

        gridLayout->addWidget(right, 3, 0, 1, 1);

        fen1 = new QLabel(gridWidget);
        fen1->setObjectName(QString::fromUtf8("fen1"));

        gridLayout->addWidget(fen1, 1, 2, 1, 1);

        meScore = new QLabel(gridWidget);
        meScore->setObjectName(QString::fromUtf8("meScore"));

        gridLayout->addWidget(meScore, 1, 1, 1, 1);

        leftScore = new QLabel(gridWidget);
        leftScore->setObjectName(QString::fromUtf8("leftScore"));

        gridLayout->addWidget(leftScore, 2, 1, 1, 1);

        rightScore = new QLabel(gridWidget);
        rightScore->setObjectName(QString::fromUtf8("rightScore"));

        gridLayout->addWidget(rightScore, 3, 1, 1, 1);


        retranslateUi(ScorePanel);

        QMetaObject::connectSlotsByName(ScorePanel);
    } // setupUi

    void retranslateUi(QWidget *ScorePanel)
    {
        ScorePanel->setWindowTitle(QCoreApplication::translate("ScorePanel", "Form", nullptr));
        fen2->setText(QCoreApplication::translate("ScorePanel", "\345\210\206", nullptr));
        fen3->setText(QCoreApplication::translate("ScorePanel", "\345\210\206", nullptr));
        me->setText(QCoreApplication::translate("ScorePanel", "\346\210\221\357\274\232", nullptr));
        left->setText(QCoreApplication::translate("ScorePanel", "\345\267\246\346\234\272\345\231\250\344\272\272\357\274\232", nullptr));
        right->setText(QCoreApplication::translate("ScorePanel", "\345\217\263\346\234\272\345\231\250\344\272\272\357\274\232", nullptr));
        fen1->setText(QCoreApplication::translate("ScorePanel", "\345\210\206", nullptr));
        meScore->setText(QString());
        leftScore->setText(QString());
        rightScore->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ScorePanel: public Ui_ScorePanel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCOREPANEL_H
