#ifndef SHOWINGPLAYERS_H
#define SHOWINGPLAYERS_H

#include <QDialog>
#include "playingground.h"

namespace Ui {
class ShowingPlayers;
}

class ShowingPlayers : public QDialog
{
    Q_OBJECT

public:
    explicit ShowingPlayers(QWidget *parent = nullptr);
    ~ShowingPlayers();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_select_player_clicked();

private:
    Ui::ShowingPlayers *ui;
    PlayingGround *playground;
};

#endif // SHOWINGPLAYERS_H
