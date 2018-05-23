#ifndef MYPLAYER_H
#define MYPLAYER_H

#include <QDialog>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QFileDialog>
#include <QMediaMetaData>

namespace Ui
{
    class myPlayer;
}

class myPlayer : public QDialog
{
    Q_OBJECT

public:
    explicit myPlayer(QWidget *parent = 0);
    ~myPlayer();
public slots:
    void addMusic();
    void metaMusic();
private:
    Ui::myPlayer *ui;
    QMediaPlaylist *_playlist;
    QMediaPlayer *_player;
};

#endif // MYPLAYER_H
