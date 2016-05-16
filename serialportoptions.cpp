#include "serialportoptions.h"
#include "ui_serialportoptions.h"

serialPortOptions::serialPortOptions(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::serialPortOptions)
{
    ui->setupUi(this);
    connect(ui->okButton,SIGNAL(clicked()),this,SLOT(okButtonHit()));
    connect(ui->okButton,SIGNAL(clicked()),this,SLOT(close()));
    connect(ui->cancleButton,SIGNAL(clicked()),this,SLOT(close()));


}

serialPortOptions::~serialPortOptions()
{
    delete ui;
}

void serialPortOptions::setPortNameText(QString inText)
{
    ui->serialPortNameLineEdit->setText(inText);
}

void serialPortOptions::okButtonHit()
{
    setNewSerialPort(ui->serialPortNameLineEdit->text());
}
