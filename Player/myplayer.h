#ifndef MYPLAYER_H
#define MYPLAYER_H

#include <QDialog>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QFileDialog>
#include <QStandardItemModel>
#include <QDir>

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
    void metaMusic(int number);
private:
    Ui::myPlayer *ui;
    QMediaPlaylist *_playlist;
    QMediaPlayer *_player;
    QStandardItemModel  *_list;
};

#endif // MYPLAYER_H
