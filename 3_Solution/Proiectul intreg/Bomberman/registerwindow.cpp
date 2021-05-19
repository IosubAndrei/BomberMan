#include "registerwindow.h"
#include "ui_registerwindow.h"
#include <QMessageBox>
#include <vector>
#include "FunctionCode.h"

RegisterWindow::RegisterWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RegisterWindow)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
}

RegisterWindow::~RegisterWindow()
{
    delete ui;
}

void RegisterWindow::on_commandLinkButton_clicked()
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
    else if (ui->lineEdit_username->text() != "" and ui->lineEdit_password->text() != ""
             and ui->lineEdit_password_check_password->text() == "")
    {
        QMessageBox::warning(this, "WARNING", "Please re-enter your password in the 'Re-enter the password' field");
    }
    else
    {
        bool authAccepted = false;
        string str = ui->lineEdit_username->text().toLocal8Bit().constData();
        client->SendString(str);
        str.clear();
        str = ui->lineEdit_password->text().toLocal8Bit().constData();
        client->SendString(str);

        if(client->GetBool(authAccepted))
        {
             QMessageBox::warning(this, "WARNING", "This account already exists");
        }
        else
        {
            // verific ce se intampla dupa ce introduce date in toate spatiile
            if(ui->lineEdit_password->text() != ui->lineEdit_password_check_password->text())
            {
                QMessageBox::warning(this, "WARNING", "Passwords don't match");
            }
            else
            {
                vector<string> vect;
                string str = ui->lineEdit_username->text().toLocal8Bit().constData();

                vect.insert(vect.begin(), str);
                parser->parseString(parser->protocoliseString((int)FunctionCode::InsertNewUser, vect), '$');

                str.clear();
                str = ui->lineEdit_password->text().toLocal8Bit().constData();
                vect.insert(vect.end(), str);

                parser->parseString(parser->protocoliseString((int)FunctionCode::InsertNewUser, vect), '$');


                QMessageBox::information(this, "Fresh meat! >:)", "Welcome new adventurer! Enjoy the game!");
                show_players = new ShowingPlayers(this);
                hide();
                show_players->show();
            }
        }
    }
}
