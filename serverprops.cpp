#include "serverprops.h"
#include "ui_serverprops.h"

ServerProps::ServerProps(QWidget *parent) :
    QDialog(parent),
    m_ui(new Ui::ServerProps)
{
    m_ui->setupUi(this);
}

ServerProps::~ServerProps()
{
    delete m_ui;
}

void ServerProps::changeEvent(QEvent *e)
{
    switch (e->type()) {
    case QEvent::LanguageChange:
        m_ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

const QString ServerProps::getName()
{
    return m_ui->userNameLineEdit->text();
}

int ServerProps::getPort()
{
    return m_ui->portSpinBox->value();
}

int ServerProps::getRoundTime()
{
    return m_ui->seconsForRoundSpinBox->value();
}
