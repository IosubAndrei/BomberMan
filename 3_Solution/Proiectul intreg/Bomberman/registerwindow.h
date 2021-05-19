#ifndef REGISTERWINDOW_H
#define REGISTERWINDOW_H

#include <QDialog>
#include "showingplayers.h"
#include "Client.h"
#include "Parser.h"


namespace Ui {
class RegisterWindow;
}

class RegisterWindow : public QDialog
{
    Q_OBJECT

public:
    explicit RegisterWindow(QWidget *parent = nullptr);
    ~RegisterWindow();

private slots:
    void on_commandLinkButton_clicked();

private:
    Ui::RegisterWindow *ui;
    ShowingPlayers *show_players;
    Client* client;
    Parser* parser;
};

#endif // REGISTERWINDOW_H
