/********************************************************************************
** Form generated from reading UI file 'showingplayers.ui'
**
** Created by: Qt User Interface Compiler version 6.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOWINGPLAYERS_H
#define UI_SHOWINGPLAYERS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ShowingPlayers
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QListWidget *listWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_select_player;
    QPushButton *pushButton_exit;
    QPushButton *pushButton_check_for_challanges;
    QPushButton *pushButton_refresh;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *ShowingPlayers)
    {
        if (ShowingPlayers->objectName().isEmpty())
            ShowingPlayers->setObjectName(QString::fromUtf8("ShowingPlayers"));
        ShowingPlayers->resize(461, 381);
        gridLayout = new QGridLayout(ShowingPlayers);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        listWidget = new QListWidget(ShowingPlayers);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));

        verticalLayout->addWidget(listWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton_select_player = new QPushButton(ShowingPlayers);
        pushButton_select_player->setObjectName(QString::fromUtf8("pushButton_select_player"));

        horizontalLayout->addWidget(pushButton_select_player);


        verticalLayout->addLayout(horizontalLayout);


        gridLayout->addLayout(verticalLayout, 1, 0, 1, 5);

        pushButton_exit = new QPushButton(ShowingPlayers);
        pushButton_exit->setObjectName(QString::fromUtf8("pushButton_exit"));

        gridLayout->addWidget(pushButton_exit, 0, 4, 1, 1);

        pushButton_check_for_challanges = new QPushButton(ShowingPlayers);
        pushButton_check_for_challanges->setObjectName(QString::fromUtf8("pushButton_check_for_challanges"));

        gridLayout->addWidget(pushButton_check_for_challanges, 0, 2, 1, 1);

        pushButton_refresh = new QPushButton(ShowingPlayers);
        pushButton_refresh->setObjectName(QString::fromUtf8("pushButton_refresh"));

        gridLayout->addWidget(pushButton_refresh, 0, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 3, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 1, 1, 1);


        retranslateUi(ShowingPlayers);
        QObject::connect(pushButton_exit, &QPushButton::clicked, ShowingPlayers, qOverload<>(&QDialog::close));

        QMetaObject::connectSlotsByName(ShowingPlayers);
    } // setupUi

    void retranslateUi(QDialog *ShowingPlayers)
    {
        ShowingPlayers->setWindowTitle(QCoreApplication::translate("ShowingPlayers", "Dialog", nullptr));
        pushButton_select_player->setText(QCoreApplication::translate("ShowingPlayers", "Select Player", nullptr));
        pushButton_exit->setText(QCoreApplication::translate("ShowingPlayers", "Exit", nullptr));
        pushButton_check_for_challanges->setText(QCoreApplication::translate("ShowingPlayers", "Check for challanges", nullptr));
        pushButton_refresh->setText(QCoreApplication::translate("ShowingPlayers", "Refresh", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ShowingPlayers: public Ui_ShowingPlayers {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOWINGPLAYERS_H