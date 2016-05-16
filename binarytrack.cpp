#include "binarytrack.h"
#include <math.h>

//Constructors
binaryTrack::binaryTrack()
{
}

binaryTrack::binaryTrack(const binaryTrack& inCopy):binaryArray(inCopy.binaryArray),length(inCopy.length)
{

}

binaryTrack::binaryTrack(binaryTrack&& inMove):binaryArray(inMove.binaryArray),length(inMove.length)
{

}

//Operator Overloading

binaryTrack binaryTrack::operator =(const binaryTrack& rhs)
{
    if(this==&rhs)
    {
        return *this;
    }
    binaryArray=rhs.binaryArray;
    length=rhs.length;
    return *this;
}

binaryTrack binaryTrack::operator =(binaryTrack&& rhs)
{
    if(this==&rhs)
    {
        return *this;
    }
    binaryArray=rhs.binaryArray;
    length=rhs.length;
    return *this;
}

//Getters

bool binaryTrack::getBit(const int &inTrack, const int &inIndex) const
{
    if(inTrack<binaryArray.size())
    {
        int realIndex = floor(inIndex/8);
        if(realIndex < binaryArray.at(inTrack).size())
        {
            int position = inIndex % 8;
            unsigned char answer = pow(2,position);
            answer = binaryArray.at(inTrack).at(realIndex) & answer;
            if(answer==0)
            {
                return false;
            }
            else
            {
                return true;
            }
        }

    }
return 0;
}

unsigned int binaryTrack::getNumberOfChannels() const
{
    return binaryArray.size();
}

unsigned int binaryTrack::getNumberOfIndexs() const
{
    return length;
}

unsigned int binaryTrack::getIndexByteSize() const
{
    if(binaryArray.size()>0)
    {
        return binaryArray.at(0).size();
    }
    return 0;
}

unsigned char binaryTrack::getData(const unsigned int& inChannel,const unsigned int& inByte) const
{
    return binaryArray.at(inChannel).at(inByte);
}

void binaryTrack::setData(const unsigned int& inChannel,const unsigned int& inByte,const unsigned char& inData)
{
    binaryArray.at(inChannel).at(inByte)=inData;
}

void binaryTrack::clearData()
{
    binaryArray.clear();
}

void binaryTrack::setByteSize(const unsigned int &inByteSize)
{
    length=inByteSize*8;
}

//Setters

void binaryTrack::setBit(const int &inTrack, const int &inIndex, const bool &inValue)
{
    int realIndex = floor(inIndex/8);
    int position = inIndex % 8;
    unsigned char answer = pow(2,position);

    if(inValue==false)
    {
        binaryArray.at(inTrack).at(realIndex) = binaryArray.at(inTrack).at(realIndex) & ~answer;
    }
    else
    {
        binaryArray.at(inTrack).at(realIndex) = binaryArray.at(inTrack).at(realIndex) | answer;
    }
}

//Public Methods

void binaryTrack::addLength(const unsigned int &inLength)
{
    length=inLength;
}

void binaryTrack::addChannel()
{
    if(length!=0)
    {
        std::vector<unsigned char> tempVector;
        for(unsigned int i=0; i<=ceil((double)length/8)-1;i++)
        {
            tempVector.push_back(0x00);
        }
        binaryArray.push_back(tempVector);
    }
}

void binaryTrack::removeChannel(const int &inChannel)
{
    int i=inChannel;
    while(i<binaryArray.size()-1)
    {
        binaryArray.at(i)=binaryArray.at(i+1);
        i++;
    }
    binaryArray.pop_back();
}

binaryTrack binaryTrack::cut(const int &inIndexStart, const int &inIndexEnd)
{
    binaryTrack returnTrack;
    returnTrack.addLength(1+inIndexEnd-inIndexStart);
    unsigned int i=0;
    while(i<=binaryArray.size()-1)
    {
        returnTrack.addChannel();
        i++;
    }

    i=0;
    int j=0;
    while(i<=binaryArray.size()-1)
    {
        j=0;
        while(j+inIndexStart<=inIndexEnd)
        {
            returnTrack.setBit(i,j,getBit(i,j+inIndexStart));
            setBit(i,j+inIndexStart,false);
            j++;
        }
        i++;
    }
    return returnTrack;
}

binaryTrack binaryTrack::cut(const int &inIndexStart, const int &inIndexEnd,const std::vector<bool>& inEnabled)
{
    binaryTrack returnTrack;
    returnTrack.addLength(1+inIndexEnd-inIndexStart);
    unsigned int i=0;
    while(i<=binaryArray.size()-1)
    {
        returnTrack.addChannel();
        i++;
    }

    i=0;
    int j=0;
    while(i<=binaryArray.size()-1)
    {
        if(inEnabled.at(i))
        {
            j=0;
            while(j+inIndexStart<=inIndexEnd)
            {
                returnTrack.setBit(i,j,getBit(i,j+inIndexStart));
                setBit(i,j+inIndexStart,false);
                j++;
            }
        }
        i++;
    }
    return returnTrack;
}


binaryTrack binaryTrack::copy(const int &inIndexStart, const int &inIndexEnd) const
{
    binaryTrack returnTrack;
    returnTrack.addLength(inIndexEnd-inIndexStart+1);
    unsigned int i=0;
    while(i<=binaryArray.size()-1)
    {
        returnTrack.addChannel();
        i++;
    }

    i=0;
    int j=0;
    while(i<=binaryArray.size()-1)
    {
        j=0;
        while(j+inIndexStart<=inIndexEnd)
        {
            returnTrack.setBit(i,j,getBit(i,j+inIndexStart));
            j++;
        }
        i++;
    }
    return returnTrack;
}

binaryTrack binaryTrack::copy(const int &inIndexStart, const int &inIndexEnd,const std::vector<bool>& inEnabled) const
{
    binaryTrack returnTrack;
    returnTrack.addLength(inIndexEnd-inIndexStart+1);
    unsigned int i=0;
    while(i<=binaryArray.size()-1)
    {
        returnTrack.addChannel();
        i++;
    }

    i=0;
    int j=0;
    while(i<=binaryArray.size()-1)
    {
        if(inEnabled.at(i))
        {
            j=0;
            while(j+inIndexStart<=inIndexEnd)
            {
                returnTrack.setBit(i,j,getBit(i,j+inIndexStart));
                j++;
            }
        }
        i++;
    }
    return returnTrack;
}


void binaryTrack::paste(const binaryTrack &inValues, const int &inIndexStart)
{
    if(binaryArray.size()>0 && inValues.binaryArray.size()==binaryArray.size())
    {
        if(inValues.getNumberOfIndexs()+inIndexStart<getNumberOfIndexs())
        {
            unsigned int i=0;
            unsigned int j=0;
            while(i<=inValues.binaryArray.size()-1)
            {
                j=0;
                while(j<=inValues.getNumberOfIndexs()-1)
                {
                    setBit(i,j+inIndexStart,inValues.getBit(i,j));
                    j++;
                }
                i++;
            }
       }
    }
}

void binaryTrack::paste(const binaryTrack &inValues, const int &inIndexStart,const std::vector<bool>& inEnabled)
{
    if(binaryArray.size()>0 && inValues.binaryArray.size()==binaryArray.size())
    {
        if(inValues.getNumberOfIndexs()+inIndexStart<getNumberOfIndexs())
        {
            unsigned int i=0;
            unsigned int j=0;
            while(i<=inValues.binaryArray.size()-1)
            {
                if(inEnabled.at(i))
                {
                    j=0;
                    while(j<=inValues.getNumberOfIndexs()-1)
                    {
                        setBit(i,j+inIndexStart,inValues.getBit(i,j));
                        j++;
                    }
                }
                i++;
            }
       }
    }
}


binaryTrack::~binaryTrack()
{}




































