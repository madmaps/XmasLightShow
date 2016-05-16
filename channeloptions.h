#ifndef CHANNELOPTIONS_H
#define CHANNELOPTIONS_H

#include <QDialog>
#include <QPushButton>
#include <QCheckBox>
#include <QLabel>
#include <QVBoxLayout>
#include <QColor>
#include "channelcolordisplay.h"

class channelOptions : public QDialog
{
    Q_OBJECT
public:
    explicit channelOptions(QWidget *parent = 0);
    void setChannel(const unsigned int& inChannel);
    void setChannelColor(const QColor& inColor);
    ~channelOptions();

signals:
    void theColorChanged(unsigned int outChannel,QColor outColor);
    void changeEditMode(bool outEditMode);
    void removeChannel(int outChannel);
    void channelEnableButtonPushed(int outChannel,bool outData);

public slots:
    void channelColorChanged(QColor value);
    void editButtonPushed();
    void removeThisChannel();
    void enabledButtonPushed(bool outData);
    void changeEnabledState(bool inData);
private:

    QPushButton* editButton;
    channelColorDisplay* currentColor;
    QCheckBox* enabledButton;
    QVBoxLayout* theLayout;
    QPushButton* removeButton;

    unsigned int currentChannel;
    bool editMode;


};

#endif // CHANNELOPTIONS_H
