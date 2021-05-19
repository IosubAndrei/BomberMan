#include "bomberman_dialog.h"
#include "ui_bomberman_dialog.h"

#include <QPixmap>
#include <QMessageBox>
#include <QWindow>
#include <QFile> // QFile is an I/O device for reading and writing text and binary files and resources
#include <QTextStream>
#include <QFileDialog>
#include <QHash>


Bomberman_dialog::Bomberman_dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Bomberman_dialog)
{
    ui->setupUi(this);


//    frame->setAttribute(Qt::WA_NoSystemBackground);
//    frame->setAttribute(Qt::WA_OpaquePaintEvent);
//    frame->setStyleSheet("background-color: transparent");
//    frame->setStyleSheet("opacity: 0");

    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
}

Bomberman_dialog::~Bomberman_dialog()
{
    delete ui;
}


// model de citire din fisier
//QFile inputFile(fileName);
//if (inputFile.open(QIODevice::ReadOnly))
//{
//   QTextStream in(&inputFile);
//   while (!in.atEnd())
//   {
//      QString line = in.readLine();
//      ...
//   }
//   inputFile.close();
//}



void Bomberman_dialog::on_commandLinkButton_login_clicked()
{
    // adminul va fi intotdeauna un cont care va exista mereu
    if(ui->lineEdit_username->text() == "admin" and ui->lineEdit_password->text() == "admin")
    {
        QMessageBox::information(this, "Admin log in", "Welcome administrator");
        this->hide();
        show_players = new ShowingPlayers(this);
        show_players->show();
    }
    else
    {
        // verific daca user-ul e uituc si nu completeaza toate spatiile
       if(ui->lineEdit_username->text() == "" and ui->lineEdit_password->text() == "")
       {
           QMessageBox::warning(this, "WARNING", "Both username and password fields are empty");
       }
       else if(ui->lineEdit_username->text() == "" and ui->lineEdit_password->text() != "")
       {
           QMessageBox::warning(this, "WARNING", "Username field is empty");
       }
       else if(ui->lineEdit_username->text() != "" and ui->lineEdit_password->text() == "")
       {
           QMessageBox::warning(this, "WARNING", "Password field is empty");
       }

       else
       {
           bool authAccepted = false;
           string str = ui->lineEdit_username->text().toLocal8Bit().constData();
           client->SendString(str);
           str.clear();
           str = ui->lineEdit_password->text().toLocal8Bit().constData();
           client->SendString(str);

           if (!client->GetBool(authAccepted))
           {
               QMessageBox::warning(this, "WARNING",
                   "Invalid username or password. Either create a new account, or check your spelling issues");
           }
           else
           {
               QMessageBox::information(this, "Congrats!", "Welcome adventurer! Enjoy the game!");
               show_players = new ShowingPlayers(this);
               hide();
               show_players->show();
           }
        }
    }
    




}


void Bomberman_dialog::on_commandLinkButton_signup_clicked()
{
    ui->label_username->clear();
    ui->label_username->clear();

    hide();
    register_window = new RegisterWindow(this);
    register_window->show();
}
