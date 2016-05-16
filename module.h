#ifndef MODULE_H
#define MODULE_H
#include <vector>
#include <QByteArray>
#include "binarytrack.h"

class module
{
public:
    module();
    module(const module& inModule);
    module(module&& inModule);
    module& operator=(const module& inModule);
    module& operator=(module&& inModule);

    std::vector<char> getSaveData()const;
    int setSavedData(const QByteArray &inData, const int &startLocation);
    int getChunkSize()const;
    void setID(const int& inID);
    int getID()const;
    std::vector<char> getOutputData(const binaryTrack& inData)const;
    void addChannel(const int& inChannel);
    void moveChannelUp(const int& inChannel);
    void moveChannelDown(const int& inChannel);
    void deleteChannel(const int& inChannel);
    void shiftChannel(const int& inChannel);
    void clearAll();

    int getSizeOfChannels()const;
    int getChannel(const int& inIndex) const;
private:
    int ID;
    std::vector<int> channelList;
};

#endif // MODULE_H
