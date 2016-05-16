#include "track.h"
#include <QPainter>
#include <math.h>
#include <iostream>
#include <QFont>
#include <QString>
#include <QTime>

Track::Track(QWidget *parent) :
    QLabel(parent)
{
    scrollX=0;
    scrollY=0;
    secondDivider=16;
    songLength=0;
    unitWidth = 10;
    unitHeight = 20;
    QFont channelFont;
    channelFont.setPointSize(10);
    setFont(channelFont);
    QFontMetrics fontMatrix(channelFont);

    channelTitleXBuffer=10;
    channelTitleYBuffer=6;
    unitHeight=fontMatrix.height()+channelTitleYBuffer;
    channelTitleWidth = fontMatrix.width("Channel 00")+channelTitleXBuffer;

    tickerTextLength=fontMatrix.width("00:00:00");
    tickerTextHeight=fontMatrix.height();

    tickerHeight = 50;

    graphHeight=0;
    graphWidth=0;

    shortTickHeight=10;
    mediumTickHeight=15;
    longTickHeight=20;

    songAdded=0;
    playPosition=0;
    isPlaying = 0;
    highlightActive=0;
    highlightEnd=-1;
    highlightStart=-1;
    keepLooping=0;


}

void Track::addNewTrack()
{
    if(songAdded!=0)
    {
        trackArray.addChannel();
        QColor tempColor;
        tempColor.setRgb(255,0,0);
        channelColors.push_back(tempColor);
        isEnabled.push_back(true);
    }
    update();
}

void Track::setChannelColor(const int &inChannel, const QColor &inColor)
{
    channelColors.at(inChannel)=inColor;
    update();
}

void Track::addSong(const double& inLength)
{
    songLength=inLength;
    trackArray.addLength(songLength*secondDivider);
    songAdded=1;
    update();
}

void Track::resetSongAdded()
{
    songAdded=0;
    trackArray.clearData();
    update();
}

void Track::setChannelEnabled(const int &inChannel, const bool &inData)
{
    isEnabled.at(inChannel)=inData;
}

bool Track::getChannelEnabled(const int &inChannel) const
{
    return isEnabled.at(inChannel);
}

binaryTrack Track::getBitArray(const int &inIndex) const
{
    binaryTrack tempTrack;
    tempTrack.addLength(trackArray.getNumberOfChannels());
    tempTrack.addChannel();

    int i=0;
    while(i<trackArray.getNumberOfChannels())
    {
        if(isEnabled.at(i))
        {
            tempTrack.setBit(0,i,trackArray.getBit(i,inIndex));
        }
        i++;
    }
    return tempTrack;
}

bool Track::isSongAdded()
{
    return songAdded;
}

void Track::zoomIn()
{
    unitWidth*=2;
    update();
}

void Track::zoomOut()
{
    unitWidth/=2;
    update();
}

int Track::getScrollSize() const
{
    return unitWidth*secondDivider*songLength;
}

void Track::setPlayState(const bool &inPlayState)
{
    isPlaying=inPlayState;
}

void Track::setLoop(const bool& inLoop)
{
    keepLooping=inLoop;
}

void Track::cut()
{
    if(highlightActive)
    {
        clipBoard=trackArray.cut(highlightStart,highlightEnd,isEnabled);
        update();
    }
}

void Track::copy()
{
    if(highlightActive)
    {
        clipBoard=trackArray.copy(highlightStart,highlightEnd,isEnabled);
        update();
    }
}

void Track::paste()
{
    if(highlightStart>=0)
    {
        trackArray.paste(clipBoard,highlightStart,isEnabled);
        update();
    }
}

void Track::invert()
{
    if(highlightActive)
    {
        int i=0;
        int j=highlightStart;
        while(i<trackArray.getNumberOfChannels())
        {
            if(isEnabled.at(i))
            {
                j=highlightStart;
                while(j<=highlightEnd)
                {
                    trackArray.setBit(i,j,!trackArray.getBit(i,j));
                    j++;
                }
            }
            i++;
        }
        update();
    }
}

int Track::getChannelSize()
{
    return trackArray.getNumberOfChannels();
}

std::vector<QColor> Track::getColorArray()const
{
    return channelColors;
}

void Track::removeChannel(const int &inChannel)
{
    trackArray.removeChannel(inChannel);

    int i=inChannel;
    while(i<channelColors.size()-1)
    {
        isEnabled.at(i)=isEnabled.at(i+1);
        channelColors.at(i)=channelColors.at(i+1);
        i++;
    }
    isEnabled.pop_back();
    channelColors.pop_back();

}

void Track::clearAllData()
{
    trackArray.clearData();
    update();
}

void Track::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPen thePen;
    QBrush theBrush;
    theBrush.setStyle(Qt::SolidPattern);
    thePen.setStyle(Qt::SolidLine);
    QColor theColor;

    graphHeight=this->height()-tickerHeight;
    graphWidth=this->width()-channelTitleWidth;



    int startY=floor(scrollY/unitHeight);
    int startX=floor(scrollX/unitWidth);
    int endY=(graphHeight/unitHeight)+startY+1;
    int endX=(graphWidth/unitWidth)+startX+2;

    double bufferY = ((scrollY/unitHeight)-floor(scrollY/unitHeight)) * unitHeight;
    double bufferX = ((scrollX/unitWidth)-floor(scrollX/unitWidth)) * unitWidth;

    int i=0;
    int j=0;
    QString channelNumber;

    while(i+startY < endY && i+startY < trackArray.getNumberOfChannels())
    {
        j=0;
        while(j+startX < endX && j+startX < trackArray.getNumberOfIndexs())
        {
            if(trackArray.getBit(i+startY,j+startX))
            {
                if(isEnabled.at(i+startY))
                {
                    if(j+startX>=highlightStart && j+startX<=highlightEnd)
                    {
                        theColor=channelColors.at(i+startY);
                        //theColor.setRgb(0,255,255);
                        theColor.setRgb(255-channelColors.at(i+startY).red(),255-channelColors.at(i+startY).green(),255-channelColors.at(i+startY).blue());
                    }
                    else
                    {
                        theColor=channelColors.at(i+startY);

                        //theColor.setRgb(255,0,0);
                    }
                }
                else
                {
                    theColor.setRgb(180,180,180);
                }
            }
            else
            {
                if(j+startX>=highlightStart && j+startX<=highlightEnd)
                {
                    theColor.setRgb(120,120,255);
                }
                else
                {
                    theColor.setRgb(200,200,200);
                }
            }
            theBrush.setColor(theColor);
            if(unitWidth>3)
            {
                theColor.setRgb(230,230,230);
                thePen.setStyle(Qt::DashLine);
            }

            thePen.setColor(theColor);

            painter.setPen(thePen);
            painter.setBrush(theBrush);

            painter.drawRect(j*unitWidth-bufferX+channelTitleWidth,i*unitHeight-bufferY+tickerHeight,unitWidth,unitHeight);
            thePen.setStyle(Qt::SolidLine);

            theColor.setRgb(40,40,40);
            thePen.setColor(theColor);
            painter.setPen(thePen);

            painter.drawLine(j*unitWidth-bufferX+channelTitleWidth,i*unitHeight-bufferY+tickerHeight,j*unitWidth-bufferX+channelTitleWidth+unitWidth,i*unitHeight-bufferY+tickerHeight);
            painter.drawLine(j*unitWidth-bufferX+channelTitleWidth,i*unitHeight-bufferY+tickerHeight+unitHeight,j*unitWidth-bufferX+channelTitleWidth+unitWidth,i*unitHeight-bufferY+tickerHeight+unitHeight);
            j++;
        }
        theColor.setRgb(40,40,40);
        thePen.setColor(theColor);
        painter.setPen(thePen);
        theColor.setRgb(200,200,200);
        theBrush.setColor(theColor);
        painter.setBrush(theBrush);

        channelNumber=QString("Channel %1").arg(i+startY);
        painter.drawRect(0,i*unitHeight-bufferY+tickerHeight,channelTitleWidth,unitHeight);
        painter.drawText(3,i*unitHeight+(channelTitleYBuffer/2)-bufferY+tickerHeight,channelTitleWidth,unitHeight,Qt::AlignLeft,channelNumber);

        i++;
    }

    theColor.setRgb(200,200,200);
    thePen.setColor(theColor);
    theBrush.setColor(theColor);
    theBrush.setStyle(Qt::SolidPattern);
    painter.setBrush(theBrush);
    painter.setPen(thePen);

    painter.drawRect(channelTitleWidth,0,graphWidth,tickerHeight);
    if(highlightActive)
    {
        theColor.setRgb(120,120,255);
        thePen.setColor(theColor);
        theBrush.setColor(theColor);
        theBrush.setStyle(Qt::SolidPattern);
        painter.setBrush(theBrush);
        painter.setPen(thePen);
        painter.drawRect(highlightStart*unitWidth-(startX*unitWidth)+channelTitleWidth-bufferX,0,(highlightEnd+1-highlightStart)*unitWidth,tickerHeight);
    }

    j=0;
    int drawLine=0;
    int theLine=shortTickHeight;
    double theTime=0;
    int hour=0;
    int minutes=0;
    int seconds=0;
    QTime displayTime;

    theColor.setRgb(40,40,40);
    thePen.setColor(theColor);
    painter.setPen(thePen);

    if(trackArray.getNumberOfChannels()>0)
    {
        while(j+startX < endX && j+startX < (trackArray.getNumberOfIndexs())+1)
        {
            theLine=shortTickHeight;
            drawLine=(j+startX) % (int)(secondDivider/4);
            if(drawLine==0)
            {
                theLine=mediumTickHeight;
            }
            drawLine=(j+startX) % (int)(secondDivider/2);
            if(drawLine==0)
            {
                theLine=longTickHeight;
            }
            drawLine=(j+startX) % (int)(secondDivider);
            if(drawLine==0)
            {
                theTime = (j+startX)/secondDivider;
                hour=floor(theTime/3600);
                minutes=floor((theTime-hour*3600)/60);
                seconds=floor(((theTime-hour*3600)-minutes*60));
                displayTime=QTime(hour,minutes,seconds,0);

                painter.drawText(j*unitWidth-bufferX+channelTitleWidth-((double)tickerTextLength/2),10+longTickHeight,tickerTextLength,tickerTextHeight,Qt::AlignLeft,displayTime.toString("hh:mm:ss"));
            }

            painter.drawLine(j*unitWidth-bufferX+channelTitleWidth,5,j*unitWidth-bufferX+channelTitleWidth,5+theLine);
            j++;
        }
    }

    theColor.setRgb(20,50,200);
    thePen.setColor(theColor);
    painter.setPen(thePen);

    painter.drawLine(((double)playPosition*secondDivider)*unitWidth+channelTitleWidth-startX*unitWidth-bufferX,tickerHeight/2,((double)playPosition*secondDivider)*unitWidth+channelTitleWidth-startX*unitWidth-bufferX,graphHeight+tickerHeight/2);


    theBrush.setStyle(Qt::NoBrush);
    painter.setBrush(theBrush);

    painter.drawRect(0,0,this->width()-1,this->height()-1);
    theBrush.setStyle(Qt::SolidPattern);
    theColor.setRgb(120,120,120);
    thePen.setColor(theColor);
    theBrush.setColor(theColor);
    painter.setBrush(theBrush);
    painter.setPen(thePen);
    painter.drawRect(0,0,channelTitleWidth,tickerHeight);

    if(((double)playPosition*secondDivider)*unitWidth+channelTitleWidth-startX*unitWidth-bufferX > this->width() && isPlaying)
    {
        playScroll(scrollX+this->width()-channelTitleWidth);
    }
    if(((double)playPosition*secondDivider)*unitWidth+channelTitleWidth-startX*unitWidth-bufferX < channelTitleWidth && isPlaying)
    {
        playScroll(scrollX-channelTitleWidth);
    }

    if(playPosition>highlightEnd/secondDivider && keepLooping && highlightActive)
    {
        playPosition = highlightStart/secondDivider;
        userChangePlayPosition((qint64)(playPosition*1000));
    }

    if(playPosition>=highlightStart/secondDivider && playPosition<=highlightEnd/secondDivider && highlightActive)
    {
        theColor.setRgb(240,240,240);
    }
    else
    {
        theColor.setRgb(120,120,120);
    }
    thePen.setColor(theColor);
    painter.setPen(thePen);
    painter.drawLine(((double)playPosition*secondDivider)*unitWidth+channelTitleWidth-startX*unitWidth-bufferX,tickerHeight/2,((double)playPosition*secondDivider)*unitWidth+channelTitleWidth-startX*unitWidth-bufferX,graphHeight+tickerHeight/2);

}

void Track::mousePressEvent(QMouseEvent* event)
{
    if(event->pos().x()>channelTitleWidth && event->pos().y()>tickerHeight)
    {
        unsigned int locationX=floor((((double)event->pos().x()-(double)channelTitleWidth)/unitWidth)+((double)scrollX/unitWidth));
        unsigned int locationY=floor((((double)event->pos().y()-(double)tickerHeight)/unitHeight)+((double)scrollY/unitHeight));
        if(locationX < trackArray.getNumberOfIndexs() && locationY < trackArray.getNumberOfChannels())
        {
            if(event->button()==Qt::LeftButton)
            {
                if(isEnabled.at(locationY))
                {
                    trackArray.setBit(locationY,locationX,true);
                }
                leftMouseDown=1;
            }
            if(event->button()==Qt::RightButton)
            {
                if(isEnabled.at(locationY))
                {
                    trackArray.setBit(locationY,locationX,false);
                }
                rightMouseDown=1;
            }
            update();
        }
    }
    if(event->pos().x()>channelTitleWidth && event->pos().y()<tickerHeight)
    {
        if(event->button()==Qt::LeftButton)
        {
            playPosition = (((event->pos().x()-channelTitleWidth)/unitWidth)/secondDivider)+(scrollX/unitWidth)/secondDivider;//-bufferX;
            userChangePlayPosition((qint64)(playPosition*1000));
            if(highlightActive)
            {
                highlightActive=!highlightActive;
                highlightEnd=-1;
            }
            highlightStart = floor((((double)event->pos().x()-(double)channelTitleWidth)/unitWidth)+((double)scrollX/unitWidth));
        }
        if(event->button()==Qt::RightButton)
        {
            if(highlightStart!=-1)
            {
                int distanceCheck = floor((((double)event->pos().x()-(double)channelTitleWidth)/unitWidth)+((double)scrollX/unitWidth));
                if(highlightActive && (abs(distanceCheck-highlightEnd)>abs(distanceCheck-highlightStart)))
                {
                    highlightStart=highlightEnd;
                    highlightEnd=distanceCheck;
                }
                else
                {
                    highlightEnd=distanceCheck;
                }
                if(highlightEnd<highlightStart)
                {
                    int temp = highlightEnd;
                    highlightEnd=highlightStart;
                    highlightStart=temp;
                }
                highlightActive=true;

            }
        }

        update();
    }
    if(event->pos().x()<channelTitleWidth && event->pos().y()>tickerHeight)
    {
        if(event->button()==Qt::LeftButton)
        {
            unsigned int value = floor((event->pos().y()+scrollY-tickerHeight)/unitHeight);
            if(value<trackArray.getNumberOfChannels())
            {
                trackSelected(value,channelColors.at(value));
            }
        }
    }
}

void Track::mouseMoveEvent(QMouseEvent *event)
{
    if((leftMouseDown || rightMouseDown) && event->pos().x()>channelTitleWidth && event->pos().y()>tickerHeight)
    {
        int locationX=floor((((double)event->pos().x()-(double)channelTitleWidth)/unitWidth)+((double)scrollX/unitWidth));
        int locationY=floor((((double)event->pos().y()-(double)tickerHeight)/unitHeight)+((double)scrollY/unitHeight));
        if(locationX < trackArray.getNumberOfIndexs() && locationY < trackArray.getNumberOfChannels())
        {
            if(leftMouseDown)
            {
                if(isEnabled.at(locationY))
                {
                    trackArray.setBit(locationY,locationX,true);
                }
            }
            if(rightMouseDown)
            {
                if(isEnabled.at(locationY))
                {
                    trackArray.setBit(locationY,locationX,false);
                }
            }
            update();
        }

    }
}

void Track::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton)
    {
        leftMouseDown=0;
    }
    if(event->button()==Qt::RightButton)
    {
        rightMouseDown=0;
    }
}

void Track::scrollinX(const int inX)
{
    scrollX=inX;
    update();
}

void Track::scrollinY(const int inY)
{
    scrollY=inY;
    update();
}

void Track::playPositionChanged(qint64 inValue)
{
    playPosition=(double)inValue/1000;
    int temp = floor(playPosition*secondDivider);

    updatePicture(getBitArray(temp));


    update();
}


std::vector<char> Track::saveData()const
{
    std::vector<char> returnData;
    char highByte,lowByte;

    // ChunkID
    lowByte = 0x01;
    returnData.push_back(lowByte);

    // Overall Size
    int returnValue = (trackArray.getNumberOfChannels()*trackArray.getIndexByteSize()+6);
    lowByte=(unsigned char)(returnValue & 0xFF);
    highByte=(unsigned char)((returnValue >> 8) & 0xFF);
    returnData.push_back(highByte);
    returnData.push_back(lowByte);

    // Size of channels
    returnValue = trackArray.getNumberOfChannels();
    lowByte=(unsigned char)(returnValue & 0xFF);
    returnData.push_back(lowByte);

    //ChannelLenthInBytes
    returnValue = trackArray.getIndexByteSize();
    lowByte=(unsigned char)(returnValue & 0xFF);
    highByte=(unsigned char)((returnValue >> 8) & 0xFF);
    returnData.push_back(highByte);
    returnData.push_back(lowByte);

    //TrackArray Data
    int i = 0;
    int j = 0;
    while(i<trackArray.getNumberOfChannels())
    {
        j=0;
        while(j<trackArray.getIndexByteSize())
        {
            returnData.push_back(trackArray.getData(i,j));
            j++;
        }
        i++;
    }

    //ChannelColors Chunk ID
    lowByte = 0x02;
    returnData.push_back(lowByte);

    // ColorChunk size
    returnValue = channelColors.size()*3+3;
    lowByte=(unsigned char)(returnValue & 0xFF);
    highByte=(unsigned char)((returnValue >> 8) & 0xFF);
    returnData.push_back(highByte);
    returnData.push_back(lowByte);

    //channelColors data
    i=0;//channelColors.size()-1;
    while(i<channelColors.size())
    {
        returnData.push_back((unsigned char)channelColors.at(i).red());
        returnData.push_back((unsigned char)channelColors.at(i).green());
        returnData.push_back((unsigned char)channelColors.at(i).blue());
        i++;
    }
    return returnData;
}

void Track::loadSavedData(const QByteArray &inData)
{
    const int Header = 9;
    unsigned char highByte,lowByte;
    int overallSize,channelSize,channelLength,colorSize;
    int numberOfChunks = inData[8];
    char chunkID;
    int fileLocation = 0;
    QColor tempColor;


    int i = 0,j = 0,k = 0;
    while(k<numberOfChunks)
    {
        chunkID = inData[fileLocation+Header];
        switch(chunkID)
        {
        case 0x01:
            //Channel Size
            channelSize=inData[fileLocation+Header+3];

            //Channel Length
            highByte=inData[fileLocation+Header+4];
            lowByte=inData[fileLocation+Header+5];
            channelLength=(highByte<<8) | lowByte;

            songAdded=1;
            trackArray.addLength((channelLength+1)*8);
            songLength=(double)(channelLength+1)*8/secondDivider;

            i=0;
            while(i<channelSize)
            {
                isEnabled.push_back(true);
                trackArray.addChannel();
                i++;
            }

            i=0;
            j=0;
            while(i<channelSize)
            {
                j=0;
                while(j<channelLength)
                {
                    trackArray.setData(i,j,inData.at((i*channelLength+j)+fileLocation+Header+6));
                    j++;
                }
                i++;
            }
            highByte=inData[fileLocation+Header+1];
            lowByte=inData[fileLocation+Header+2];
            overallSize=(highByte<<8) | lowByte;
            fileLocation+=overallSize;
            break;
        case 0x02:
            highByte=inData[fileLocation+Header+1];
            lowByte=inData[fileLocation+Header+2];
            colorSize =(highByte<<8) | lowByte;
            colorSize-=3;
            channelColors.clear();
            i=0;
            while(i<colorSize)
            {
                tempColor.setRgb((unsigned char)inData[fileLocation+Header+i+3+0],
                                 (unsigned char)inData[fileLocation+Header+i+3+1],
                                 (unsigned char)inData[fileLocation+Header+i+3+2]);
                channelColors.push_back(tempColor);
                i+=3;
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























