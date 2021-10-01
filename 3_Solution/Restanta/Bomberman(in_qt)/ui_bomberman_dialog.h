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
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Bomberman_dialog
{
public:
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label_username;
    QLabel *label_password;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *lineEdit_email;
    QLineEdit *lineEdit_password;
    QCommandLinkButton *commandLinkButton_login;
    QHBoxLayout *horizontalLayout_3;
    QCommandLinkButton *commandLinkButton_signup;
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
        groupBox->setGeometry(QRect(160, 340, 370, 116));
        groupBox->setStyleSheet(QString::fromUtf8("border-image: url(:/plain/img/plain color.jpg)"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_username = new QLabel(groupBox);
        label_username->setObjectName(QString::fromUtf8("label_username"));
        label_username->setStyleSheet(QString::fromUtf8("border-image:transparent;"));

        verticalLayout->addWidget(label_username);

        label_password = new QLabel(groupBox);
        label_password->setObjectName(QString::fromUtf8("label_password"));
        label_password->setStyleSheet(QString::fromUtf8("border-image:transparent;"));

        verticalLayout->addWidget(label_password);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        lineEdit_email = new QLineEdit(groupBox);
        lineEdit_email->setObjectName(QString::fromUtf8("lineEdit_email"));
        lineEdit_email->setAutoFillBackground(false);
        lineEdit_email->setStyleSheet(QString::fromUtf8("border-image:transparent;"));

        verticalLayout_2->addWidget(lineEdit_email);

        lineEdit_password = new QLineEdit(groupBox);
        lineEdit_password->setObjectName(QString::fromUtf8("lineEdit_password"));
        lineEdit_password->setStyleSheet(QString::fromUtf8("border-image:transparent;"));
        lineEdit_password->setEchoMode(QLineEdit::Password);

        verticalLayout_2->addWidget(lineEdit_password);


        horizontalLayout->addLayout(verticalLayout_2);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 2);

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

        graphicsView = new QGraphicsView(Bomberman_dialog);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(-11, -11, 711, 471));
        graphicsView->setStyleSheet(QString::fromUtf8("border-image: url(:/title/img/Bomberman Title.jpg);"));
        graphicsView->raise();
        groupBox->raise();

        retranslateUi(Bomberman_dialog);

        QMetaObject::connectSlotsByName(Bomberman_dialog);
    } // setupUi

    void retranslateUi(QDialog *Bomberman_dialog)
    {
        Bomberman_dialog->setWindowTitle(QCoreApplication::translate("Bomberman_dialog", "Title", nullptr));
        groupBox->setTitle(QString());
        label_username->setText(QCoreApplication::translate("Bomberman_dialog", "Email", nullptr));
        label_password->setText(QCoreApplication::translate("Bomberman_dialog", "Password", nullptr));
        commandLinkButton_login->setText(QCoreApplication::translate("Bomberman_dialog", "Log In", nullptr));
        commandLinkButton_signup->setText(QCoreApplication::translate("Bomberman_dialog", "Register", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Bomberman_dialog: public Ui_Bomberman_dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOMBERMAN_DIALOG_H
