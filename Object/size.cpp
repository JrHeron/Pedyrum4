#include "size.h"

Size::Size(QObject *parent) :
    QObject(parent)
{
}

Size::Size(int id, QString name, double value){
    setId(id);
    setName(name);
    setValue(value);
}

int Size::getId(){
    return id;
}

QString Size::getName(){
    return name;
}

double Size::getValue(){
    return value;
}

void Size::setId(int id){
    this->id = id;
}

void Size::setName(QString name){
    this->name = name;
}

void Size::setValue(double value){
    this->value = value;
}
