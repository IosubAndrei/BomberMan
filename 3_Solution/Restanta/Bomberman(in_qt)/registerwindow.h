#ifndef REGISTERWINDOW_H
#define REGISTERWINDOW_H

#include <QDialog>
#include "showingplayers.h"
#include "Client.h"
#include <QFile>
#include <QTextStream>

#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Mswsock.lib")
#pragma comment (lib, "AdvApi32.lib")

#include <conio.h>

#include<iostream>
#include<vector>

namespace Ui {
class RegisterWindow;
}

class RegisterWindow : public QDialog
{
    Q_OBJECT

public:
    explicit RegisterWindow(QString location_of_the_file, QWidget *parent = nullptr); // (int port_number, QWidget *parent = nullptr);
    ~RegisterWindow();

private slots:
    void on_commandLinkButton_clicked();
    void on_pushButton_help_clicked();

private:
    Ui::RegisterWindow *ui;
    ShowingPlayers *show_players;
//    Client* myClient;
//    static int id_client;
//    static int port;
    QString file_location;
};

#endif // REGISTERWINDOW_H
