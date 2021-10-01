#include "bomberman_dialog.h"
#include "ui_bomberman_dialog.h"

#include <QPixmap>
#include <QMessageBox>
#include <QWindow>
#include <QTextStream>
#include <QFileDialog>


#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Mswsock.lib")
#pragma comment (lib, "AdvApi32.lib")

#include <conio.h>

#include<iostream>
#include<vector>

int port_number = 42069;

Bomberman_dialog::Bomberman_dialog(QWidget *parent)
	: QDialog(parent)
    , ui(new Ui::Bomberman_dialog)
{
    ui->setupUi(this);
    //myClient = new Client(port_number);
	file_location = "C:/Users/User/Desktop/POO Proiect/BomberMan/3_Solution/Restanta/Bomberman(in qt)/accounts.txt";//":/resource_file/accounts.txt";

//    frame->setAttribute(Qt::WA_NoSystemBackground);
//    frame->setAttribute(Qt::WA_OpaquePaintEvent);
//    frame->setStyleSheet("background-color: transparent");
//    frame->setStyleSheet("opacity: 0");

    setWindowFlags(Qt::Window | Qt::WindowMinimizeButtonHint | Qt::WindowCloseButtonHint);
    this->setWindowTitle("Bomberman online");
}

Bomberman_dialog::~Bomberman_dialog()
{
    delete ui;
}

void Bomberman_dialog::on_commandLinkButton_login_clicked()
{
   
	// verific daca user-ul e uituc si nu completeaza toate spatiile
    if(ui->lineEdit_email->text().isEmpty() and ui->lineEdit_password->text().isEmpty())
    {
        QMessageBox::warning(this, "WARNING", "Both username and password fields are empty");
    }
    else if(ui->lineEdit_email->text().isEmpty() and ui->lineEdit_password->text().isEmpty() == false)
    {
        QMessageBox::warning(this, "WARNING", "Username field is empty");
    }
    else if(ui->lineEdit_email->text().isEmpty()==false and ui->lineEdit_password->text().isEmpty())
    {
        QMessageBox::warning(this, "WARNING", "Password field is empty");
    }
    else
    {
		/*
        //nou
		   
		bool usernameReceived = false;
		bool passwordReceived = false;
		bool authAccepted = false;


		string str = ui->lineEdit_username->text().toStdString();
		myClient->SendString(str);
		
		if (!myClient->GetBool(usernameReceived))
		{
			QMessageBox::warning(this, "ERROR", "Authentification failed. Problems with the username");
			//exit(EXIT_FAILURE);
			//this->close();
		}
		else
		{
			str.clear();
			str = ui->lineEdit_password->text().toStdString();
			myClient->SendString(str);
			
			if (!myClient->GetBool(passwordReceived))
			{
				QMessageBox::warning(this, "ERROR", "Authentification failed. Problems with the password");
				//exit(EXIT_FAILURE);
				//this->close();
			}
			else if (!myClient->GetBool(authAccepted))
			{
				QMessageBox::warning(this, "WARNING",
					"Invalid username or password. Check your spelling issues or create a new account");
			}
			else if (myClient->Connect())
			{
				//if (myClient->LoadUserInfo())
				//{
				//	myClient->StartSubRoutine();
				//}

				QMessageBox::information(this, "Congrats!", "Welcome adventurer! Enjoy the game!");
				show_players = new ShowingPlayers(this);
				hide();
				show_players->show();
				WSACleanup();
			}
		}
		*/

		// citire din fisier
		int gasit = 0, parola_gresita = 0, username_gresit = 0, nu_exista_cont = 0;

		QFile inputFile(file_location);
		QString email_gasit;


		if (inputFile.open(QIODevice::ReadOnly))
		{
			QTextStream in(&inputFile);
			while (!in.atEnd())
			{
				QString email, password;

				in >> email >> password;

				if (email == ui->lineEdit_email->text() && password == ui->lineEdit_password->text())
				{
					gasit = 1;
					email_gasit = email;
				}
				else if (email == ui->lineEdit_email->text() && password != ui->lineEdit_password->text() && gasit == 0) parola_gresita = 1;
				else if (email != ui->lineEdit_email->text() && password == ui->lineEdit_password->text() && gasit == 0) username_gresit = 1;
				else if (email != ui->lineEdit_email->text() && password != ui->lineEdit_password->text() && gasit == 0)
				{
					parola_gresita = 1;
					username_gresit = 1;
				}
				else nu_exista_cont = 1;
			}
			inputFile.close();
		}


		if (gasit == 1)
		{
            // scriere in fisier cine e on
            QFile file("C:/Users/User/Desktop/POO Proiect/BomberMan/3_Solution/Restanta/Bomberman(in qt)/online.txt");

            if(file.open(QFile::ReadWrite | QFile::Append))
            {
                QTextStream out(&file);
                out << ui->lineEdit_email->text() << '\n';
                file.close();
            }

			QMessageBox::information(this, "Welcome back", "Enjoy the adventure!");
			show_players = new ShowingPlayers(email_gasit, this);
			hide();
			show_players->show();
		}
		else
		{
			if (parola_gresita == 1 && username_gresit == 1) QMessageBox::warning(this, "Warning", "Username and password are incorrect");
			else if (parola_gresita == 1 && username_gresit == 0) QMessageBox::warning(this, "Warning", "Incorrect username");
			else if (parola_gresita == 0 && username_gresit == 1) QMessageBox::warning(this, "Warning", "Incorrect password");
			else if (nu_exista_cont == 1) QMessageBox::warning(this, "Warning", "There is no account linked to this email address");
		}
    }
}


void Bomberman_dialog::on_commandLinkButton_signup_clicked()
{
    ui->label_username->clear();
    ui->label_username->clear();

    hide();
    register_window = new RegisterWindow(file_location, this); // (port_number, this);
    register_window->show();
}
