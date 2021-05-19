/********************************************************************************
** Form generated from reading UI file 'bomberman_dialog.ui'
**
** Created by: Qt User Interface Compiler version 6.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOMBERMAN_DIALOG_H
#define UI_BOMBERMAN_DIALOG_H

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

class Ui_Bomberman_dialog
{
public:
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_username;
    QLineEdit *lineEdit_username;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_password;
    QLineEdit *lineEdit_password;
    QCommandLinkButton *commandLinkButton_login;
    QHBoxLayout *horizontalLayout_3;
    QCommandLinkButton *commandLinkButton_signup;
    QPushButton *pushButton_exit;
    QGraphicsView *graphicsView;

    void setupUi(QDialog *Bomberman_dialog)
    {
        if (Bomberman_dialog->objectName().isEmpty())
            Bomberman_dialog->setObjectName(QString::fromUtf8("Bomberman_dialog"));
        Bomberman_dialog->setEnabled(true);
        Bomberman_dialog->resize(694, 455);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/bomb/img/Bomb.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        Bomberman_dialog->setWindowIcon(icon);
        Bomberman_dialog->setStyleSheet(QString::fromUtf8(""));
        groupBox = new QGroupBox(Bomberman_dialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(170, 310, 370, 118));
        groupBox->setStyleSheet(QString::fromUtf8("border-image: url(:/plain/img/plain color.jpg)"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_username = new QLabel(groupBox);
        label_username->setObjectName(QString::fromUtf8("label_username"));
        label_username->setStyleSheet(QString::fromUtf8("border-image:transparent;"));

        horizontalLayout->addWidget(label_username);

        lineEdit_username = new QLineEdit(groupBox);
        lineEdit_username->setObjectName(QString::fromUtf8("lineEdit_username"));
        lineEdit_username->setAutoFillBackground(false);
        lineEdit_username->setStyleSheet(QString::fromUtf8("border-image:transparent;"));

        horizontalLayout->addWidget(lineEdit_username);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_password = new QLabel(groupBox);
        label_password->setObjectName(QString::fromUtf8("label_password"));
        label_password->setStyleSheet(QString::fromUtf8("border-image:transparent;"));

        horizontalLayout_2->addWidget(label_password);

        lineEdit_password = new QLineEdit(groupBox);
        lineEdit_password->setObjectName(QString::fromUtf8("lineEdit_password"));
        lineEdit_password->setStyleSheet(QString::fromUtf8("border-image:transparent;"));
        lineEdit_password->setEchoMode(QLineEdit::Password);

        horizontalLayout_2->addWidget(lineEdit_password);


        verticalLayout->addLayout(horizontalLayout_2);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 2);

        commandLinkButton_login = new QCommandLinkButton(groupBox);
        commandLinkButton_login->setObjectName(QString::fromUtf8("commandLinkButton_login"));
        commandLinkButton_login->setInputMethodHints(Qt::ImhNone);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/login/img/login.png"), QSize(), QIcon::Normal, QIcon::Off);
        commandLinkButton_login->setIcon(icon1);

        gridLayout->addWidget(commandLinkButton_login, 1, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        commandLinkButton_signup = new QCommandLinkButton(groupBox);
        commandLinkButton_signup->setObjectName(QString::fromUtf8("commandLinkButton_signup"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/signup/img/signup.png"), QSize(), QIcon::Normal, QIcon::Off);
        commandLinkButton_signup->setIcon(icon2);

        horizontalLayout_3->addWidget(commandLinkButton_signup);


        gridLayout->addLayout(horizontalLayout_3, 1, 1, 1, 1);

        pushButton_exit = new QPushButton(Bomberman_dialog);
        pushButton_exit->setObjectName(QString::fromUtf8("pushButton_exit"));
        pushButton_exit->setGeometry(QRect(550, 10, 141, 31));
        pushButton_exit->setStyleSheet(QString::fromUtf8("border-style: solid;\n"
"border-width: 2px;\n"
"border-color: black;\n"
"border-radius: 15px;"));
        graphicsView = new QGraphicsView(Bomberman_dialog);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(-11, -11, 711, 471));
        graphicsView->setStyleSheet(QString::fromUtf8("border-image: url(:/title/img/Bomberman Title.jpg);"));
        graphicsView->raise();
        groupBox->raise();
        pushButton_exit->raise();

        retranslateUi(Bomberman_dialog);
        QObject::connect(pushButton_exit, &QPushButton::clicked, Bomberman_dialog, qOverload<>(&QDialog::close));

        QMetaObject::connectSlotsByName(Bomberman_dialog);
    } // setupUi

    void retranslateUi(QDialog *Bomberman_dialog)
    {
        Bomberman_dialog->setWindowTitle(QCoreApplication::translate("Bomberman_dialog", "Title", nullptr));
        groupBox->setTitle(QString());
        label_username->setText(QCoreApplication::translate("Bomberman_dialog", "Username", nullptr));
        label_password->setText(QCoreApplication::translate("Bomberman_dialog", "Password", nullptr));
        commandLinkButton_login->setText(QCoreApplication::translate("Bomberman_dialog", "Log In", nullptr));
        commandLinkButton_signup->setText(QCoreApplication::translate("Bomberman_dialog", "Register", nullptr));
        pushButton_exit->setText(QCoreApplication::translate("Bomberman_dialog", "Exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Bomberman_dialog: public Ui_Bomberman_dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOMBERMAN_DIALOG_H
