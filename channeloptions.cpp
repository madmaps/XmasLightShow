#include "channeloptions.h"

channelOptions::channelOptions(QWidget *parent) :
    QDialog(parent)
{
    this->setMinimumWidth(200);
    editButton = new QPushButton(this);
    editButton->setText("EDIT");

    currentColor = new channelColorDisplay(this);
    //currentColor->setText("Color");

    enabledButton = new QCheckBox(this);
    enabledButton->setText("Enabled");
    enabledButton->setChecked(true);

    removeButton = new QPushButton(this);
    removeButton->setText("Remove");

    theLayout = new QVBoxLayout(this);
    theLayout->addWidget(enabledButton);
    theLayout->addWidget(currentColor);
    theLayout->addWidget(editButton);
    theLayout->addWidget(removeButton);
    theLayout->setAlignment(Qt::AlignCenter);

    setLayout(theLayout);

    connect(currentColor,SIGNAL(channelColorChanged(QColor)),this,SLOT(channelColorChanged(QColor)));
    connect(editButton,SIGNAL(clicked()),this,SLOT(editButtonPushed()));
    connect(removeButton,SIGNAL(clicked()),this,SLOT(removeThisChannel()));
    connect(enabledButton,SIGNAL(clicked(bool)),this,SLOT(enabledButtonPushed(bool)));
    currentChannel=0;

}

channelOptions::~channelOptions()
{
    theLayout->removeWidget(enabledButton);
    theLayout->removeWidget(currentColor);
    theLayout->removeWidget(editButton);
    theLayout->removeWidget(removeButton);
    delete theLayout;
    delete editButton;
    delete currentColor;
    delete enabledButton;
    delete removeButton;
}

void channelOptions::setChannel(const unsigned int &inChannel)
{
    currentChannel=inChannel;
    this->setWindowTitle(QString("Channel %1").arg(currentChannel));
}

void channelOptions::editButtonPushed()
{
    if(editMode)
    {
        editButton->setText("EDIT");
        editMode=0;
        changeEditMode(editMode);
    }
    else
    {
        editButton->setText("DONE");
        editMode=1;
        changeEditMode(editMode);

    }


}

void channelOptions::changeEnabledState(bool inData)
{
    enabledButton->setChecked(inData);
}

void channelOptions::setChannelColor(const QColor &inColor)
{
    currentColor->setColor(inColor);
}

void channelOptions::channelColorChanged(QColor value)
{
    theColorChanged(currentChannel,value);
}

void channelOptions::removeThisChannel()
{
    removeChannel(currentChannel);
}

void channelOptions::enabledButtonPushed(bool outData)
{
    channelEnableButtonPushed(currentChannel,outData);
}

