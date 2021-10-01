#ifndef SHOWINGPLAYERS_H
#define SHOWINGPLAYERS_H

#include <QDialog>
#include "playingground.h"
#include <QFile>


namespace Ui {
class ShowingPlayers;
}

class ShowingPlayers : public QDialog
{
    Q_OBJECT

public:
    explicit ShowingPlayers(QString player_email, QWidget *parent = nullptr);
    ~ShowingPlayers();

private slots:
    void on_pushButton_select_player_clicked();

    void on_pushButton_refresh_clicked();

    void on_pushButton_check_for_challanges_clicked();

private:
    Ui::ShowingPlayers *ui;
    PlayingGround *playground;
    QString this_player_email;
};

#endif // SHOWINGPLAYERS_H
