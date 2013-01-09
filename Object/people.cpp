#include "people.h"

People::People()
{
}

void People::setComplement(QString complement) {
    this->complement = complement;
}

void People::setDistrict(QString district) {
    this->district = district;
}

void People::setId(int id) {
    this->id = id;
}

void People::setName(QString name) {
    this->name = name;
}

void People::setNumber(QString number) {
    this->number = number;
}

void People::setPhone(QString phone) {
    this->phone = phone;
}

void People::setStreet(QString street) {
    this->street = street;
}

void People::setNote(QString observation){
    this->note = observation;
}

void People::setCEP(QString cep){
    this->cep = cep;
}

int People::getId(){
    return id;
}

QString People::getName(){
    return name;
}

QString People::getPhone()
{
    return phone;
}

QString People::getStreet()
{
    return street;
}

QString People::getDistrict()
{
    return district;
}

QString People::getNumber()
{
    return number;
}

QString People::getComplement()
{
    return complement;
}

QString People::getCEP(){
    return cep;
}

QString People::getNote(){
    return note;
}
