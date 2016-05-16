#ifndef VISUALDISPLAY_H
#define VISUALDISPLAY_H

#include <QLabel>
#include <QPixmap>
#include "binarytrack.h"
#include <QMouseEvent>

class visualDisplay : public QLabel
{
    Q_OBJECT
public:
    explicit visualDisplay(QWidget *parent = 0);
    bool loadImage(const QPixmap& inImage);
    void addChannel(const QColor& inColor);
    void changeColor(const unsigned int& inChannel,const QColor& inColor);
    void setActiveChannel(const unsigned int& inActiveChannel);
    std::vector<char> saveData() const;
    void loadSavedData(const QByteArray &inData);
    void clearAllData();
    void addColorArray(const std::vector<QColor>& inColorArray);
    void removeChannel(const int& inChannel);
    void setChannelEnabled(const int& inChannel,const bool& inData);
    bool getIsChannelEnabled(const int& inChannel)const;


signals:

public slots:
    void whatToLightUp(const binaryTrack& inTrack);
    void changeEditMode(bool inEditMode);


protected:
    void paintEvent(QPaintEvent* event);
    void mousePressEvent(QMouseEvent* event);

private:
    QPixmap* scaledImage;
    std::vector<std::vector<double>> drawLights;
    std::vector<QColor> lightColors;
    binaryTrack whatToLight;
    std::vector<bool> isEnabled;
    bool editMode;
    unsigned int activeChannel;

};

#endif // VISUALDISPLAY_H
