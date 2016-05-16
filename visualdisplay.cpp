#include "visualdisplay.h"
#include <QPainter>

visualDisplay::visualDisplay(QWidget *parent) :
    QLabel(parent)
{
    editMode=0;
    scaledImage = NULL;
}


bool visualDisplay::loadImage(const QPixmap &inImage)
{
    if(scaledImage!=NULL)
    {
        delete scaledImage;
        scaledImage = NULL;
    }
    scaledImage=new QPixmap(inImage);
    update();
    return true;
}

void visualDisplay::changeEditMode(bool inEditMode)
{
    editMode=inEditMode;
    update();
}

void visualDisplay::removeChannel(const int &inChannel)
{
    int i=inChannel;
    while(i<lightColors.size()-1)
    {
        lightColors.at(i)=lightColors.at(i+1);
        drawLights.at(i)=drawLights.at(i+1);
        isEnabled.at(i)=isEnabled.at(i+1);
        i++;
    }
    lightColors.pop_back();
    drawLights.pop_back();
    isEnabled.pop_back();
}

void visualDisplay::addChannel(const QColor &inColor)
{
    std::vector<double> temp;
    drawLights.push_back(temp);
    lightColors.push_back(inColor);
    isEnabled.push_back(true);
}

void visualDisplay::changeColor(const unsigned int &inChannel, const QColor &inColor)
{
    lightColors.at(inChannel)=inColor;
    update();

}

void visualDisplay::setActiveChannel(const unsigned int &inActiveChannel)
{
    activeChannel=inActiveChannel;
    update();
}

void visualDisplay::clearAllData()
{
    drawLights.clear();
    lightColors.clear();
    whatToLight.clearData();
    isEnabled.clear();
}

void visualDisplay::addColorArray(const std::vector<QColor> &inColorArray)
{
    lightColors.clear();
    lightColors=inColorArray;
}

void visualDisplay::setChannelEnabled(const int &inChannel, const bool &inData)
{
    isEnabled.at(inChannel)=inData;
}

bool visualDisplay::getIsChannelEnabled(const int &inChannel) const
{
    return isEnabled.at(inChannel);
}

void visualDisplay::paintEvent(QPaintEvent *event)
{
    if(scaledImage!=NULL)
    {
        QPainter painter(this);
        QPen thePen;
        thePen.setWidth(2);

        painter.drawPixmap(0,0,width(),height(),*scaledImage);
        if(!editMode)
        {
            if(drawLights.size()>0 && whatToLight.getNumberOfChannels()>0)//!editMode &&
            {
                int i=0;
                int j=0;
                while(i<drawLights.size())
                {
                    if(whatToLight.getBit(0,i) && isEnabled.at(i))
                    {
                        j=0;
                        thePen.setColor(lightColors.at(i));
                        painter.setPen(thePen);

                        while((int)j<=(int)drawLights.at(i).size()-3)
                        {
                            painter.drawLine(drawLights.at(i).at(j+0)*width(),drawLights.at(i).at(j+1)*height(),drawLights.at(i).at(j+2)*width(),drawLights.at(i).at(j+3)*height());
                            j+=2;
                        }
                    }
                    i++;
                }
            }


        }
        else
        {
            QColor tempColor;
            if(drawLights.size()>0)// && whatToLight.getNumberOfChannels()>0)//!editMode &&
            {
                int i=0;
                int j=0;
                while(i<drawLights.size())
                {
                    j=0;
                    thePen.setStyle(Qt::SolidLine);
                    thePen.setWidth(2);

                    if(i==activeChannel)
                    {
                        thePen.setColor(lightColors.at(i));
                    }
                    else
                    {
                        tempColor.setRgb(230,230,230);
                        thePen.setColor(tempColor);
                    }
                    if(!isEnabled.at(i))
                    {
                        tempColor.setRgb(130,130,130);
                        thePen.setColor(tempColor);
                        thePen.setStyle(Qt::DashLine);
                        thePen.setWidth(1);
                    }
                        painter.setPen(thePen);

                    while((int)j<=(int)drawLights.at(i).size()-3)
                    {
                        painter.drawLine(drawLights.at(i).at(j+0)*width(),drawLights.at(i).at(j+1)*height(),drawLights.at(i).at(j+2)*width(),drawLights.at(i).at(j+3)*height());
                        j+=2;
                    }
                    i++;
                }
            }

        }


    }
}

void visualDisplay::mousePressEvent(QMouseEvent *event)
{
    if(editMode && isEnabled.at(activeChannel))
    {
        if(event->button()==Qt::LeftButton)
        {
            drawLights.at(activeChannel).push_back((double)event->pos().x()/(double)width());
            drawLights.at(activeChannel).push_back((double)event->pos().y()/(double)height());
            update();
        }
        if(event->button()==Qt::RightButton)
        {
            if(drawLights.at(activeChannel).size()>0)
            {
                drawLights.at(activeChannel).pop_back();
                drawLights.at(activeChannel).pop_back();
                update();
            }
        }
    }
}

void visualDisplay::whatToLightUp(const binaryTrack &inTrack)
{
    whatToLight=inTrack;
    update();
}


std::vector<char> visualDisplay::saveData() const
{
    std::vector<char> returnData;
    unsigned char returnByte[8]={};
    int returnValue=0;

    //Visial ID
    returnByte[0]=0x05;
    returnData.push_back(returnByte[0]);

    //Chunk Size
    int i=0;
    while(i<drawLights.size())
    {
        returnValue+=drawLights.at(i).size();
        i++;
    }
    returnValue*=4;
    returnValue+=4+drawLights.size();

    returnByte[0]=(unsigned char)(returnValue & 0xFF);
    returnByte[1]=(unsigned char)((returnValue >> 8) & 0xFF);
    returnData.push_back(returnByte[1]);
    returnData.push_back(returnByte[0]);

    //ChannelSize
    returnValue = drawLights.size();
    returnByte[0]=(unsigned char)(returnValue & 0xFF);
    returnData.push_back(returnByte[0]);

    i=0;
    int j=0;
    while(i<drawLights.size())
    {
        returnValue=(unsigned char)drawLights.at(i).size();
        returnData.push_back(returnValue);
        j=0;
        while(j<drawLights.at(i).size())
        {
            returnValue=drawLights.at(i).at(j)*100000;
            for(int k=0;k<=3;k++)
            {
                returnByte[k]=(unsigned char)((returnValue >> (8*k)) & 0xFF);
            }
            for(int k=3;k>=0;k--)
            {
                returnData.push_back(returnByte[k]);
            }

            j++;
        }
        i++;
    }
    return returnData;
}

void visualDisplay::loadSavedData(const QByteArray& inData)
{
    const int Header = 9;
    int overallSize;
    int colorSize;
    int numberOfChunks = inData[8];
    char chunkID;
    int fileLocation = 0;
    unsigned char highByte;
    unsigned char lowByte;
    unsigned int returnValue,pointCount;
    int dataCount=0;
    std::vector<double> tempDouble;
    int channelSize=0;


    QColor tempColor;


    int i = 0,j = 0,t = 0;
    while(t<numberOfChunks)
    {
        chunkID = (unsigned char)inData[fileLocation+Header];
        switch(chunkID)
        {
        case 0x05:
            //Channel Size
            channelSize=inData[fileLocation+Header+3];
            dataCount=fileLocation+Header+4;

            drawLights.clear();
            isEnabled.clear();
            i=0,j=0;
            while(i<channelSize)
            {
                pointCount=(int)inData[dataCount];
                dataCount++;
                tempDouble.clear();
                j=0;
                while(j<pointCount)
                {
                    returnValue=0;
                    for(int k=0;k<=3;k++)
                    {
                       returnValue=((returnValue << 8) | (unsigned char)inData[dataCount]);
                       dataCount++;
                    }
                    tempDouble.push_back((double)returnValue/100000);
                    j++;
                }
                drawLights.push_back(tempDouble);
                isEnabled.push_back(true);
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
            lightColors.clear();
            i=0;
            while(i<colorSize)
            {
                tempColor.setRgb((unsigned char)inData[fileLocation+Header+i+3+0],
                                 (unsigned char)inData[fileLocation+Header+i+3+1],
                                 (unsigned char)inData[fileLocation+Header+i+3+2]);
                lightColors.push_back(tempColor);
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
        t++;
    }
}























