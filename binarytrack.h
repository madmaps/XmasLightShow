#ifndef BINARYTRACK_H
#define BINARYTRACK_H
#include <vector>

class binaryTrack
{
public:
    //Constructors
    binaryTrack();
    binaryTrack(const binaryTrack& inCopy);
    binaryTrack(binaryTrack&& inMove);

    //Operator Overloading
    binaryTrack operator=(const binaryTrack& rhs);
    binaryTrack operator=(binaryTrack&& rhs);

    //Getters
    bool getBit(const int& inTrack,const int& inIndex)const;
    unsigned int getNumberOfChannels()const;
    unsigned int getNumberOfIndexs()const;
    unsigned int getIndexByteSize()const;
    unsigned char getData(const unsigned int& inChannel,const unsigned int& inByte) const;
    void setData(const unsigned int& inChannel,const unsigned int& inByte,const unsigned char& inData);
    void setByteSize(const unsigned int& inByteSize);
    void clearData();

    //Setters
    void setBit(const int& inTrack,const int& inIndex,const bool& inValue);

    //Public Methods
    void addLength(const unsigned int& inLength);
    void addChannel();
    binaryTrack cut(const int& inIndexStart,const int& inIndexEnd);
    binaryTrack cut(const int& inIndexStart,const int& inIndexEnd,const std::vector<bool>& inEnabled);
    binaryTrack copy(const int& inIndexStart,const int& inIndexEnd) const;
    binaryTrack copy(const int& inIndexStart,const int& inIndexEnd,const std::vector<bool>& inEnabled) const;
    void paste(const binaryTrack& inValues,const int& inIndexStart);
    void paste(const binaryTrack& inValues,const int& inIndexStart,const std::vector<bool>& inEnabled);


    void removeChannel(const int& inChannel);
    //std::vector<unsigned char> getXValues(const int& inIndex) const;
    //void removeChannel(const int& inChannel);
    //void removeAll();


    //Destructor
    ~binaryTrack();

protected:
private:
    //Members
    std::vector<std::vector<unsigned char>> binaryArray;
    unsigned int length;

    //Helper Methods

};

#endif // BINARYTRACK_H
