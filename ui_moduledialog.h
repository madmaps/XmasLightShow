/********************************************************************************
** Form generated from reading UI file 'moduledialog.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODULEDIALOG_H
#define UI_MODULEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_moduleDialog
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *idLabel;
    QLineEdit *idLineEdit;
    QPushButton *idApplyButton;
    QListWidget *moduleChannelListView;
    QListWidget *moduleListView;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer_3;
    QPushButton *moveChannelUpButton;
    QPushButton *moveChannelDownButton;
    QSpacerItem *verticalSpacer_4;
    QListWidget *channelListView;
    QHBoxLayout *horizontalLayout;
    QPushButton *addModuleButton;
    QPushButton *removeModuleButton;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QPushButton *addChannelToModButton;
    QPushButton *removeChannelFromModChannel;
    QSpacerItem *verticalSpacer_2;
    QLabel *channelsLabel;
    QLabel *moduleChannelLabel;
    QPushButton *doneButton;

    void setupUi(QDialog *moduleDialog)
    {
        if (moduleDialog->objectName().isEmpty())
            moduleDialog->setObjectName(QStringLiteral("moduleDialog"));
        moduleDialog->resize(995, 444);
        gridLayout = new QGridLayout(moduleDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        idLabel = new QLabel(moduleDialog);
        idLabel->setObjectName(QStringLiteral("idLabel"));

        horizontalLayout_2->addWidget(idLabel);

        idLineEdit = new QLineEdit(moduleDialog);
        idLineEdit->setObjectName(QStringLiteral("idLineEdit"));
        idLineEdit->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_2->addWidget(idLineEdit);

        idApplyButton = new QPushButton(moduleDialog);
        idApplyButton->setObjectName(QStringLiteral("idApplyButton"));

        horizontalLayout_2->addWidget(idApplyButton);


        gridLayout->addLayout(horizontalLayout_2, 0, 0, 1, 1);

        moduleChannelListView = new QListWidget(moduleDialog);
        moduleChannelListView->setObjectName(QStringLiteral("moduleChannelListView"));

        gridLayout->addWidget(moduleChannelListView, 1, 4, 1, 1);

        moduleListView = new QListWidget(moduleDialog);
        moduleListView->setObjectName(QStringLiteral("moduleListView"));

        gridLayout->addWidget(moduleListView, 1, 0, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_3);

        moveChannelUpButton = new QPushButton(moduleDialog);
        moveChannelUpButton->setObjectName(QStringLiteral("moveChannelUpButton"));
        moveChannelUpButton->setMaximumSize(QSize(50, 16777215));

        verticalLayout_2->addWidget(moveChannelUpButton);

        moveChannelDownButton = new QPushButton(moduleDialog);
        moveChannelDownButton->setObjectName(QStringLiteral("moveChannelDownButton"));
        moveChannelDownButton->setMaximumSize(QSize(50, 16777215));

        verticalLayout_2->addWidget(moveChannelDownButton);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_4);


        gridLayout->addLayout(verticalLayout_2, 1, 5, 1, 1);

        channelListView = new QListWidget(moduleDialog);
        channelListView->setObjectName(QStringLiteral("channelListView"));

        gridLayout->addWidget(channelListView, 1, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        addModuleButton = new QPushButton(moduleDialog);
        addModuleButton->setObjectName(QStringLiteral("addModuleButton"));

        horizontalLayout->addWidget(addModuleButton);

        removeModuleButton = new QPushButton(moduleDialog);
        removeModuleButton->setObjectName(QStringLiteral("removeModuleButton"));

        horizontalLayout->addWidget(removeModuleButton);


        gridLayout->addLayout(horizontalLayout, 2, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        addChannelToModButton = new QPushButton(moduleDialog);
        addChannelToModButton->setObjectName(QStringLiteral("addChannelToModButton"));
        addChannelToModButton->setMaximumSize(QSize(50, 16777215));

        verticalLayout->addWidget(addChannelToModButton);

        removeChannelFromModChannel = new QPushButton(moduleDialog);
        removeChannelFromModChannel->setObjectName(QStringLiteral("removeChannelFromModChannel"));
        removeChannelFromModChannel->setMaximumSize(QSize(50, 16777215));

        verticalLayout->addWidget(removeChannelFromModChannel);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);


        gridLayout->addLayout(verticalLayout, 1, 3, 1, 1);

        channelsLabel = new QLabel(moduleDialog);
        channelsLabel->setObjectName(QStringLiteral("channelsLabel"));
        channelsLabel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(channelsLabel, 0, 1, 1, 1);

        moduleChannelLabel = new QLabel(moduleDialog);
        moduleChannelLabel->setObjectName(QStringLiteral("moduleChannelLabel"));
        moduleChannelLabel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(moduleChannelLabel, 0, 4, 1, 1);

        doneButton = new QPushButton(moduleDialog);
        doneButton->setObjectName(QStringLiteral("doneButton"));

        gridLayout->addWidget(doneButton, 2, 4, 1, 1);


        retranslateUi(moduleDialog);

        QMetaObject::connectSlotsByName(moduleDialog);
    } // setupUi

    void retranslateUi(QDialog *moduleDialog)
    {
        moduleDialog->setWindowTitle(QApplication::translate("moduleDialog", "Module Settings", 0));
        idLabel->setText(QApplication::translate("moduleDialog", "MOD_ID (0-255)", 0));
        idApplyButton->setText(QApplication::translate("moduleDialog", "Apply", 0));
        moveChannelUpButton->setText(QApplication::translate("moduleDialog", "^", 0));
        moveChannelDownButton->setText(QApplication::translate("moduleDialog", "v", 0));
        addModuleButton->setText(QApplication::translate("moduleDialog", "Add Module", 0));
        removeModuleButton->setText(QApplication::translate("moduleDialog", "Remove Module", 0));
        addChannelToModButton->setText(QApplication::translate("moduleDialog", ">", 0));
        removeChannelFromModChannel->setText(QApplication::translate("moduleDialog", "<", 0));
        channelsLabel->setText(QApplication::translate("moduleDialog", "Channels", 0));
        moduleChannelLabel->setText(QApplication::translate("moduleDialog", "Module Channels", 0));
        doneButton->setText(QApplication::translate("moduleDialog", "DONE", 0));
    } // retranslateUi

};

namespace Ui {
    class moduleDialog: public Ui_moduleDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODULEDIALOG_H
