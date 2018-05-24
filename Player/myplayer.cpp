#include "myplayer.h"
#include "ui_myplayer.h"
#include <QTime>
#include <QDebug>
//#include <QtTest/QTest>
#include <QMediaContent>
#include<conio.h>

#include <QMediaContent>
#include <QThread>


myPlayer::myPlayer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::myPlayer)
{
    ui->setupUi(this);

    _player = new QMediaPlayer(this);
    _playlist = new QMediaPlaylist(_player);
    _player->setPlaylist(_playlist);
    _playlist->setPlaybackMode(QMediaPlaylist::Loop);

    connect(ui->Play, SIGNAL(clicked()), _player, SLOT(play()));
    connect(ui->Pause, SIGNAL(clicked()), _player, SLOT(pause()));
    connect(ui->Stop,SIGNAL(clicked()),_player,SLOT(stop()));
    connect(ui->Next,SIGNAL(clicked()),_playlist,SLOT(next()));
    connect(ui->Previous,SIGNAL(clicked()),_playlist,SLOT(previous()));
    connect(ui->Add,SIGNAL(clicked()),this, SLOT(addMusic()));
//    connect(_playlist, SIGNAL(currentMediaChanged(QMediaContent)), this, SLOT(metaMusic()));
    connect(_playlist, SIGNAL(currentMediaChanged(QMediaContent)), this, SLOT(metaMusic()));
//    connect(_playlist, SIGNAL(availabilityChanged()), this, slot(metaMusic()));
//    connect(_playlist, SIGNAL(QMediaObject::availabilityChanged()), this, SLOT(metaMusic()));
    connect(_player, QOverload<QMultimedia::AvailabilityStatus>::of(&QMediaObject::availabilityChanged),
            this, QOverload<QMultimedia::AvailabilityStatus>::of(&myPlayer::_error));
}


myPlayer::~myPlayer()
{
    delete ui;
}

void myPlayer::addMusic()
{
    QStringList music = QFileDialog::getOpenFileNames(this, tr("Выбор музыки"), "", tr("Audio(*.mp3 *.wav *.ogg *.flac))"));
    foreach(QString _music, music)
    {
        _playlist->addMedia(QUrl(_music));
    }
}

void myPlayer::metaMusic()
{
     ui->_Album->setText("Banana");


//   connect (_player, QOverload < > :: of ( & QMediaObject :: metaDataChanged ) , [ = ] () { / * ... * / });
//   connect(ui, SIGNAL(_playlist->QMediaObject::isMetaDataAvailable()), this, SLOT(addd));
//
//   connect(_playlist, SIGNAL(metaDataChanged()), ui->_Track, SLOT(setText(_player->metaData(QMediaMetaData::Title).toString())));
//         ui->_Track->);
//         ui->_Artist->setText( _player->metaData(QMediaMetaData::Author).toString());

//
//   QVariant vr;
//   vr=_player->metaData(QMediaMetaData::Title);
//   ui->_Track->setText(vr.toString());
//
//   QString track = ();
//
    //  -- Отсюда --
    // QMediaContent *sss;
    // sss = new QMediaContent(this);
    // sss = _playlist->currentMedia();
    // connect ( sss , QOverload < > :: of ( & QMediaObject :: metaDataChanged ) , [ = ] () { /* ... */ });

//      ui->_Track->setText((sss.QMediaMetaData::metaData("Title")).toString() );
//      ui->_Track->setText(_player->metaData(QMediaMetaData::Title).toString());

/*        QThread::msleep(3000);
    qDebug()<<"Song title: "<<(_player->metaData(QMediaMetaData::Title).toString());
    qDebug()<<"Song duration: "<<_player->duration();
    QMediaContent temp = _player->currentMedia();
    QMediaResourceList temp_resourse_list = temp.resources();
    QMediaResource temp_resource = temp_resourse_list.takeLast();
    qDebug() << temp_resource.audioBitRate();
//


//     ui->_Artist->setText();*/
//
//   ui->_Track->setText();

   //   connect(_player, QOverload<QMultimedia::AvailabilityStatus>::of(&QMediaObject::availabilityChanged),this, SLOT(add()));
   //   connect(_player, QOverload<QMultimedia::AvailabilityStatus>(&QMediaObject::availabilityChanged), this, SLOT(add()));
   //   connect(_player, static_cast<void (QMultimedia::*)(QMultimedia::AvailabilityStatus)>(&QMediaObject::availabilityChanged), this, SLOT(add()));
   //   connect(_player, QOverload<QMultimedia::AvailabilityStatus>(&QMediaObject::availabilityChanged), {  availability){  });});
}

//void myPlayer::addd()
//{
//    QString m_title = _player->metaData(QMediaMetaData::Title).toString();
//    qDebug() << "1 "<< m_title;
//}

