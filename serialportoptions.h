#ifndef SERIALPORTOPTIONS_H
#define SERIALPORTOPTIONS_H

#include <QDialog>
#include <QString>

namespace Ui {
class serialPortOptions;
}

class serialPortOptions : public QDialog
{
    Q_OBJECT

public:
    explicit serialPortOptions(QWidget *parent = 0);
    void setPortNameText(QString inText);

    ~serialPortOptions();

public slots:
    void okButtonHit();

signals:
    void setNewSerialPort(QString outText);

private:
    Ui::serialPortOptions *ui;
};

#endif // SERIALPORTOPTIONS_H
