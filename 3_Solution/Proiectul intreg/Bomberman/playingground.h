#ifndef PLAYINGGROUND_H
#define PLAYINGGROUND_H

#include <QDialog>
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QKeyEvent>
#include <QGraphicsItem>
#include <vector>
#include <QTimer>


#include "player.h"
#include "field.h"



class PlayingGround : public QMainWindow
{
    Q_OBJECT

public:
    explicit PlayingGround(QWidget *parent = nullptr);
    ~PlayingGround();

public slots:
    void playerDied();

private:
    void keyPressEvent(QKeyEvent *event);
    void initFields(int frequency);

    QGraphicsView *_view;
    QGraphicsScene *_scene;
    Player *_player1; //arrows
    Player *_player2; //wsad
    int _playersCount;
    std::vector<std::vector<Field *>> _fields;
};

#endif // MAINWINDOW_H
