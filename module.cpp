#include "module.h"
#include <math.h>

module::module()
{
    ID=0;
}

module::module(const module &inModule)
{
    channelList = inModule.channelList;
    ID=inModule.ID;
}

module::module(module &&inModule)
{
    channelList=inModule.channelList;
    ID=inModule.ID;
}

module& module::operator=(const module& inModule)
{
    if(&inModule==this)
    {
        return *this;
    }
    channelList=inModule.channelList;
    ID=inModule.ID;
    return *this;
}


module& module::operator=(module&& inModule)
{
    if(&inModule==this)
    {
        return *this;
    }
    channelList=inModule.channelList;
    ID=inModule.ID;
    return *this;
}


std::vector<char> module::getSaveData()const
{
    std::vector<char> returnData;
    returnData.push_back((char)ID);
    returnData.push_back((char)channelList.size());
    int i=0;
    while(i<channelList.size())
    {
        returnData.push_back((char)channelList.at(i));
        i++;
    }
    return returnData;
}

int module::getChunkSize()const
{
    return channelList.size()+2;
}

int module::getSizeOfChannels()const
{
    return channelList.size();
}

int module::getChannel(const int &inIndex) const
{
    return channelList.at(inIndex);
}

void module::clearAll()
{
    ID=0;
    channelList.clear();
}

int module::setSavedData(const QByteArray& inData, const int& startLocation)
{
    channelList.clear();
    ID = inData[startLocation];
    int channelListSize=inData[startLocation+1];
    int i=0;
    while(i<channelListSize)
    {
        channelList.push_back(inData[startLocation+i+2]);
        i++;
    }
    return i+2;
}

void module::setID(const int &inID)
{
    ID=inID;
}

int module::getID()const
{
    return ID;
}

std::vector<char> module::getOutputData(const binaryTrack &inData)const
{
    std::vector<char> returnData;

    returnData.push_back((char)ID);
    int sizeOfBytes = (int)ceil((double)channelList.size()/8);
    returnData.push_back((char)sizeOfBytes);

    binaryTrack tempTrack;
    tempTrack.addLength(channelList.size());
    tempTrack.addChannel();

    int i=0;
    while(i<channelList.size())
    {
        tempTrack.setBit(0,i,inData.getBit(0,channelList.at(i)));
        i++;
    }

    i=0;
    while(i<tempTrack.getIndexByteSize())
    {
        returnData.push_back((char)tempTrack.getData(0,i));
        i++;
    }
    return returnData;
}

void module::addChannel(const int &inChannel)
{
    channelList.push_back(inChannel);
}

void module::moveChannelUp(const int &inChannel)
{
    if(inChannel>0)
    {
        int temp = channelList.at(inChannel-1);
        channelList.at(inChannel-1)=channelList.at(inChannel);
        channelList.at(inChannel)=temp;
    }
}

void module::moveChannelDown(const int &inChannel)
{
    if(inChannel<channelList.size()-1)
    {
        int temp = channelList.at(inChannel+1);
        channelList.at(inChannel+1)=channelList.at(inChannel);
        channelList.at(inChannel)=temp;
    }
}

void module::deleteChannel(const int &inChannel)
{
    int i=inChannel;
    while(i < channelList.size()-1)
    {
        channelList.at(i)=channelList.at(i+1);
        i++;
    }
    channelList.pop_back();
}


void module::shiftChannel(const int &inChannel)
{
    int i=0;
    while(i<channelList.size())
    {
        if(channelList.at(i)>=inChannel)
        {
            channelList.at(i)-=1;
        }
        i++;
    }
}






















