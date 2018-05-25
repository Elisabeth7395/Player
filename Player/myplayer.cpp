#include "myplayer.h"
#include "ui_myplayer.h"

myPlayer::myPlayer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::myPlayer)
{
    ui->setupUi(this);

    _player = new QMediaPlayer(this);
    _playlist = new QMediaPlaylist(_player);
    _list = new QStandardItemModel(this);
    _player->setPlaylist(_playlist);
    _playlist->setPlaybackMode(QMediaPlaylist::Random);
    ui->_Table->setModel(_list);

    connect(ui->Play, SIGNAL(clicked()), _player, SLOT(play()));
    connect(ui->Pause, SIGNAL(clicked()), _player, SLOT(pause()));
    connect(ui->Stop,SIGNAL(clicked()),_player,SLOT(stop()));
    connect(ui->Next,SIGNAL(clicked()),_playlist,SLOT(next()));
    connect(ui->Previous,SIGNAL(clicked()),_playlist,SLOT(previous()));
    connect(ui->Add,SIGNAL(clicked()),this, SLOT(addMusic()));
//    connect(_playlist, SIGNAL(currentMediaChanged(QMediaContent)), this, SLOT(metaMusic()));

    _list->setColumnCount(2);
    _list->setHorizontalHeaderLabels(QStringList() << ("Music"));
    ui->_Table->hideColumn(1);
    ui->_Table->horizontalHeader()->setStretchLastSection(true);
    connect (_playlist, QOverload<int>::of(&QMediaPlaylist::currentIndexChanged),
                this , QOverload<int>::of(&myPlayer::metaMusic));
}


myPlayer::~myPlayer()
{
    delete ui;
}

void myPlayer::addMusic()
{
    QStringList music = QFileDialog::getOpenFileNames(this, ("Выбор музыки"), "", ("Audio(*.mp3))"));
    foreach(QString _music, music)
    {
        _playlist->addMedia(QUrl(_music));

        QList<QStandardItem*> _str;

//        _str = new QStandardItem((QDir(_music).dirName()));
//       _list->setItem(0, 0, str);
        _str.append(new QStandardItem(QDir(_music).dirName()));
        _str.append(new QStandardItem(_music));
        _list->appendRow(_str);
    }
}

void myPlayer::metaMusic(int number)
{
//     ui->_Track->setText("Banana");
     ui->_Track->setText(_list->data(_list->index(number, 0)).toString());
}



