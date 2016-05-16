#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <QDialog>
#include "channeloptions.h"
#include <QColor>
#include <QSerialPort>
#include "binarytrack.h"
#include "moduledialog.h"
#include "serialportoptions.h"
#include "playlist.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_horizontalScrollBar_valueChanged(int value);

    void on_verticalScrollBar_valueChanged(int value);

    void on_zoomIn_clicked();

    void on_zoomOut_clicked();

    void on_PlayButton_clicked();

    void on_AddTrack_clicked();

    void on_playbackRateIncrease_clicked();

    void on_playbackRateDecrease_clicked();

    void on_StopButton_clicked();

    void on_loop_clicked(bool checked);

    void on_cutButton_clicked();

    void on_pasteButton_clicked();

    void on_copyButton_clicked();

    void channelColorHasChanged(unsigned int inChannel,QColor inColor);

    void channelSelected(unsigned int inChannel, QColor inColor);

    void writeToSerialPort(const binaryTrack& inData);

    void on_enableSerialOut_clicked(bool checked);

    void on_actionImport_Image_triggered();

    void on_actionImport_Song_triggered();

    void on_actionSave_Project_triggered();

    void on_actionLoad_Project_triggered();

    void removeChannel(int inChannel);

    void channelEnabledButtonPushed(int inChannel,bool inData);

    void on_actionCut_triggered();

    void on_actionCopy_triggered();

    void on_actionPaste_triggered();

    void on_actionModule_Settings_triggered();

    void on_actionPort_Settings_triggered();

    void serialPortNameChanged(QString inSerialPortName);

    void updateSongDuration(qint64 inSongDuration);

    void on_actionManage_Playlist_triggered();

    void checkForNextSong(QMediaPlayer::State currentState);

    void on_invertButton_clicked();

    void playlistChangeSong(QString fileName);

private:


    Ui::MainWindow *ui;
    QMediaPlayer* thePlayer;
    qreal playbackRate;
    channelOptions* options;
    QString imageFileName;
    QString audioFileName;
    QSerialPort thePort;
    QString serialPortName;
    bool serialOutputOn;
    moduleDialog* modOptions;
    serialPortOptions* serialPortOpt;
    int tempTrackCount;
    playlist* thePlaylist;

};

#endif // MAINWINDOW_H
