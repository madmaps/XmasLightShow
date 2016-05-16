#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <QDialog>
#include <vector>
#include <QString>

namespace Ui {
class playlist;
}

class playlist : public QDialog
{
    Q_OBJECT

public:
    explicit playlist(QWidget *parent = 0);
    ~playlist();
    QString getNextSong();


public slots:
    void addSongs();
    void removeSong();
    void moveSongUp();
    void moveSongDown();
    void changeCurrentSong();
    void savePlaylist();
    void loadPlaylist();



signals:
    void changeSong(QString outFile);

private:
    void updateList();

    Ui::playlist *ui;
    std::vector<QString> playlistFiles;
    int currentSong;

};

#endif // PLAYLIST_H
