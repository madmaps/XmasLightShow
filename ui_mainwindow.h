/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "track.h"
#include "visualdisplay.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionImport_Image;
    QAction *actionImport_Song;
    QAction *actionSave_Project;
    QAction *actionLoad_Project;
    QAction *actionExit;
    QAction *actionCut;
    QAction *actionCopy;
    QAction *actionPaste;
    QAction *actionPort_Settings;
    QAction *actionModule_Settings;
    QAction *actionManage_Playlist;
    QAction *actionEnable_Playlist;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_6;
    visualDisplay *label;
    QSpacerItem *horizontalSpacer_7;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *StopButton;
    QPushButton *PlayButton;
    QCheckBox *enableSerialOut;
    QSpacerItem *horizontalSpacer_5;
    QCheckBox *loop;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *playbackRateDecrease;
    QLabel *label_3;
    QPushButton *playbackRateIncrease;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QPushButton *AddTrack;
    QVBoxLayout *verticalLayout;
    Track *label_2;
    QScrollBar *horizontalScrollBar;
    QScrollBar *verticalScrollBar;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_8;
    QPushButton *cutButton;
    QPushButton *copyButton;
    QPushButton *pasteButton;
    QPushButton *invertButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *zoomOut;
    QPushButton *zoomIn;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuOutput;
    QMenu *menuPlaylist;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(870, 652);
        actionImport_Image = new QAction(MainWindow);
        actionImport_Image->setObjectName(QStringLiteral("actionImport_Image"));
        actionImport_Song = new QAction(MainWindow);
        actionImport_Song->setObjectName(QStringLiteral("actionImport_Song"));
        actionSave_Project = new QAction(MainWindow);
        actionSave_Project->setObjectName(QStringLiteral("actionSave_Project"));
        actionLoad_Project = new QAction(MainWindow);
        actionLoad_Project->setObjectName(QStringLiteral("actionLoad_Project"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionCut = new QAction(MainWindow);
        actionCut->setObjectName(QStringLiteral("actionCut"));
        actionCopy = new QAction(MainWindow);
        actionCopy->setObjectName(QStringLiteral("actionCopy"));
        actionPaste = new QAction(MainWindow);
        actionPaste->setObjectName(QStringLiteral("actionPaste"));
        actionPort_Settings = new QAction(MainWindow);
        actionPort_Settings->setObjectName(QStringLiteral("actionPort_Settings"));
        actionModule_Settings = new QAction(MainWindow);
        actionModule_Settings->setObjectName(QStringLiteral("actionModule_Settings"));
        actionManage_Playlist = new QAction(MainWindow);
        actionManage_Playlist->setObjectName(QStringLiteral("actionManage_Playlist"));
        actionEnable_Playlist = new QAction(MainWindow);
        actionEnable_Playlist->setObjectName(QStringLiteral("actionEnable_Playlist"));
        actionEnable_Playlist->setCheckable(true);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_3 = new QVBoxLayout(centralWidget);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_6);

        label = new visualDisplay(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setFrameShape(QFrame::WinPanel);
        label->setFrameShadow(QFrame::Sunken);

        horizontalLayout_2->addWidget(label);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_7);


        verticalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        StopButton = new QPushButton(centralWidget);
        StopButton->setObjectName(QStringLiteral("StopButton"));

        horizontalLayout_3->addWidget(StopButton);

        PlayButton = new QPushButton(centralWidget);
        PlayButton->setObjectName(QStringLiteral("PlayButton"));

        horizontalLayout_3->addWidget(PlayButton);

        enableSerialOut = new QCheckBox(centralWidget);
        enableSerialOut->setObjectName(QStringLiteral("enableSerialOut"));

        horizontalLayout_3->addWidget(enableSerialOut);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);

        loop = new QCheckBox(centralWidget);
        loop->setObjectName(QStringLiteral("loop"));
        loop->setChecked(false);

        horizontalLayout_3->addWidget(loop);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        playbackRateDecrease = new QPushButton(centralWidget);
        playbackRateDecrease->setObjectName(QStringLiteral("playbackRateDecrease"));

        horizontalLayout_3->addWidget(playbackRateDecrease);

        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_3->addWidget(label_3);

        playbackRateIncrease = new QPushButton(centralWidget);
        playbackRateIncrease->setObjectName(QStringLiteral("playbackRateIncrease"));

        horizontalLayout_3->addWidget(playbackRateIncrease);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);


        verticalLayout_3->addLayout(horizontalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        AddTrack = new QPushButton(centralWidget);
        AddTrack->setObjectName(QStringLiteral("AddTrack"));
        AddTrack->setMaximumSize(QSize(100, 16777215));

        verticalLayout_2->addWidget(AddTrack);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_2 = new Track(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setMinimumSize(QSize(0, 180));
        label_2->setMaximumSize(QSize(16777215, 1800));
        label_2->setFrameShape(QFrame::NoFrame);

        verticalLayout->addWidget(label_2);

        horizontalScrollBar = new QScrollBar(centralWidget);
        horizontalScrollBar->setObjectName(QStringLiteral("horizontalScrollBar"));
        horizontalScrollBar->setMaximum(14400);
        horizontalScrollBar->setSingleStep(10);
        horizontalScrollBar->setPageStep(100);
        horizontalScrollBar->setOrientation(Qt::Horizontal);
        horizontalScrollBar->setInvertedAppearance(false);
        horizontalScrollBar->setInvertedControls(true);

        verticalLayout->addWidget(horizontalScrollBar);


        horizontalLayout->addLayout(verticalLayout);

        verticalScrollBar = new QScrollBar(centralWidget);
        verticalScrollBar->setObjectName(QStringLiteral("verticalScrollBar"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(verticalScrollBar->sizePolicy().hasHeightForWidth());
        verticalScrollBar->setSizePolicy(sizePolicy1);
        verticalScrollBar->setMaximum(500);
        verticalScrollBar->setSingleStep(10);
        verticalScrollBar->setPageStep(50);
        verticalScrollBar->setOrientation(Qt::Vertical);

        horizontalLayout->addWidget(verticalScrollBar);


        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_8);

        cutButton = new QPushButton(centralWidget);
        cutButton->setObjectName(QStringLiteral("cutButton"));

        horizontalLayout_4->addWidget(cutButton);

        copyButton = new QPushButton(centralWidget);
        copyButton->setObjectName(QStringLiteral("copyButton"));

        horizontalLayout_4->addWidget(copyButton);

        pasteButton = new QPushButton(centralWidget);
        pasteButton->setObjectName(QStringLiteral("pasteButton"));

        horizontalLayout_4->addWidget(pasteButton);

        invertButton = new QPushButton(centralWidget);
        invertButton->setObjectName(QStringLiteral("invertButton"));

        horizontalLayout_4->addWidget(invertButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        zoomOut = new QPushButton(centralWidget);
        zoomOut->setObjectName(QStringLiteral("zoomOut"));

        horizontalLayout_4->addWidget(zoomOut);

        zoomIn = new QPushButton(centralWidget);
        zoomIn->setObjectName(QStringLiteral("zoomIn"));

        horizontalLayout_4->addWidget(zoomIn);


        verticalLayout_3->addLayout(horizontalLayout_4);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 870, 25));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        menuOutput = new QMenu(menuBar);
        menuOutput->setObjectName(QStringLiteral("menuOutput"));
        menuPlaylist = new QMenu(menuBar);
        menuPlaylist->setObjectName(QStringLiteral("menuPlaylist"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuOutput->menuAction());
        menuBar->addAction(menuPlaylist->menuAction());
        menuFile->addAction(actionImport_Image);
        menuFile->addAction(actionImport_Song);
        menuFile->addSeparator();
        menuFile->addAction(actionSave_Project);
        menuFile->addAction(actionLoad_Project);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuEdit->addAction(actionCut);
        menuEdit->addAction(actionCopy);
        menuEdit->addAction(actionPaste);
        menuOutput->addAction(actionPort_Settings);
        menuOutput->addAction(actionModule_Settings);
        menuPlaylist->addAction(actionManage_Playlist);
        menuPlaylist->addAction(actionEnable_Playlist);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Lightshow Editor", 0));
        actionImport_Image->setText(QApplication::translate("MainWindow", "Import Image", 0));
        actionImport_Song->setText(QApplication::translate("MainWindow", "Import Song", 0));
        actionSave_Project->setText(QApplication::translate("MainWindow", "Save Project", 0));
        actionLoad_Project->setText(QApplication::translate("MainWindow", "Load Project", 0));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", 0));
        actionCut->setText(QApplication::translate("MainWindow", "Cut", 0));
        actionCopy->setText(QApplication::translate("MainWindow", "Copy", 0));
        actionPaste->setText(QApplication::translate("MainWindow", "Paste", 0));
        actionPort_Settings->setText(QApplication::translate("MainWindow", "Port Settings", 0));
        actionModule_Settings->setText(QApplication::translate("MainWindow", "Module Settings", 0));
        actionManage_Playlist->setText(QApplication::translate("MainWindow", "Manage Playlist", 0));
        actionEnable_Playlist->setText(QApplication::translate("MainWindow", "Enable Playlist", 0));
        label->setText(QString());
        StopButton->setText(QApplication::translate("MainWindow", "Stop", 0));
        PlayButton->setText(QApplication::translate("MainWindow", "Play", 0));
        enableSerialOut->setText(QApplication::translate("MainWindow", "Enable Output", 0));
        loop->setText(QApplication::translate("MainWindow", "Loop", 0));
        playbackRateDecrease->setText(QApplication::translate("MainWindow", "-", 0));
        label_3->setText(QApplication::translate("MainWindow", "1.0", 0));
        playbackRateIncrease->setText(QApplication::translate("MainWindow", "+", 0));
        AddTrack->setText(QApplication::translate("MainWindow", "Add Channel", 0));
        label_2->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        cutButton->setText(QApplication::translate("MainWindow", "Cut", 0));
        copyButton->setText(QApplication::translate("MainWindow", "Copy", 0));
        pasteButton->setText(QApplication::translate("MainWindow", "Paste", 0));
        invertButton->setText(QApplication::translate("MainWindow", "Invert", 0));
        zoomOut->setText(QApplication::translate("MainWindow", "-", 0));
        zoomIn->setText(QApplication::translate("MainWindow", "+", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
        menuEdit->setTitle(QApplication::translate("MainWindow", "Edit", 0));
        menuOutput->setTitle(QApplication::translate("MainWindow", "Output", 0));
        menuPlaylist->setTitle(QApplication::translate("MainWindow", "Playlist", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
