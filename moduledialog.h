#ifndef MODULEDIALOG_H
#define MODULEDIALOG_H

#include <QDialog>
#include <QModelIndex>
#include "module.h"

namespace Ui {
class moduleDialog;
}

class moduleDialog : public QDialog
{
    Q_OBJECT

public:
    explicit moduleDialog(QWidget *parent = 0);
    void addChannel();
    std::vector<char> saveData()const;
    void loadSavedData(const QByteArray& inData);

    std::vector<char> getOutputData(const binaryTrack& inData)const;
    void deleteChannel(const int& inChannel);

    ~moduleDialog();

private slots:
    void removeChannelFromMod();
    void addModule();
    void removeModule();
    void updateModInfo(QModelIndex theIndex);
    void addChannelToMod();
    void moveModChannelUp();
    void moveModChannelDown();
    void applyModID();


private:
    void updateModChannelView();
    Ui::moduleDialog *ui;
    std::vector<module> moduleList;
    int numberOfChannels;
};

#endif // MODULEDIALOG_H
