#ifndef CHANNELCOLORDISPLAY_H
#define CHANNELCOLORDISPLAY_H

#include <QLabel>
#include <QColor>

class channelColorDisplay : public QLabel
{
    Q_OBJECT
public:
    explicit channelColorDisplay(QWidget *parent = 0);
    QColor getThisColor()const;
    void setColor(const QColor& inColor);

signals:
    void channelColorChanged(QColor value);

public slots:

protected:
    void paintEvent(QPaintEvent* event);
    void mousePressEvent(QMouseEvent* event);

private:
    QColor theColor;

};

#endif // CHANNELCOLORDISPLAY_H
