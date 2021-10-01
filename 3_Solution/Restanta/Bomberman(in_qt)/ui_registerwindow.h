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
    QPushButton *pushButton_exit;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_email;
    QLabel *label_password;
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEdit_email;
    QLineEdit *lineEdit_password;
    QCommandLinkButton *commandLinkButton;
    QGraphicsView *graphicsView;
    QPushButton *pushButton_help;

    void setupUi(QDialog *RegisterWindow)
    {
        if (RegisterWindow->objectName().isEmpty())
            RegisterWindow->setObjectName(QString::fromUtf8("RegisterWindow"));
        RegisterWindow->resize(679, 435);
        pushButton_exit = new QPushButton(RegisterWindow);
        pushButton_exit->setObjectName(QString::fromUtf8("pushButton_exit"));
        pushButton_exit->setGeometry(QRect(600, 20, 71, 31));
        pushButton_exit->setStyleSheet(QString::fromUtf8("border-image:transparent;\n"
"border-style: solid;\n"
"color: rgb(255, 255, 255);\n"
"border-width: 2px;\n"
"border-color: yellow;\n"
"border-radius: 10px;"));
        groupBox = new QGroupBox(RegisterWindow);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(180, 233, 301, 111));
        groupBox->setStyleSheet(QString::fromUtf8("border-image: url(:/plain/img/plain color 2.png);"));
        verticalLayout_3 = new QVBoxLayout(groupBox);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_email = new QLabel(groupBox);
        label_email->setObjectName(QString::fromUtf8("label_email"));

        verticalLayout_2->addWidget(label_email);

        label_password = new QLabel(groupBox);
        label_password->setObjectName(QString::fromUtf8("label_password"));

        verticalLayout_2->addWidget(label_password);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        lineEdit_email = new QLineEdit(groupBox);
        lineEdit_email->setObjectName(QString::fromUtf8("lineEdit_email"));
        lineEdit_email->setStyleSheet(QString::fromUtf8("border-image: transparent;"));

        verticalLayout->addWidget(lineEdit_email);

        lineEdit_password = new QLineEdit(groupBox);
        lineEdit_password->setObjectName(QString::fromUtf8("lineEdit_password"));
        lineEdit_password->setStyleSheet(QString::fromUtf8("border-image: transparent;"));
        lineEdit_password->setEchoMode(QLineEdit::Password);

        verticalLayout->addWidget(lineEdit_password);


        horizontalLayout->addLayout(verticalLayout);


        verticalLayout_3->addLayout(horizontalLayout);

        commandLinkButton = new QCommandLinkButton(groupBox);
        commandLinkButton->setObjectName(QString::fromUtf8("commandLinkButton"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/signup/img/signup.png"), QSize(), QIcon::Normal, QIcon::Off);
        commandLinkButton->setIcon(icon);

        verticalLayout_3->addWidget(commandLinkButton);

        graphicsView = new QGraphicsView(RegisterWindow);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(-10, -10, 701, 451));
        graphicsView->setStyleSheet(QString::fromUtf8("border-image: url(:/title/img/title.jpg);"));
        pushButton_help = new QPushButton(RegisterWindow);
        pushButton_help->setObjectName(QString::fromUtf8("pushButton_help"));
        pushButton_help->setGeometry(QRect(10, 20, 71, 31));
        pushButton_help->setStyleSheet(QString::fromUtf8("border-image:transparent;\n"
"border-style: solid;\n"
"color: rgb(255, 255, 255);\n"
"border-width: 2px;\n"
"border-color: yellow;\n"
"border-radius: 10px;"));
        graphicsView->raise();
        pushButton_exit->raise();
        groupBox->raise();
        pushButton_help->raise();

        retranslateUi(RegisterWindow);
        QObject::connect(pushButton_exit, &QPushButton::clicked, RegisterWindow, qOverload<>(&QDialog::close));

        QMetaObject::connectSlotsByName(RegisterWindow);
    } // setupUi

    void retranslateUi(QDialog *RegisterWindow)
    {
        RegisterWindow->setWindowTitle(QCoreApplication::translate("RegisterWindow", "Dialog", nullptr));
        pushButton_exit->setText(QCoreApplication::translate("RegisterWindow", "Exit", nullptr));
        groupBox->setTitle(QString());
        label_email->setText(QCoreApplication::translate("RegisterWindow", "Choose an email", nullptr));
        label_password->setText(QCoreApplication::translate("RegisterWindow", "Choose a password", nullptr));
        commandLinkButton->setText(QCoreApplication::translate("RegisterWindow", "Register", nullptr));
        pushButton_help->setText(QCoreApplication::translate("RegisterWindow", "Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RegisterWindow: public Ui_RegisterWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERWINDOW_H
