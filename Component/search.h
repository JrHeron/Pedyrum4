#ifndef SEARCH_H
#define SEARCH_H

#include <QWidget>
#include <Component/edit.h>
#include <QToolButton>
#include <QCompleter>
#include <QResizeEvent>

const char URL_MENU[25] = ":/Extras/search";

class Search : public QWidget
{
    Q_OBJECT
public:
    explicit Search(QWidget *parent = 0, QString text = "", bool single = false);

    void createCompleter();
    void input();
    void connections();
    void layout();

    void setColumn(int column);
    void setCompleter(QCompleter *autoCompleter);
    void setAction(QAction *action);

    void resizeEvent(QResizeEvent *);

    int column();
    
signals:
    void textSearch(QString text);
    
public slots:

    void textChanged(QString text);

public:
    Edit *eSearch;
    QToolButton *tbMenu;
    QCompleter *completer;
    QString textStandard;
    bool isSingle;
};

#endif // SEARCH_H
