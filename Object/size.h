#ifndef SIZE_H
#define SIZE_H

#include <QObject>

class Size : public QObject
{
    Q_OBJECT
public:
    explicit Size(QObject *parent = 0);
    explicit Size(int id, QString name, double value);

public:
    int getId();
    QString getName();
    double getValue();

    void setId(int id);
    void setName(QString name);
    void setValue(double value);

protected:
    int id;
    QString name;
    double value;

signals:

public slots:

};

#endif // SIZE_H
