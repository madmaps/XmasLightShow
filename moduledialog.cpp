#include "moduledialog.h"
#include "ui_moduledialog.h"

moduleDialog::moduleDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::moduleDialog)
{
    ui->setupUi(this);
    connect(ui->addModuleButton,SIGNAL(clicked()),this,SLOT(addModule()));
    connect(ui->removeModuleButton,SIGNAL(clicked()),this,SLOT(removeModule()));
    connect(ui->moduleListView,SIGNAL(clicked(QModelIndex)),this,SLOT(updateModInfo(QModelIndex)));
    connect(ui->addChannelToModButton,SIGNAL(clicked()),this,SLOT(addChannelToMod()));
    connect(ui->removeChannelFromModChannel,SIGNAL(clicked()),this,SLOT(removeChannelFromMod()));
    connect(ui->moveChannelUpButton,SIGNAL(clicked()),this,SLOT(moveModChannelUp()));
    connect(ui->moveChannelDownButton,SIGNAL(clicked()),this,SLOT(moveModChannelDown()));
    connect(ui->idApplyButton,SIGNAL(clicked()),this,SLOT(applyModID()));
    connect(ui->doneButton,SIGNAL(clicked()),this,SLOT(close()));
    numberOfChannels=0;

}

void moduleDialog::addModule()
{
    module tempModule;
    tempModule.setID(moduleList.size());
    moduleList.push_back(tempModule);
    ui->moduleListView->addItem(QString("Module %1").arg(moduleList.at(moduleList.size()-1).getID()));
}

std::vector<char> moduleDialog::getOutputData(const binaryTrack &inData) const
{
    std::vector<char> outputData;
    std::vector<char> tempVector;
    outputData.push_back((char)moduleList.size());
    int i = 0;
    while(i<moduleList.size())
    {
        tempVector = moduleList.at(i).getOutputData(inData);
        outputData.insert(outputData.end(),tempVector.begin(),tempVector.end());
        i++;
    }
    return outputData;
}

void moduleDialog::removeChannelFromMod()
{
    if(ui->moduleListView->currentIndex().row()>=0 && ui->moduleChannelListView->currentIndex().row()>=0)
    {
        moduleList.at(ui->moduleListView->currentIndex().row()).deleteChannel(ui->moduleChannelListView->currentIndex().row());
        updateModChannelView();
    }

}

void moduleDialog::deleteChannel(const int &inChannel)
{
    int i=0;
    int j=0;
    while(i<moduleList.size())
    {
        j=0;
        while(j<moduleList.at(i).getSizeOfChannels())
        {
            if(moduleList.at(i).getChannel(j)==inChannel)
            {
                moduleList.at(i).deleteChannel(j);
                j--;
            }
            j++;
        }
        moduleList.at(i).shiftChannel(inChannel);
        i++;
    }
    QListWidgetItem* tempItem = ui->channelListView->takeItem(ui->channelListView->count()-1);
    delete tempItem;
    updateModChannelView();
    numberOfChannels--;

}

void moduleDialog::removeModule()
{
    int index = ui->moduleListView->currentRow();
    if(index>=0 && index<moduleList.size())
    {
        int i=index;
        while(i<moduleList.size()-1)
        {
            moduleList.at(i)=moduleList.at(i+1);
            i++;
        }
        moduleList.pop_back();
        QListWidgetItem* tempitem = ui->moduleListView->takeItem(index);
        delete tempitem;
        if(moduleList.size()>0)
        {
            updateModChannelView();
        }
        else
        {
            ui->moduleChannelListView->clear();
        }

    }
}

void moduleDialog::addChannel()
{
    ui->channelListView->addItem(QString("Channel %1").arg(numberOfChannels));
    numberOfChannels++;
}

void moduleDialog::updateModInfo(QModelIndex theIndex)
{
    ui->idLineEdit->setText(QString("%1").arg(moduleList.at(theIndex.row()).getID()));
    updateModChannelView();
}

void moduleDialog::moveModChannelUp()
{
    if(ui->moduleChannelListView->currentIndex().row()>=1 && ui->moduleListView->currentIndex().row()>=0)
    {
        int theRow=ui->moduleChannelListView->currentIndex().row();
        moduleList.at(ui->moduleListView->currentIndex().row()).moveChannelUp(theRow);
        updateModChannelView();
        ui->moduleChannelListView->setCurrentRow(theRow-1);
    }
}

void moduleDialog::moveModChannelDown()
{
    if(ui->moduleChannelListView->currentIndex().row()>=0 && ui->moduleListView->currentIndex().row()>=0 &&
       ui->moduleChannelListView->currentIndex().row() < moduleList.at(ui->moduleListView->currentIndex().row()).getSizeOfChannels()-1)
    {
        int theRow=ui->moduleChannelListView->currentIndex().row();
        moduleList.at(ui->moduleListView->currentIndex().row()).moveChannelDown(theRow);
        updateModChannelView();
        ui->moduleChannelListView->setCurrentRow(theRow+1);
    }
}


void moduleDialog::addChannelToMod()
{
    if(ui->moduleListView->currentIndex().row()>=0 && ui->channelListView->currentIndex().row()>=0)
    {
        moduleList.at(ui->moduleListView->currentIndex().row()).addChannel(ui->channelListView->currentIndex().row());
        updateModChannelView();
        if(ui->channelListView->currentIndex().row()<numberOfChannels-1)
        {
            ui->channelListView->setCurrentRow(ui->channelListView->currentIndex().row()+1);
        }
    }
}

void moduleDialog::updateModChannelView()
{
    int index = ui->moduleListView->currentRow();

    if(index>=0)
    {
        ui->moduleChannelListView->clear();

        int i=0;
        while(i<moduleList.at(index).getSizeOfChannels())
        {
            ui->moduleChannelListView->addItem(QString("Channel %1").arg(moduleList.at(index).getChannel(i)));
            i++;
        }
    }
}

void moduleDialog::applyModID()
{
    int index = ui->moduleListView->currentIndex().row();
    if(index>=0)
    {
        QString tempString = ui->idLineEdit->text();
        int tempInt = tempString.toInt();
        if(tempInt>=0 && tempInt<=255)
        {
            moduleList.at(index).setID(tempInt);
            QListWidgetItem* tempItem = ui->moduleListView->currentItem();
            tempItem->setText(QString("Module %1").arg(tempInt));

        }
    }
}

std::vector<char> moduleDialog::saveData()const
{
    std::vector<char> returnData;
    std::vector<char> modReturnData;
    char highByte,lowByte;
    int returnValue=0;

    // ChunkID
    lowByte = 0x06;
    returnData.push_back(lowByte);

    // Overall Size
    int j=0;
    int i=0;
    while(i<moduleList.size())
    {
        returnValue+=moduleList.at(i).getChunkSize();
        i++;
    }
    returnValue +=+5;
    lowByte=(char)(returnValue & 0xFF);
    highByte=(char)((returnValue >> 8) & 0xFF);
    returnData.push_back(highByte);
    returnData.push_back(lowByte);

    // Number of Modules
    returnValue = moduleList.size();
    lowByte=(char)(returnValue & 0xFF);
    returnData.push_back(lowByte);

    // Number of Channels
    returnValue = numberOfChannels;
    lowByte=(char)(returnValue &0xFF);
    returnData.push_back(lowByte);

    //Data
    i=0;
    while(i<moduleList.size())
    {
        modReturnData = moduleList.at(i).getSaveData();
        j=0;
        while(j<modReturnData.size())
        {
            returnData.push_back(modReturnData.at(j));
            j++;
        }
        i++;
    }
    return returnData;
}

void moduleDialog::loadSavedData(const QByteArray &inData)
{
    const int Header = 9;
    unsigned char highByte,lowByte;
    int overallSize,numberOfModules,i,j,k;
    int numberOfChunks = inData[8];
    char chunkID;
    int tempCounter;
    int fileLocation = 0;
    moduleList.clear();
    ui->moduleListView->clear();
    ui->channelListView->clear();
    ui->moduleChannelListView->clear();
    numberOfChannels=0;
    int channelCount;
    module tempMod;

    k=0;
    while(k<numberOfChunks)
    {
        chunkID = inData[fileLocation+Header];
        switch(chunkID)
        {
        case 0x06:
            numberOfModules = inData[fileLocation+Header+3];
            channelCount=inData[fileLocation+Header+4];

            i=0;
            while(i<channelCount)
            {
                addChannel();
                i++;
            }

            tempCounter=0;
            i=0;
            while(i<numberOfModules)
            {
                tempMod.clearAll();
                tempCounter+=tempMod.setSavedData(inData,fileLocation+Header+tempCounter+5);
                moduleList.push_back(tempMod);
                ui->moduleListView->addItem(QString("Module %1").arg(moduleList.at(moduleList.size()-1).getID()));
                i++;
            }
            highByte=inData[fileLocation+Header+1];
            lowByte=inData[fileLocation+Header+2];
            overallSize=(highByte<<8) | lowByte;
            fileLocation+=overallSize;
            break;
        default:
            highByte=inData[fileLocation+Header+1];
            lowByte=inData[fileLocation+Header+2];
            overallSize=(highByte<<8) | lowByte;
            fileLocation+=overallSize;
            break;
        }
        k++;
    }
}



moduleDialog::~moduleDialog()
{
    delete ui;
}




















