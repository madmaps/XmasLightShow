#include "playlist.h"
#include "ui_playlist.h"
#include <QFileDialog>
#include <QStringList>
#include <QFile>
#include <QDir>
#include <QFileInfo>

playlist::playlist(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::playlist)
{
    ui->setupUi(this);
    connect(ui->addFilesButton,SIGNAL(clicked()),this,SLOT(addSongs()));
    connect(ui->removeSongsButton,SIGNAL(clicked()),this,SLOT(removeSong()));
    connect(ui->moveDownButton,SIGNAL(clicked()),this,SLOT(moveSongDown()));
    connect(ui->moveUpButton,SIGNAL(clicked()),this,SLOT(moveSongUp()));
    connect(ui->listWidget,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(changeCurrentSong()));
    connect(ui->savePlaylistButton,SIGNAL(clicked()),this,SLOT(savePlaylist()));
    connect(ui->loadPlaylistButton,SIGNAL(clicked()),this,SLOT(loadPlaylist()));
    currentSong=-1;
}

void playlist::addSongs()
{
    QStringList fileList = QFileDialog::getOpenFileNames(this,tr("Load Songs"),":/",tr("Xmas Projects (*.xmas)"));
    int i=0;
    while(i<fileList.size())
    {
        playlistFiles.push_back(fileList.at(i));
        i++;
    }
    updateList();
}

void playlist::removeSong()
{
    if(ui->listWidget->currentIndex().row()>=0)
    {
        int i=ui->listWidget->currentIndex().row();
        while(i<playlistFiles.size()-1)
        {
            playlistFiles.at(i)=playlistFiles.at(i+1);
            i++;
        }
        playlistFiles.pop_back();

        updateList();

    }
}

void playlist::updateList()
{
    QFileInfo temp;
    ui->listWidget->clear();
    int i=0;
    while(i<playlistFiles.size())
    {
        temp.setFile(playlistFiles.at(i));
        if(i==currentSong)
        {
            ui->listWidget->addItem("(Active->)"+temp.fileName());

        }
        else
        {
            ui->listWidget->addItem(temp.fileName());
        }
        i++;
    }
}

void playlist::moveSongUp()
{
    if(ui->listWidget->currentIndex().row()>=1)
    {
        int theRow = ui->listWidget->currentIndex().row();
        if(theRow==currentSong)
        {
            currentSong--;
        }
        else if(theRow-1==currentSong)
        {
            currentSong++;
        }

        QString temp = playlistFiles.at(theRow-1);
        playlistFiles.at(theRow-1)=playlistFiles.at(theRow);
        playlistFiles.at(theRow)=temp;
        updateList();
        ui->listWidget->setCurrentRow(theRow-1);

    }
}

void playlist::moveSongDown()
{
    if(ui->listWidget->currentIndex().row()<playlistFiles.size()-1)
    {
        int theRow = ui->listWidget->currentIndex().row();

        if(theRow==currentSong)
        {
            currentSong++;
        }
        else if(theRow+1==currentSong)
        {
            currentSong--;
        }

        QString temp = playlistFiles.at(theRow+1);
        playlistFiles.at(theRow+1)=playlistFiles.at(theRow);
        playlistFiles.at(theRow)=temp;
        updateList();
        ui->listWidget->setCurrentRow(theRow+1);

    }
}


QString playlist::getNextSong()
{
    currentSong++;
    if(currentSong>playlistFiles.size()-1)
    {
        currentSong=0;
    }
    if(playlistFiles.size()>0)
    {
        updateList();
        return playlistFiles.at(currentSong);
    }
    updateList();
    return QString("");
}

void playlist::changeCurrentSong()
{
    currentSong=ui->listWidget->currentRow();
    changeSong(playlistFiles.at(ui->listWidget->currentRow()));
    updateList();
}

void playlist::savePlaylist()
{
    QString fileName = QFileDialog::getSaveFileName(this,tr("Save File"),":/",tr("Playlist (*.xpl"));
    QFile outFile(fileName);
    if(outFile.open(QIODevice::WriteOnly))
    {
        char* temp = new char[16];
        int returnValue=0;

        returnValue = playlistFiles.size();
        temp[1]=(char)(returnValue & 0xFF);
        temp[0]=(char)((returnValue>>8)&0xFF);
        outFile.write(temp,2);

        QFileInfo fileInfo(fileName);
        QDir currentDir=fileInfo.absoluteDir();
        QString relativePath;

        int i=0;
        while(i<playlistFiles.size())
        {
            relativePath = currentDir.relativeFilePath(playlistFiles.at(i));
            returnValue = relativePath.length();
            temp[1]=(char)(returnValue & 0xFF);
            temp[0]=(char)((returnValue >>8) & 0xFF);
            outFile.write(temp,2);
            outFile.write(relativePath.toLocal8Bit(),relativePath.length());
            i++;
        }
    }
}


void playlist::loadPlaylist()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),":/",tr("Playlist (*.xpl)"));
    if(fileName!="")
    {
        QFile inFile(fileName);
        if(inFile.open(QIODevice::ReadOnly))
        {
            playlistFiles.clear();
            QFileInfo fileInfo(fileName);
            QDir tempDir = fileInfo.absoluteDir();
            QString fileDir = tempDir.absolutePath();
            QByteArray data = inFile.readAll();
            inFile.close();
            char highByte,lowByte;
            int count=0;
            int fileLength;
            QString tempFileName;

            highByte=data[0];
            lowByte=data[1];
            int playlistCount = (highByte<<8) | lowByte;
            count+=2;

            int i=0,j=0;
            while(i<playlistCount)
            {
                highByte=data[count+0];
                lowByte=data[count+1];
                fileLength = (highByte<<8) | lowByte;
                count+=2;
                tempFileName=fileDir+'/';
                j=0;
                while(j<fileLength)
                {
                    tempFileName+=data.at(count+j);
                    j++;
                }
                playlistFiles.push_back(tempFileName);
                count+=fileLength;
                i++;
            }
            updateList();
        }
    }
}

























playlist::~playlist()
{
    delete ui;
}
