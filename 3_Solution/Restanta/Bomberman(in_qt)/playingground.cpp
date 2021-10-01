#include "playingground.h"

#include <QRandomGenerator>

#include "settings.h"
#include <QMessageBox>


PlayingGround::PlayingGround(QWidget *parent) : QMainWindow(parent) {

    //setez sa fie afisat doar butoanele de minimise si close
    setWindowFlags(Qt::Window | Qt::WindowMinimizeButtonHint | Qt::WindowCloseButtonHint);

    int w =650;//1392;//768;//this->width();
    int h =550;//770;//1366;//this->height();

    //this->setFixedSize(w, h);
    _scene = new QGraphicsScene();
    _scene->setSceneRect(0, 0, w, h);//650, 550);
    _scene->clearFocus();

    _view = new QGraphicsView(_scene);
    _view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    _view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    _view->setFixedSize(w, h);//(650, 550);



    setCentralWidget(_view);
    setWindowTitle(tr("Bomberman")); //am setat titlu
    setWindowIcon(QPixmap(":/bomb/img/Bomb.jpg"));

    initFields(3);

    _playersCount = sizes::Players;
    _player1 = new Player(0, 0);
    connect(_player1, SIGNAL(playerDied()), this, SLOT(playerDied()));
    _fields[0][0]->playerOn(_player1);
    _player2 = new Player(sizes::Columns - 1, sizes::Rows - 1);
    connect(_player2, SIGNAL(playerDied()), this, SLOT(playerDied()));
    _fields[sizes::Rows - 1][sizes::Columns - 1]->playerOn(_player2);
    _scene->addItem(_player1);
    _scene->addItem(_player2);

    setFocus();
}

PlayingGround::~PlayingGround() {
    for (std::size_t i = 0; i < sizes::Rows; i++) {
        for(std::size_t j = 0; j < sizes::Columns; j++) {
          delete  _fields[i][j];
        }
    }

    delete _player1;
    delete _player2;
    delete _scene;
    delete _view;
}

void PlayingGround::playerDied()
{
    _playersCount--;
    if(_playersCount == 1) {
        QMessageBox::warning(this, "Winner", "The other player won. You loose");
        //delete this;
        //this->close();

        this->destroy();
    }
}


void PlayingGround::keyPressEvent(QKeyEvent *event) {
    setFocus();
    //player1 control
    switch (event->key()) {
        case Qt::Key_A:
            _player1->move(Left, _fields);
            break;
        case Qt::Key_D:
            _player1->move(Right, _fields);
            break;
        case Qt::Key_S:
            _player1->move(Down, _fields);
            break;
        case Qt::Key_W:
            _player1->move(Up, _fields);
            break;
        case Qt::Key_Q:
            _player1->plantBomb(_fields);
            break;
    }

    //player2 control
    switch (event->key()) {
        case Qt::Key_Left:
            _player2->move(Left, _fields);
            break;
        case Qt::Key_Right:
            _player2->move(Right, _fields);
            break;
        case Qt::Key_Down:
            _player2->move(Down, _fields);
            break;
        case Qt::Key_Up:
            _player2->move(Up, _fields);
            break;
        case Qt::Key_Space:
            _player2->plantBomb(_fields);
            break;
    }

}

void PlayingGround::initFields(int frequency) {
    for (int i = 0; i < sizes::Rows; i++) {
        _fields.push_back(std::vector<Field *>());
        for(int j = 0; j < sizes::Columns; j++) {
            Field *newField = new Field(j * sizes::FieldSize, i * sizes::FieldSize);
            _fields[static_cast<std::size_t>(i)].push_back(newField);
            _scene->addItem(newField);
            //generating UndestroyableBlocks
            if (i % 2 && j % 2) {
                newField->setUnDestroyableBlock(new UnDestroyableBlock());
            }
            //generating DestoryableBlocks
            else if ((i > 1 || j > 1) && (i < sizes::Rows - 2 || j < sizes::Columns - 2)) {
                if(QRandomGenerator::global()->bounded(frequency)) { //put bigger number to generate blocks more often
                    newField->setDestoryableBlock(new DestroyableBlock());
                }
            }
        }
    }
}
