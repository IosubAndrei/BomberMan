#include "registerwindow.h"
#include "ui_registerwindow.h"
#include <QMessageBox>
#include <ctime>

//int RegisterWindow::id_client = 0;
//int RegisterWindow::port = 22;

RegisterWindow::RegisterWindow(QString location_of_the_file, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RegisterWindow)
{
    ui->setupUi(this);
    //myClient = new Client(port_number);
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    //id_client++;
    file_location = location_of_the_file;
}

RegisterWindow::~RegisterWindow()
{
    delete ui;
}


bool send_infos(int& all_ok, Client* client, vector<string>& user_info)
{
    if(all_ok == 1)
    {
        char delim = '$';
        string parsed_string = Parser::getInstance()->parseString(user_info, delim);
        bool worked = client->SendString(parsed_string);
        return worked;
    }
    else return false;
}


void RegisterWindow::on_commandLinkButton_clicked()
{
    //trebuie sa folosesc createUser

    /*
    userID
    lastName
    firstName
    joinedDate
    email
    password
    role
    */
    /*
    int all_ok = 1;
    Client* my_client = new Client(port);
    vector<string> user_info;

    // LAST NAME
    QString last_name=ui->lineEdit_lastname->text().toLower();
    last_name.replace(0, 1, last_name[0].toUpper());

    user_info.push_back(last_name.toStdString());
    Parser::getInstance()->protocoliseString(id_client, user_info);

    // FIRST NAME
    QString first_name=ui->lineEdit_firstname->text().toLower();
    QString copie, final_first_name;

    for(int i = 0; i < first_name.length(); i++)
    {
        if(first_name[i] != ' ' || first_name[i] != '-')
        {
            copie += first_name[i];
        }
        else
        {
            copie.replace(0, 1, copie[0].toUpper());
            final_first_name += copie;
            final_first_name += first_name[i];
            copie.clear();
        }
    }

    user_info.push_back(final_first_name.toStdString());

    // JOINED DATE
    time_t tmNow;
    tmNow = time(NULL);
    struct tm t = *localtime(&tmNow);
    string data =to_string(t.tm_mday) + '-' + to_string(t.tm_mon + 1) + '-' + to_string(t.tm_year+1900);

    user_info.push_back(data);

    // EMAIL
    //verificare email

    QString email = ui->lineEdit_email->text();

    int gasit_format = 0, good_email = 0;
    for(int i = 0; i < email.length(); i++)
    {
        if(email[i] == '@') gasit_format = 1;

        if(gasit_format == 1 && email[i] != '@')
        {
            if(email[i] == 'y')
            {
                QString yahoo = email[i];
                for(int j = i + 1; j < email.length(); j++)
                {
                    yahoo += email[j];
                }

                if(yahoo == "yahoo.com") good_email = 1;
            }
            else if(email[i] == 'g')
            {
                QString gmail = email[i];
                for(int j = i + 1; j < email.length(); j++)
                {
                    gmail += email[j];
                }

                if(gmail == "gmail.com") good_email = 1;
            }

        }
    }

    if(good_email == 1) user_info.push_back(email.toStdString());
    else
    {
        QMessageBox::warning(this, "Warning", "Email doesn't respect the required standards. Press 'Help' button to see them");
        all_ok = 0;
    }

    // PAROLA
    //verificare parola sa nu contina '@','#' si '$'

    QString password = ui->lineEdit_password->text();
    for(int i = 0; i < password.length(); i++)
    {
        if(password[i] == '@' || password[i] == '#' || password[i] == '$')
        {
            QMessageBox::warning(this, "Warning", "Password can't contain the following: '@', '#', '$'");
            all_ok = 0;
        }
    }

    user_info.push_back(password.toStdString());


    // ROL
    QString rol = ui->lineEdit_user_role->text().toLower();
    int id_rol;

     // 1 -> student
     // 2 -> profesor
     // 3 -> administrator

    if(rol == "student" || rol == "std" || rol == "sd")
    {
        id_rol = 1;
        user_info.push_back((to_string(id_rol)));
        if(send_infos(all_ok, my_client, user_info))
        {
            QMessageBox::information(this, "Welcome", "Enjoy the game adventurer!");
            show_players = new ShowingPlayers(this);
            hide();
            show_players->show();
        }
        else
        {
            if(all_ok == 0) QMessageBox::warning(this, "Warning", "You still have some errors to fix");
            else QMessageBox::warning(this, "Warning", "Connection error");
        }
    }
    else if(rol == "professor" || rol == "profesor" || rol == "prof")
    {
        id_rol = 2;
        user_info.push_back((to_string(id_rol)));
        send_infos(all_ok, my_client, user_info);    }
    else if(rol == "administrator" || rol == "admin")
    {
        id_rol = 3;
        user_info.push_back((to_string(id_rol)));
        send_infos(all_ok, my_client, user_info);
    }
    else QMessageBox::warning(this, "Warning",
      "The role must be one of the following: student, professor, admin. Your input is " + rol);



    WSACleanup();
    */


    QFile file(file_location);
    int all_ok = 1, gasit = 0;

    QFile inputFile(file_location);

    if (inputFile.open(QIODevice::ReadOnly))
    {
        QTextStream in(&inputFile);
        while (!in.atEnd())
        {
            QString email, password;

            in >> email >> password;

            if (email == ui->lineEdit_email->text() && password == ui->lineEdit_password->text()) gasit = 1;
        }
        inputFile.close();
    }
    else
    {
        all_ok = 0;
        QMessageBox::warning(this, "Warning", "File can't open in read only mode");
    }

    if (!file.open(QIODevice::ReadWrite | QIODevice::Append))
    {
        QMessageBox::warning(this, "Warning", "File not open");
        all_ok = 0;
    }
    else
    {
        QTextStream out(&file); // ia referinta la fisierul meu pentru a putea sa scriu text

        QString new_email = ui->lineEdit_email->text();


        if (new_email.right(10) != "@gmail.com" && new_email.right(10) != "@yahoo.com")
        {
            QMessageBox::warning(this, "Warning", "Email type not allowed. You need a gmail or a yahoo account to be able to sign up");
            all_ok = 0;
        }


        QString password = ui->lineEdit_password->text();


        if (all_ok == 1)
        {
            out << new_email << " " << password << '\n';
            //file.flush(); // Flushes any buffered data to the file
            file.close();

            //QMessageBox::information(this, "Info", "The content of the file was modified");
            show_players = new ShowingPlayers(new_email, this);
            hide();
            show_players->show();
        }
    }
}

void RegisterWindow::on_pushButton_help_clicked()
{
    QString string1 = "In the user role box i need you to specify me your role: a student, a professor or an admin. In the other boxes, just fill in with what you are asked to.";
    QString string2 = "Use ONLY a gmail account or yahoo as input mail. Any other mail will not work.";
    QString string3 = string1 + '\n' + string2;
    QMessageBox::information(this, "Help", string3);
}
