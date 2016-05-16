#include "channelcolordisplay.h"
#include <QPainter>
#include <QMouseEvent>
#include <QColorDialog>

channelColorDisplay::channelColorDisplay(QWidget *parent) :
    QLabel(parent)
{
    theColor.setRgb(255,0,0);
    setFixedWidth(20);
    setFixedHeight(20);

}

QColor channelColorDisplay::getThisColor()const
{
    return theColor;
}

void channelColorDisplay::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QBrush theBrush;
    theBrush.setStyle(Qt::SolidPattern);
    theBrush.setColor(theColor);
    QPen thePen;
    thePen.setStyle(Qt::SolidLine);
    thePen.setColor(theColor);
    painter.setBrush(theBrush);
    painter.setPen(thePen);
    painter.drawRect(0,0,width(),height());
}

void channelColorDisplay::setColor(const QColor &inColor)
{
    theColor=inColor;
    update();
}

void channelColorDisplay::mousePressEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton)
    {
        theColor = QColorDialog::getColor(theColor);
        channelColorChanged(theColor);
        update();
    }
}


