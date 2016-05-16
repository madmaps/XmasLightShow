/********************************************************************************
** Form generated from reading UI file 'serialportoptions.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERIALPORTOPTIONS_H
#define UI_SERIALPORTOPTIONS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_serialPortOptions
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *serialPortNameLineEdit;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *okButton;
    QPushButton *cancleButton;

    void setupUi(QDialog *serialPortOptions)
    {
        if (serialPortOptions->objectName().isEmpty())
            serialPortOptions->setObjectName(QStringLiteral("serialPortOptions"));
        serialPortOptions->resize(283, 185);
        verticalLayout = new QVBoxLayout(serialPortOptions);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(serialPortOptions);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        serialPortNameLineEdit = new QLineEdit(serialPortOptions);
        serialPortNameLineEdit->setObjectName(QStringLiteral("serialPortNameLineEdit"));

        horizontalLayout->addWidget(serialPortNameLineEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        okButton = new QPushButton(serialPortOptions);
        okButton->setObjectName(QStringLiteral("okButton"));

        horizontalLayout_2->addWidget(okButton);

        cancleButton = new QPushButton(serialPortOptions);
        cancleButton->setObjectName(QStringLiteral("cancleButton"));

        horizontalLayout_2->addWidget(cancleButton);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(serialPortOptions);

        QMetaObject::connectSlotsByName(serialPortOptions);
    } // setupUi

    void retranslateUi(QDialog *serialPortOptions)
    {
        serialPortOptions->setWindowTitle(QApplication::translate("serialPortOptions", "Serial Port Options", 0));
        label->setText(QApplication::translate("serialPortOptions", "Serial Port Name", 0));
        okButton->setText(QApplication::translate("serialPortOptions", "OK", 0));
        cancleButton->setText(QApplication::translate("serialPortOptions", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class serialPortOptions: public Ui_serialPortOptions {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERIALPORTOPTIONS_H
