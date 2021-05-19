/********************************************************************************
** Form generated from reading UI file 'registerwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERWINDOW_H
#define UI_REGISTERWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_RegisterWindow
{
public:
    QPushButton *pushButton;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QCommandLinkButton *commandLinkButton;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_username;
    QLabel *label_password;
    QLabel *label_check_password;
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEdit_username;
    QLineEdit *lineEdit_password;
    QLineEdit *lineEdit_password_check_password;
    QGraphicsView *graphicsView;

    void setupUi(QDialog *RegisterWindow)
    {
        if (RegisterWindow->objectName().isEmpty())
            RegisterWindow->setObjectName(QString::fromUtf8("RegisterWindow"));
        RegisterWindow->resize(679, 435);
        pushButton = new QPushButton(RegisterWindow);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(600, 20, 71, 31));
        pushButton->setStyleSheet(QString::fromUtf8("border-image:transparent;\n"
"border-style: solid;\n"
"color: rgb(255, 255, 255);\n"
"border-width: 2px;\n"
"border-color: yellow;\n"
"border-radius: 10px;"));
        groupBox = new QGroupBox(RegisterWindow);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(200, 150, 276, 138));
        groupBox->setStyleSheet(QString::fromUtf8("border-image: url(:/plain/img/plain color 2.png);"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        commandLinkButton = new QCommandLinkButton(groupBox);
        commandLinkButton->setObjectName(QString::fromUtf8("commandLinkButton"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/signup/img/signup.png"), QSize(), QIcon::Normal, QIcon::Off);
        commandLinkButton->setIcon(icon);

        gridLayout->addWidget(commandLinkButton, 1, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_username = new QLabel(groupBox);
        label_username->setObjectName(QString::fromUtf8("label_username"));

        verticalLayout_2->addWidget(label_username);

        label_password = new QLabel(groupBox);
        label_password->setObjectName(QString::fromUtf8("label_password"));

        verticalLayout_2->addWidget(label_password);

        label_check_password = new QLabel(groupBox);
        label_check_password->setObjectName(QString::fromUtf8("label_check_password"));

        verticalLayout_2->addWidget(label_check_password);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        lineEdit_username = new QLineEdit(groupBox);
        lineEdit_username->setObjectName(QString::fromUtf8("lineEdit_username"));
        lineEdit_username->setStyleSheet(QString::fromUtf8("border-image: transparent;"));

        verticalLayout->addWidget(lineEdit_username);

        lineEdit_password = new QLineEdit(groupBox);
        lineEdit_password->setObjectName(QString::fromUtf8("lineEdit_password"));
        lineEdit_password->setStyleSheet(QString::fromUtf8("border-image: transparent;"));
        lineEdit_password->setEchoMode(QLineEdit::Password);

        verticalLayout->addWidget(lineEdit_password);

        lineEdit_password_check_password = new QLineEdit(groupBox);
        lineEdit_password_check_password->setObjectName(QString::fromUtf8("lineEdit_password_check_password"));
        lineEdit_password_check_password->setStyleSheet(QString::fromUtf8("border-image: transparent;"));
        lineEdit_password_check_password->setEchoMode(QLineEdit::Password);

        verticalLayout->addWidget(lineEdit_password_check_password);


        horizontalLayout->addLayout(verticalLayout);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        graphicsView = new QGraphicsView(RegisterWindow);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(-10, -10, 701, 451));
        graphicsView->setStyleSheet(QString::fromUtf8("border-image: url(:/title/img/title.jpg);"));
        graphicsView->raise();
        pushButton->raise();
        groupBox->raise();

        retranslateUi(RegisterWindow);
        QObject::connect(pushButton, &QPushButton::clicked, RegisterWindow, qOverload<>(&QDialog::close));

        QMetaObject::connectSlotsByName(RegisterWindow);
    } // setupUi

    void retranslateUi(QDialog *RegisterWindow)
    {
        RegisterWindow->setWindowTitle(QCoreApplication::translate("RegisterWindow", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("RegisterWindow", "Exit", nullptr));
        groupBox->setTitle(QString());
        commandLinkButton->setText(QCoreApplication::translate("RegisterWindow", "Register", nullptr));
        label_username->setText(QCoreApplication::translate("RegisterWindow", "Choose an username", nullptr));
        label_password->setText(QCoreApplication::translate("RegisterWindow", "Choose a password", nullptr));
        label_check_password->setText(QCoreApplication::translate("RegisterWindow", "Re-enter the password", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RegisterWindow: public Ui_RegisterWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERWINDOW_H
