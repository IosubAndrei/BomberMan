#include "showingplayers.h"
#include "ui_showingplayers.h"

#include <QMessageBox>

ShowingPlayers::ShowingPlayers(QString player_email, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ShowingPlayers)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    this_player_email = player_email;

    QFile file("C:/Users/User/Desktop/POO Proiect/BomberMan/3_Solution/Restanta/Bomberman(in qt)/online.txt");

    if(file.open(QFile::ReadOnly))
    {
        QTextStream in(&file);
        while(!in.atEnd())
        {
            QString email_player_on;
            in >> email_player_on;

            if(email_player_on != this_player_email)
            {
                ui->listWidget->addItem(email_player_on);
            }
        }
        file.close();
    }
}

ShowingPlayers::~ShowingPlayers()
{
//    QFile file("C:/Users/User/Desktop/POO Proiect/BomberMan/3_Solution/Restanta/Bomberman(in qt)/online.txt");

//    if(file.open(QFile::WriteOnly)) file.close();

    delete ui;
}

bool challange_status(QString challange_status_file_location, QString challanger, QString challanged)
{
    QFile file(challange_status_file_location);

    if(file.open(QFile::ReadOnly))
    {
        QString answer, file_challanger, file_challanged;
        QTextStream in(&file);

        while(!in.atEnd())
        {
            in >> file_challanger >> file_challanged >> answer;

            if(file_challanger == challanger && file_challanged == challanged && answer == "yes")
            {
                file.close();
                return true;
            }
        }
        file.close();
    }

    return false;
}

void ShowingPlayers::on_pushButton_select_player_clicked()
{
    QString player_name = ui->listWidget->currentItem()->text();
    QString description = "Challange sent to ";
    description += player_name;
    QMessageBox::information(this, "Challange sent succesfully",
                             description + "Remember to refresh to see if he/she accepted or not");


    QString status_file_location = "C:/Users/User/Desktop/POO Proiect/BomberMan/3_Solution/Restanta/Bomberman(in qt)/status_challanges.txt";

    // trebuie sa scriu in challanges.txt
    QFile file("C:/Users/User/Desktop/POO Proiect/BomberMan/3_Solution/Restanta/Bomberman(in qt)/challanges.txt");

    int ok = 1;
    if(file.open(QFile::ReadWrite | QIODevice::Append))
    {
        QTextStream out(&file);

        out << this_player_email << " " << player_name << '\n';
        file.close();
    }
    else
    {
        ok = 0;
        QMessageBox::warning(this, "Warning", "File could not open");
    }

    if(ok == 1)
    {
        // aici trebuia sa vina confirmarea sau infirmarea cererii de challange trimisa
        QMessageBox::information(this, "Yeey", player_name + " accepted to play with you");
        playground = new PlayingGround(this);
        hide();
        playground->show();
    }
}

QString challange_message(QString challanger)
{
  QString message = challanger + " wants to challange you. Do you accept?";
  return message;
}

void ShowingPlayers::on_pushButton_refresh_clicked()
{
    QFile file("C:/Users/User/Desktop/POO Proiect/BomberMan/3_Solution/Restanta/Bomberman(in qt)/online.txt");

    ui->listWidget->clear();
    if(file.open(QFile::ReadOnly))
    {
        QTextStream in(&file);

        while(!in.atEnd())
        {
            QString email;
            in >> email;
            if(email != this_player_email) ui->listWidget->addItem(email);
        }
        file.close();
    }
}

void ShowingPlayers::on_pushButton_check_for_challanges_clicked()
{
    QFile file("C:/Users/User/Desktop/POO Proiect/BomberMan/3_Solution/Restanta/Bomberman(in qt)/challanges.txt");
    QFile file_2("C:/Users/User/Desktop/POO Proiect/BomberMan/3_Solution/Restanta/Bomberman(in qt)/status_challanges.txt");

    if(file.open(QFile::ReadOnly))
    {
        QString answer, challanger, challanged;
        QTextStream in(&file);

        while(!in.atEnd())
        {
            in >> challanger >> challanged >> answer;

            if(challanged == this_player_email)
            {

                if(file_2.open(QFile::ReadWrite | QFile::Append))
                {
                    QTextStream out(&file_2);
                    // trebuia sa scriu daca a acceptat sau nu

                }
            }
        }
        file.close();
    }

}
