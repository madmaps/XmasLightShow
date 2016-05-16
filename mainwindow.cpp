#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QColor>
#include <QString>
#include <QFile>
#include <QByteArray>
#include <QFileInfo>
#include <QDir>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),ui(new Ui::MainWindow),options(new channelOptions(this)),modOptions(new moduleDialog(this)),serialPortOpt(new serialPortOptions(this)),thePlaylist(new playlist(this))//thePlayer(new QMediaPlayer),
{
    thePlayer = NULL;
    ui->setupUi(this);
    playbackRate=1;
    serialPortName="COM3";
    //serialPortName="/dev/ttyUSB0";
    //thePort.setPortName("/dev/ttyACM0");
    thePort.setPortName(serialPortName);
    thePort.setBaudRate(QSerialPort::Baud9600);
    serialOutputOn=0;
    connect(ui->label_2,SIGNAL(playScroll(int)),ui->horizontalScrollBar,SLOT(setValue(int)));
    connect(ui->label_2,SIGNAL(trackSelected(uint,QColor)),this,SLOT(channelSelected(uint,QColor)));
    connect(ui->label_2,SIGNAL(updatePicture(binaryTrack)),ui->label,SLOT(whatToLightUp(binaryTrack)));
    connect(ui->label_2,SIGNAL(updatePicture(binaryTrack)),this,SLOT(writeToSerialPort(binaryTrack)));
    connect(ui->actionExit,SIGNAL(triggered()),this,SLOT(close()));
    connect(options,SIGNAL(removeChannel(int)),this,SLOT(removeChannel(int)));
    connect(options,SIGNAL(theColorChanged(uint,QColor)),this,SLOT(channelColorHasChanged(uint,QColor)));
    connect(options,SIGNAL(changeEditMode(bool)),ui->label,SLOT(changeEditMode(bool)));
    connect(options,SIGNAL(channelEnableButtonPushed(int,bool)),this,SLOT(channelEnabledButtonPushed(int,bool)));
    connect(serialPortOpt,SIGNAL(setNewSerialPort(QString)),this,SLOT(serialPortNameChanged(QString)));
    connect(thePlaylist,SIGNAL(changeSong(QString)),this,SLOT(playlistChangeSong(QString)));
    tempTrackCount=0;
}

MainWindow::~MainWindow()
{
    thePort.close();
    delete ui;
    delete thePlayer;
    delete options;

}

void MainWindow::on_horizontalScrollBar_valueChanged(int value)
{
    ui->label_2->scrollinX(value);
}

void MainWindow::on_verticalScrollBar_valueChanged(int value)
{
    ui->label_2->scrollinY(value);
}

void MainWindow::on_zoomIn_clicked()
{
    ui->label_2->zoomIn();
    ui->horizontalScrollBar->setMaximum(ui->label_2->getScrollSize());
}

void MainWindow::on_zoomOut_clicked()
{
    ui->label_2->zoomOut();
    ui->horizontalScrollBar->setMaximum(ui->label_2->getScrollSize());

}

void MainWindow::on_PlayButton_clicked()
{
    if(thePlayer!=NULL)
    {
        if(thePlayer->state()==QMediaPlayer::PausedState || thePlayer->state()==QMediaPlayer::StoppedState)
        {
            ui->PlayButton->setText("Pause");
            ui->label_2->setPlayState(true);
            thePlayer->play();
        }
        else if(thePlayer->state()==QMediaPlayer::PlayingState)
        {
            ui->PlayButton->setText("Play");
            ui->label_2->setPlayState(false);
            thePlayer->pause();
        }
    }
}

void MainWindow::on_AddTrack_clicked()
{
    if(thePlayer!=NULL)
    {
        if(thePlayer->isAudioAvailable())
        {
            ui->label_2->addNewTrack();
            QColor tempColor;
            tempColor.setRgb(255,0,0);
            ui->label->addChannel(tempColor);
            modOptions->addChannel();
        }
    }
}

void MainWindow::serialPortNameChanged(QString inSerialPortName)
{
    serialOutputOn=0;
    thePort.close();
    ui->enableSerialOut->setChecked(false);
    serialPortName=inSerialPortName;
    thePort.setPortName(serialPortName);
}

void MainWindow::on_playbackRateIncrease_clicked()
{
    if(thePlayer!=NULL)
    {
        playbackRate+=0.1;
        qint64 temp = thePlayer->position();
        thePlayer->setPlaybackRate(playbackRate);
        ui->label_3->setText(QString("%1").arg(playbackRate));
        thePlayer->setPosition(temp);
    }
}

void MainWindow::on_playbackRateDecrease_clicked()
{
    if(thePlayer!=NULL)
    {
        playbackRate-=0.1;
        if(playbackRate<=0.1)
        {
            playbackRate=0.1;
        }
        qint64 temp = thePlayer->position();
        thePlayer->setPlaybackRate(playbackRate);
        ui->label_3->setText(QString("%1").arg(playbackRate));

        if(temp>0)
        {
            thePlayer->setPosition(temp);
        }
    }

}

void MainWindow::on_StopButton_clicked()
{
    if(thePlayer!=NULL)
    {
        ui->PlayButton->setText("Play");
        ui->label_2->setPlayState(false);
        thePlayer->stop();
    }
}

void MainWindow::on_loop_clicked(bool checked)
{
    ui->label_2->setLoop(checked);
}

void MainWindow::on_cutButton_clicked()
{
    ui->label_2->cut();
}

void MainWindow::on_pasteButton_clicked()
{
    ui->label_2->paste();
}

void MainWindow::on_copyButton_clicked()
{
    ui->label_2->copy();
}

void MainWindow::channelEnabledButtonPushed(int inChannel, bool inData)
{
    ui->label_2->setChannelEnabled(inChannel,inData);
    ui->label->setChannelEnabled(inChannel,inData);
    update();
}


void MainWindow::channelColorHasChanged(unsigned int inChannel, QColor inColor)
{
    ui->label_2->setChannelColor(inChannel,inColor);
    ui->label->changeColor(inChannel,inColor);
}

void MainWindow::channelSelected(unsigned int inChannel,QColor inColor)
{
    options->setChannel(inChannel);
    options->setChannelColor(inColor);
    options->changeEnabledState(ui->label_2->getChannelEnabled(inChannel));
    options->show();
    ui->label->setActiveChannel(inChannel);
}

void MainWindow::removeChannel(int inChannel)
{
    ui->label_2->removeChannel(inChannel);
    ui->label->removeChannel(inChannel);
    modOptions->deleteChannel(inChannel);
    if(ui->label_2->getChannelSize()>0)
    {
        if(ui->label_2->getChannelSize()<=inChannel)
        {
            options->setChannel(inChannel-1);
            options->setChannelColor(ui->label_2->getColorArray().at(inChannel-1));
            options->changeEnabledState(ui->label_2->getChannelEnabled(inChannel-1));
        }
        else
        {
            options->setChannel(inChannel);
            options->setChannelColor(ui->label_2->getColorArray().at(inChannel));
            options->changeEnabledState(ui->label_2->getChannelEnabled(inChannel));
        }
    }
    else
    {
        options->hide();
    }
    update();
}



void MainWindow::writeToSerialPort(const binaryTrack &inData)
{
    if(inData.getNumberOfChannels()>0 && serialOutputOn)
    {
        std::vector<char> tempVector = modOptions->getOutputData(inData);
        thePort.write(tempVector.data(),tempVector.size());
    }
}


void MainWindow::on_enableSerialOut_clicked(bool checked)
{
    serialOutputOn=checked;
    if(checked)
    {
        thePort.open(QSerialPort::WriteOnly);
    }
    else
    {
        thePort.close();
    }
}



void MainWindow::on_actionImport_Image_triggered()
{
    imageFileName = QFileDialog::getOpenFileName(this, tr("Open File"),"/home/matt/Desktop",tr("Images (*.jpg *.bmp)"));
    if(imageFileName!="")
    {
        QPixmap tempImage(imageFileName);
        ui->label->loadImage(tempImage);

    }
}

void MainWindow::on_actionImport_Song_triggered()
{
    audioFileName = QFileDialog::getOpenFileName(this, tr("Open File"),"/home/matt/Desktop",tr("Audio (*.mp3 *.wav)"));
    if(audioFileName!="")
    {
        if(thePlayer!=NULL)
        {
            delete thePlayer;
            thePlayer=NULL;
        }
        thePlayer = new QMediaPlayer();
        thePlayer->setNotifyInterval(20);
        connect(thePlayer,SIGNAL(durationChanged(qint64)),this,SLOT(updateSongDuration(qint64)));
        connect(thePlayer,SIGNAL(stateChanged(QMediaPlayer::State)),this,SLOT(checkForNextSong(QMediaPlayer::State)));
        connect(thePlayer,SIGNAL(positionChanged(qint64)),ui->label_2,SLOT(playPositionChanged(qint64)));
        connect(ui->label_2,SIGNAL(userChangePlayPosition(qint64)),thePlayer,SLOT(setPosition(qint64)));

        thePlayer->setMedia(QUrl::fromLocalFile(audioFileName));
        if(ui->label_2->isSongAdded())
        {
            tempTrackCount=ui->label_2->getChannelSize();
            ui->label_2->clearAllData();
            ui->label_2->resetSongAdded();
        }

    }
}

void MainWindow::updateSongDuration(qint64 inSongDuration)
{
    ui->label_2->addSong((double)inSongDuration/1000);
    ui->horizontalScrollBar->setMaximum(ui->label_2->getScrollSize());
    int i=0;
    while(i<tempTrackCount)
    {
        ui->label_2->addNewTrack();
        i++;
    }
    tempTrackCount=0;
}

void MainWindow::on_actionSave_Project_triggered()
{
    int returnValue;
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"),"/home/matt/Desktop",tr("Projects (*.xmas)"));
    QFile outFile(fileName);
    if (outFile.open(QIODevice::WriteOnly))
    {
        char* temp = new char[16];
        //File Type
        temp[0] = 0x78;
        temp[1] = 0x6d;
        temp[2] = 0x61;
        temp[3] = 0x73;
        outFile.write(temp,4);

        //File Version
        temp[0] = 0x00;
        temp[1] = 0x01;
        outFile.write(temp,2);

        //File Size
        temp[0] = 0x00;
        temp[1] = 0x00;
        outFile.write(temp,2);

        //Number of Chunks
        temp[0] = 0x06;
        outFile.write(temp,1);

        temp[0] = 0x03;
        outFile.write(temp,1);

        QFileInfo fileInfo(fileName);
        QDir currentDir=fileInfo.absoluteDir();
        QString relativePath = currentDir.relativeFilePath(imageFileName);


        returnValue = relativePath.length()+3;
        temp[1]=(char)(returnValue & 0xFF);
        temp[0]=(char)((returnValue >>8) & 0xFF);
        outFile.write(temp,2);
        outFile.write(relativePath.toLocal8Bit());

        temp[0] = 0x04;
        outFile.write(temp,1);

        relativePath=currentDir.relativeFilePath(audioFileName);

        returnValue = relativePath.length()+3;
        temp[1]=(char)(returnValue & 0xFF);
        temp[0]=(char)((returnValue >>8) & 0xFF);
        outFile.write(temp,2);
        outFile.write(relativePath.toLocal8Bit());

        std::vector<char> channelData = ui->label_2->saveData();
        outFile.write(channelData.data(),channelData.size());
        channelData = ui->label->saveData();
        outFile.write(channelData.data(),channelData.size());
        channelData = modOptions->saveData();
        outFile.write(channelData.data(),channelData.size());

        outFile.close();
    }
}

void MainWindow::on_actionLoad_Project_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),"/home/matt/Desktop",tr("Projects (*.xmas)"));
    if(fileName!="")
    {
        QFile inFile(fileName);
        if(inFile.open(QIODevice::ReadOnly))
        {
            QFileInfo fileInfo(fileName);
            QDir tempDir = fileInfo.absoluteDir();
            QString fileDir = tempDir.absolutePath();
            setWindowTitle("Lightshow Editor - " + fileInfo.fileName());

            const int Header = 9;
            QByteArray data=inFile.readAll();
            inFile.close();

            char highByte,lowByte;
            highByte=data[Header+1];
            lowByte=data[Header+2];
            int imageFileNameLength=(highByte<<8) | lowByte;

            int i=0;
            imageFileName = fileDir+'/';
            while(i<imageFileNameLength-3)
            {
                imageFileName+=data.at(Header+3+i);
                i++;
            }
            if(imageFileName!="")
            {
                ui->label->clearAllData();
                QPixmap tempImage(imageFileName);
                ui->label->loadImage(tempImage);
            }

            highByte=data[Header+imageFileNameLength+1];
            lowByte=data[Header+imageFileNameLength+2];
            int audioFileNameLength=(highByte<<8) | lowByte;

            i=0;
            audioFileName = fileDir+'/';
            while(i<audioFileNameLength-3)
            {
                audioFileName+=data.at(Header+imageFileNameLength+i+3);
                i++;
            }
            if(audioFileName!="")
            {
                if(thePlayer!=NULL)
                {
                    delete thePlayer;
                    thePlayer=NULL;
                }
                thePlayer = new QMediaPlayer();
                thePlayer->setNotifyInterval(20);
                connect(thePlayer,SIGNAL(durationChanged(qint64)),this,SLOT(updateSongDuration(qint64)));
                connect(thePlayer,SIGNAL(stateChanged(QMediaPlayer::State)),this,SLOT(checkForNextSong(QMediaPlayer::State)));
                connect(thePlayer,SIGNAL(positionChanged(qint64)),ui->label_2,SLOT(playPositionChanged(qint64)));
                connect(ui->label_2,SIGNAL(userChangePlayPosition(qint64)),thePlayer,SLOT(setPosition(qint64)));

                thePlayer->setMedia(QUrl::fromLocalFile(audioFileName));
                ui->label_2->resetSongAdded();
                ui->label->clearAllData();
            }
            ui->label_2->loadSavedData(data);
            ui->horizontalScrollBar->setMaximum(ui->label_2->getScrollSize());
            ui->label->loadSavedData(data);
            modOptions->loadSavedData(data);
            //ui->label->loadSavedData(inputData,ui->label_2->getChannelSize(),buffer);
            //ui->label->addColorArray(ui->label_2->getColorArray());
        }
    }
}


void MainWindow::on_actionCut_triggered()
{
    on_cutButton_clicked();
}

void MainWindow::on_actionCopy_triggered()
{
    on_copyButton_clicked();
}

void MainWindow::on_actionPaste_triggered()
{
    on_pasteButton_clicked();
}

void MainWindow::on_actionModule_Settings_triggered()
{
    modOptions->show();
}

void MainWindow::playlistChangeSong(QString fileName)
{
    if(thePlayer!=NULL)
    {
        thePlayer->stop();
    }
    if(fileName!="")
    {
        QFile inFile(fileName);
        if(inFile.open(QIODevice::ReadOnly))
        {
            QFileInfo fileInfo(fileName);
            QDir tempDir = fileInfo.absoluteDir();
            QString fileDir = tempDir.absolutePath();
            setWindowTitle("Lightshow Editor - " + fileInfo.fileName());


            const int Header = 9;
            QByteArray data=inFile.readAll();
            inFile.close();

            char highByte,lowByte;
            highByte=data[Header+1];
            lowByte=data[Header+2];
            int imageFileNameLength=(highByte<<8) | lowByte;

            int i=0;
            imageFileName = fileDir+'/';
            while(i<imageFileNameLength-3)
            {
                imageFileName+=data.at(Header+3+i);
                i++;
            }
            if(imageFileName!="")
            {
                ui->label->clearAllData();
                QPixmap tempImage(imageFileName);
                ui->label->loadImage(tempImage);
            }

            highByte=data[Header+imageFileNameLength+1];
            lowByte=data[Header+imageFileNameLength+2];
            int audioFileNameLength=(highByte<<8) | lowByte;

            i=0;
            audioFileName = fileDir+'/';
            while(i<audioFileNameLength-3)
            {
                audioFileName+=data.at(Header+imageFileNameLength+i+3);
                i++;
            }
            if(audioFileName!="")
            {
                if(thePlayer!=NULL)
                {
                    delete thePlayer;
                    thePlayer=NULL;
                }
                thePlayer = new QMediaPlayer();
                thePlayer->setNotifyInterval(20);
                connect(thePlayer,SIGNAL(durationChanged(qint64)),this,SLOT(updateSongDuration(qint64)));
                connect(thePlayer,SIGNAL(stateChanged(QMediaPlayer::State)),this,SLOT(checkForNextSong(QMediaPlayer::State)));
                connect(thePlayer,SIGNAL(positionChanged(qint64)),ui->label_2,SLOT(playPositionChanged(qint64)));
                connect(ui->label_2,SIGNAL(userChangePlayPosition(qint64)),thePlayer,SLOT(setPosition(qint64)));

                thePlayer->setMedia(QUrl::fromLocalFile(audioFileName));
                ui->label_2->resetSongAdded();
                ui->label->clearAllData();
            }
            ui->label_2->loadSavedData(data);
            ui->horizontalScrollBar->setMaximum(ui->label_2->getScrollSize());
            ui->label->loadSavedData(data);
            modOptions->loadSavedData(data);
        }
    }
    thePlayer->play();
    ui->label_2->setPlayState(true);
    ui->PlayButton->setText("Pause");
}

void MainWindow::checkForNextSong(QMediaPlayer::State currentState)
{
    if(currentState==QMediaPlayer::StoppedState && thePlayer->duration()-10 < thePlayer->position() && ui->actionEnable_Playlist->isChecked())
    {
        QString fileName = thePlaylist->getNextSong();
        if(fileName!="")
        {
            QFile inFile(fileName);
            if(inFile.open(QIODevice::ReadOnly))
            {
                QFileInfo fileInfo(fileName);
                QDir tempDir = fileInfo.absoluteDir();
                QString fileDir = tempDir.absolutePath();
                setWindowTitle("Lightshow Editor - " + fileInfo.fileName());

                const int Header = 9;
                QByteArray data=inFile.readAll();
                inFile.close();

                char highByte,lowByte;
                highByte=data[Header+1];
                lowByte=data[Header+2];
                int imageFileNameLength=(highByte<<8) | lowByte;

                int i=0;
                imageFileName = fileDir+'/';
                while(i<imageFileNameLength-3)
                {
                    imageFileName+=data.at(Header+3+i);
                    i++;
                }
                if(imageFileName!="")
                {
                    ui->label->clearAllData();
                    QPixmap tempImage(imageFileName);
                    ui->label->loadImage(tempImage);
                }

                highByte=data[Header+imageFileNameLength+1];
                lowByte=data[Header+imageFileNameLength+2];
                int audioFileNameLength=(highByte<<8) | lowByte;

                i=0;
                audioFileName = fileDir+'/';
                while(i<audioFileNameLength-3)
                {
                    audioFileName+=data.at(Header+imageFileNameLength+i+3);
                    i++;
                }
                if(audioFileName!="")
                {
                    if(thePlayer!=NULL)
                    {
                        delete thePlayer;
                        thePlayer=NULL;
                    }
                    thePlayer = new QMediaPlayer();
                    thePlayer->setNotifyInterval(20);
                    connect(thePlayer,SIGNAL(durationChanged(qint64)),this,SLOT(updateSongDuration(qint64)));
                    connect(thePlayer,SIGNAL(stateChanged(QMediaPlayer::State)),this,SLOT(checkForNextSong(QMediaPlayer::State)));
                    connect(thePlayer,SIGNAL(positionChanged(qint64)),ui->label_2,SLOT(playPositionChanged(qint64)));
                    connect(ui->label_2,SIGNAL(userChangePlayPosition(qint64)),thePlayer,SLOT(setPosition(qint64)));

                    thePlayer->setMedia(QUrl::fromLocalFile(audioFileName));
                    ui->label_2->resetSongAdded();
                    ui->label->clearAllData();
                }
                ui->label_2->loadSavedData(data);
                ui->horizontalScrollBar->setMaximum(ui->label_2->getScrollSize());
                ui->label->loadSavedData(data);
                modOptions->loadSavedData(data);
                //ui->label->loadSavedData(inputData,ui->label_2->getChannelSize(),buffer);
                //ui->label->addColorArray(ui->label_2->getColorArray());
            }
        }
        thePlayer->play();
    }
}

/*
void MainWindow::on_actionSave_Project_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"),"/home/matt/Desktop",tr("Projects (*.xmas)"));
    QFile outFile(fileName);
    if (outFile.open(QIODevice::WriteOnly))
    {
        char* temp = new char[16];
        *temp = (char)imageFileName.length();
        outFile.write(temp,1);
        outFile.write(imageFileName.toLocal8Bit());
        *temp=(char)audioFileName.length();
        outFile.write(temp,1);
        outFile.write(audioFileName.toLocal8Bit());
        std::vector<unsigned char> channelData = ui->label_2->saveData();// + ui->label->saveData();
        std::vector<unsigned char> visualData = ui->label->saveData();
        int i=0;
        while(i<visualData.size())
        {
            channelData.push_back(visualData.at(i));
            i++;
        }
        char* tempChar = new char[channelData.size()];// = new char[saveVector.size()];
        i=0;
        while(i<channelData.size())
        {
            tempChar[i]=(char)channelData.at(i);
            i++;
        }

        outFile.write(tempChar,channelData.size());
        outFile.close();
    }
}

void MainWindow::on_actionImport_Song_triggered()
{
    audioFileName = QFileDialog::getOpenFileName(this, tr("Open File"),"/home/matt/Desktop",tr("Audio (*.mp3 *.wav)"));
    if(audioFileName!="")
    {
        thePlayer->setMedia(QUrl::fromLocalFile(audioFileName));
        ui->label_2->resetSongAdded();
        ui->label->clearAllData();

    }
}
void MainWindow::on_actionSave_Project_triggered()
{
    int returnValue;
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"),"/home/matt/Desktop",tr("Projects (*.xmas)"));
    QFile outFile(fileName);
    if (outFile.open(QIODevice::WriteOnly))
    {
        char* temp = new char[16];
        //File Type
        temp[0] = 0x78;
        temp[1] = 0x6d;
        temp[2] = 0x61;
        temp[3] = 0x73;
        outFile.write(temp,4);

        //File Version
        temp[0] = 0x00;
        temp[1] = 0x01;
        outFile.write(temp,2);

        //File Size
        temp[0] = 0x00;
        temp[1] = 0x00;
        outFile.write(temp,2);

        //Number of Chunks
        temp[0] = 0x06;
        outFile.write(temp,1);

        temp[0] = 0x03;
        outFile.write(temp,1);

        returnValue = imageFileName.length()+3;
        temp[1]=(char)(returnValue & 0xFF);
        temp[0]=(char)((returnValue >>8) & 0xFF);
        outFile.write(temp,2);
        outFile.write(imageFileName.toLocal8Bit());

        temp[0] = 0x04;
        outFile.write(temp,1);

        returnValue = audioFileName.length()+3;
        temp[1]=(char)(returnValue & 0xFF);
        temp[0]=(char)((returnValue >>8) & 0xFF);
        outFile.write(temp,2);
        outFile.write(audioFileName.toLocal8Bit());

        std::vector<char> channelData = ui->label_2->saveData();
        outFile.write(channelData.data(),channelData.size());
        channelData = ui->label->saveData();
        outFile.write(channelData.data(),channelData.size());
        channelData = modOptions->saveData();
        outFile.write(channelData.data(),channelData.size());

        outFile.close();
    }
}


*/


void MainWindow::on_actionPort_Settings_triggered()
{
    serialPortOpt->setPortNameText(serialPortName);
    serialPortOpt->show();
}

void MainWindow::on_actionManage_Playlist_triggered()
{
    thePlaylist->show();
}

void MainWindow::on_invertButton_clicked()
{
    ui->label_2->invert();
}
