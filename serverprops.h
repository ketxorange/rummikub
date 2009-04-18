#ifndef SERVERPROPS_H
#define SERVERPROPS_H

#include <QtGui/QDialog>

namespace Ui {
    class ServerProps;
}

class ServerProps : public QDialog {
    Q_OBJECT
    Q_DISABLE_COPY(ServerProps)
public:
    explicit ServerProps(QWidget *parent = 0);
    virtual ~ServerProps();
    
    int getPort();
    int getRoundTime();
    const QString getName();

protected:
    virtual void changeEvent(QEvent *e);

private:
    Ui::ServerProps *m_ui;
};

#endif // SERVERPROPS_H
