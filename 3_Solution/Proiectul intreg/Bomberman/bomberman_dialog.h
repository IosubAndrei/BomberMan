#ifndef BOMBERMAN_DIALOG_H
#define BOMBERMAN_DIALOG_H

#include "Client.h"

#include <QDialog>

#include "showingplayers.h"
#include "registerwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Bomberman_dialog; }
QT_END_NAMESPACE

class Bomberman_dialog : public QDialog
{
    Q_OBJECT

public:
    Bomberman_dialog(QWidget *parent = nullptr);
    ~Bomberman_dialog();

private slots:


    void on_commandLinkButton_login_clicked();

    void on_commandLinkButton_signup_clicked();

private:
    Ui::Bomberman_dialog *ui;
    ShowingPlayers *show_players;
    RegisterWindow *register_window;
    Client* client;
};
#endif // BOMBERMAN_DIALOG_H
