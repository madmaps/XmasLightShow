/********************************************************************************
** Form generated from reading UI file 'playlist.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLAYLIST_H
#define UI_PLAYLIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_playlist
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_2;
    QPushButton *addFilesButton;
    QPushButton *removeSongsButton;
    QPushButton *loadPlaylistButton;
    QPushButton *savePlaylistButton;
    QVBoxLayout *verticalLayout_3;
    QSpacerItem *verticalSpacer;
    QListWidget *listWidget;
    QSpacerItem *verticalSpacer_2;
    QVBoxLayout *verticalLayout;
    QPushButton *moveUpButton;
    QPushButton *moveDownButton;

    void setupUi(QDialog *playlist)
    {
        if (playlist->objectName().isEmpty())
            playlist->setObjectName(QStringLiteral("playlist"));
        playlist->resize(519, 300);
        gridLayout = new QGridLayout(playlist);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        addFilesButton = new QPushButton(playlist);
        addFilesButton->setObjectName(QStringLiteral("addFilesButton"));

        verticalLayout_2->addWidget(addFilesButton);

        removeSongsButton = new QPushButton(playlist);
        removeSongsButton->setObjectName(QStringLiteral("removeSongsButton"));

        verticalLayout_2->addWidget(removeSongsButton);

        loadPlaylistButton = new QPushButton(playlist);
        loadPlaylistButton->setObjectName(QStringLiteral("loadPlaylistButton"));

        verticalLayout_2->addWidget(loadPlaylistButton);

        savePlaylistButton = new QPushButton(playlist);
        savePlaylistButton->setObjectName(QStringLiteral("savePlaylistButton"));

        verticalLayout_2->addWidget(savePlaylistButton);


        gridLayout->addLayout(verticalLayout_2, 0, 0, 1, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        listWidget = new QListWidget(playlist);
        listWidget->setObjectName(QStringLiteral("listWidget"));

        verticalLayout_3->addWidget(listWidget);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_2);


        gridLayout->addLayout(verticalLayout_3, 0, 1, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        moveUpButton = new QPushButton(playlist);
        moveUpButton->setObjectName(QStringLiteral("moveUpButton"));

        verticalLayout->addWidget(moveUpButton);

        moveDownButton = new QPushButton(playlist);
        moveDownButton->setObjectName(QStringLiteral("moveDownButton"));

        verticalLayout->addWidget(moveDownButton);


        gridLayout->addLayout(verticalLayout, 0, 2, 1, 1);


        retranslateUi(playlist);

        QMetaObject::connectSlotsByName(playlist);
    } // setupUi

    void retranslateUi(QDialog *playlist)
    {
        playlist->setWindowTitle(QApplication::translate("playlist", "Playlist", 0));
        addFilesButton->setText(QApplication::translate("playlist", "Add Songs", 0));
        removeSongsButton->setText(QApplication::translate("playlist", "Remove Songs", 0));
        loadPlaylistButton->setText(QApplication::translate("playlist", "Load Playlist", 0));
        savePlaylistButton->setText(QApplication::translate("playlist", "Save Playlist", 0));
        moveUpButton->setText(QApplication::translate("playlist", "^", 0));
        moveDownButton->setText(QApplication::translate("playlist", "v", 0));
    } // retranslateUi

};

namespace Ui {
    class playlist: public Ui_playlist {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLAYLIST_H
