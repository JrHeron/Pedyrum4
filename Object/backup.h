#ifndef BACKUP_H
#define BACKUP_H

#include <QObject>
#include <Abstract/bdtools.h>
#include <Abstract/encryption.h>
#include <Abstract/tools.h>
#include <process.h>

class Backup : public QObject
{
    Q_OBJECT
public:
    explicit Backup(QObject *parent = 0);

    void start();

    void createBackup(QString fileName);

    static void threadBackup(void *fileName);

    void restoreBackup(QString fileName);

public:
    BDTools bd;

    Encryption e;

    Tools tools;

signals:
    void totalRecordsBackup(int);
    void currentPositionBackup(int);
    void finishedBackup();

    void totalRecordsRestore(int);
    void currentPositionRestore(int);
    void finishedRestore();

public slots:

};

#endif // BACKUP_H
