#ifndef TRACK_H
#define TRACK_H

#include <QLabel>
#include <QMouseEvent>
#include <vector>
#include <binarytrack.h>

class Track : public QLabel
{
    Q_OBJECT
public:
    explicit Track(QWidget *parent = 0);
    void addNewTrack();
    void addSong(const double& inLength);
    void zoomIn();
    void zoomOut();
    bool isSongAdded();
    int getScrollSize() const;
    void setPlayState(const bool& inPlayState);
    void setLoop(const bool& inLoop);
    void cut();
    void copy();
    void paste();
    void invert();
    void setChannelColor(const int& inChannel, const QColor& inColor);
    binaryTrack getBitArray(const int& inIndex) const;
    std::vector<char> saveData() const;
    void loadSavedData(const QByteArray& inData);
    void resetSongAdded();
    int getChannelSize();
    std::vector<QColor> getColorArray()const;
    void removeChannel(const int& inChannel);
    void setChannelEnabled(const int& inChannel,const bool& inData);
    bool getChannelEnabled(const int& inChannel)const;
    void clearAllData();



signals:
    void playScroll(int value);
    void userChangePlayPosition(qint64 inValue);
    void trackSelected(unsigned int outChannel,QColor outColor);
    void updatePicture(binaryTrack outValue);

public slots:
    void scrollinX(const int inX);
    void scrollinY(const int inY);
    void playPositionChanged(qint64 inValue);



protected:
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);

private:


    //int numberOfTrackIndexs;
    bool leftMouseDown;
    bool rightMouseDown;
    double songLength;
    double secondDivider;
    binaryTrack trackArray;
    std::vector<QColor> channelColors;
    std::vector<bool> isEnabled;

    binaryTrack clipBoard;
    int scrollX;
    int scrollY;
    double unitWidth;
    double unitHeight;
    int channelTitleWidth;
    int channelTitleYBuffer;
    int channelTitleXBuffer;
    int tickerHeight;

    int graphHeight;
    int graphWidth;

    int shortTickHeight;
    int mediumTickHeight;
    int longTickHeight;
    int tickerTextLength;
    int tickerTextHeight;

    bool songAdded;

    double playPosition;

    bool isPlaying;

    int highlightStart;
    int highlightEnd;
    bool highlightActive;

    bool keepLooping;




};

#endif // TRACK_H
