#ifndef FISTADMIN_H
#define FISTADMIN_H

#include <QWidget>
#include <QLabel>
#include <Component/edit.h>
#include <QPushButton>
#include <QToolButton>
#include <Abstract/bdtools.h>
#include <Abstract/encryption.h>

class FirstAdminInterface : public QWidget
{
    Q_OBJECT
public:
    explicit FirstAdminInterface(QWidget *parent = 0);

    void createComponent();

    void resizeEvent(QResizeEvent *);

    void connections();

signals:
     void gotoNext(int index);

public slots:

    void input();

    void adjustLayout();

    void textChanged_ePassword();

    void textChanged_ePasswordConfirm();

    void onClick_pbCreate();

    void onClick_pbLeave();

public:

    QLabel *lText;

    QWidget *wGroup;
    QLabel *lBackground;

    Edit *eUsername;
    Edit *ePassword;
    Edit *ePasswordConfirm;

    Edit *eSecretAsk;
    Edit *eAnswer;

    QPushButton *pbCreate; // testar a conexão
    QPushButton *pbLeave; // conectar

    BDTools bd;

    Encryption e;

};

#endif // FISTADMIN_H
