#include "showingplayers.h"
#include "ui_showingplayers.h"

#include <QMessageBox>

ShowingPlayers::ShowingPlayers(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ShowingPlayers)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
}

ShowingPlayers::~ShowingPlayers()
{
    delete ui;
}

void ShowingPlayers::on_pushButton_clicked()
{
    QString nr = QString::number(ui->listWidget->count() + 1);
    QString player = "Player ";
    player += nr;

    ui->listWidget->addItem(player);
    ui->listWidget->scrollToBottom();
}

void ShowingPlayers::on_pushButton_select_player_clicked()
{
    QString player_name = ui->listWidget->currentItem()->text();
    QString description = "You have chosen to play with ";
    description += player_name;
    QMessageBox::information(this, "Player selected", description);

    playground = new PlayingGround(this);
    hide();
    playground->show();
    //playground->showFullScreen();
}

