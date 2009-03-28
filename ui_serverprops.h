/********************************************************************************
** Form generated from reading ui file 'serverprops.ui'
**
** Created: Sat 28. Mar 18:48:08 2009
**      by: Qt User Interface Compiler version 4.5.0
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_SERVERPROPS_H
#define UI_SERVERPROPS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QFormLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QSpinBox>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ServerProps
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *userNameLabel;
    QLineEdit *userNameLineEdit;
    QLabel *portLabel;
    QSpinBox *portSpinBox;
    QLabel *seconsForRoundLabel;
    QSpinBox *seconsForRoundSpinBox;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *ServerProps)
    {
        if (ServerProps->objectName().isEmpty())
            ServerProps->setObjectName(QString::fromUtf8("ServerProps"));
        ServerProps->resize(250, 123);
        verticalLayout = new QVBoxLayout(ServerProps);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        userNameLabel = new QLabel(ServerProps);
        userNameLabel->setObjectName(QString::fromUtf8("userNameLabel"));

        formLayout->setWidget(0, QFormLayout::LabelRole, userNameLabel);

        userNameLineEdit = new QLineEdit(ServerProps);
        userNameLineEdit->setObjectName(QString::fromUtf8("userNameLineEdit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, userNameLineEdit);

        portLabel = new QLabel(ServerProps);
        portLabel->setObjectName(QString::fromUtf8("portLabel"));

        formLayout->setWidget(1, QFormLayout::LabelRole, portLabel);

        portSpinBox = new QSpinBox(ServerProps);
        portSpinBox->setObjectName(QString::fromUtf8("portSpinBox"));
        portSpinBox->setMinimum(1);
        portSpinBox->setMaximum(65536);
        portSpinBox->setValue(7890);

        formLayout->setWidget(1, QFormLayout::FieldRole, portSpinBox);

        seconsForRoundLabel = new QLabel(ServerProps);
        seconsForRoundLabel->setObjectName(QString::fromUtf8("seconsForRoundLabel"));

        formLayout->setWidget(2, QFormLayout::LabelRole, seconsForRoundLabel);

        seconsForRoundSpinBox = new QSpinBox(ServerProps);
        seconsForRoundSpinBox->setObjectName(QString::fromUtf8("seconsForRoundSpinBox"));
        seconsForRoundSpinBox->setMinimum(1);
        seconsForRoundSpinBox->setMaximum(9999);
        seconsForRoundSpinBox->setValue(30);

        formLayout->setWidget(2, QFormLayout::FieldRole, seconsForRoundSpinBox);


        verticalLayout->addLayout(formLayout);

        buttonBox = new QDialogButtonBox(ServerProps);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);

#ifndef QT_NO_SHORTCUT
        userNameLabel->setBuddy(userNameLineEdit);
        portLabel->setBuddy(portSpinBox);
        seconsForRoundLabel->setBuddy(seconsForRoundSpinBox);
#endif // QT_NO_SHORTCUT

        retranslateUi(ServerProps);
        QObject::connect(buttonBox, SIGNAL(accepted()), ServerProps, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ServerProps, SLOT(reject()));

        QMetaObject::connectSlotsByName(ServerProps);
    } // setupUi

    void retranslateUi(QDialog *ServerProps)
    {
        ServerProps->setWindowTitle(QApplication::translate("ServerProps", "Dialog", 0, QApplication::UnicodeUTF8));
        userNameLabel->setText(QApplication::translate("ServerProps", "User Name:", 0, QApplication::UnicodeUTF8));
        userNameLineEdit->setText(QApplication::translate("ServerProps", "Albatros", 0, QApplication::UnicodeUTF8));
        portLabel->setText(QApplication::translate("ServerProps", "Port:", 0, QApplication::UnicodeUTF8));
        seconsForRoundLabel->setText(QApplication::translate("ServerProps", "Secons For Round:", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(ServerProps);
    } // retranslateUi

};

namespace Ui {
    class ServerProps: public Ui_ServerProps {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVERPROPS_H
