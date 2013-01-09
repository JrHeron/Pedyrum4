#ifndef LOGININTERFACE_H
#define LOGININTERFACE_H

#include <QWidget>
#include <QLabel>
#include <Component/edit.h>
#include <Abstract/tools.h>
#include <QToolButton>
#include <QCheckBox>
#include <QPushButton>
#include <QAction>
#include <Object/login.h>
#include <QKeyEvent>
#include <QMessageBox>
#include <Abstract/encryption.h>

class LoginInterface : public QWidget
{
    Q_OBJECT
public:
    explicit LoginInterface(QWidget *parent = 0);

    void createComponent();

    void resizeEvent(QResizeEvent *);

    void connections();

signals:    
    void openSystem(QString name, QString id, QList<bool> permissions);

    void fullScreen();

public slots:

    void keyPressEvent(QKeyEvent *event);

    void input();

    void adjustLayout();

    void onClick_pbLogin();

    void onTextChanged_ePassword();

    void onTriggered_aShowPassword();

    void logado(QString username, QString id, QList<bool> permissions);

public:

    QWidget *wLogin;
    QLabel *lLogin;

    QLabel *lLoginText;
    Edit *eUsername;
    Edit *ePassword;
    QToolButton *tbViewPassword;
    QAction *aShowPassword;
    QCheckBox *cbShowAskSecret;
    QLabel *lTextTitle;
    QLabel *lTextAsk;
    Edit *eAnswer;
    QPushButton *pbLogin;
    Login *login;  

    Tools tools;
};

#endif // LOGININTERFACE_H
