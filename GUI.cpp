//
// Created by Tudor on 7/7/2021.
//

#include "GUI.h"
#include <QMessageBox>
#include <iostream>

PlayerWindow::PlayerWindow(Service &serv, Player p,int count, QWidget *parent) :QWidget(parent), serv{serv} {

    QVBoxLayout * layout = new QVBoxLayout{this};
    this->p = p;
    this->count = count;
    QWidget * lowerSide = new QWidget{};
    this->setWindowTitle(QString::fromStdString(p.getName()));
    QHBoxLayout * lowerLayout = new QHBoxLayout{lowerSide};
    this->fileModel = new MineTableModel{this->serv};
    this->fileTable = new QTableView{};
    this->fileTable->setModel(this->fileModel);
    layout->addWidget(this->fileTable);
    this->coord = new QLabel{"Coordinates"};
    this->coordinates = new QLineEdit{};
    this->coord->setBuddy(this->coordinates);
    lowerLayout->addWidget(this->coord);
    lowerLayout->addWidget(this->coordinates);
    this->Mark = new QPushButton{"Mark"};
    this->Reveal = new QPushButton{"Reveal"};
    lowerLayout->addWidget(this->Mark);
    lowerLayout->addWidget(this->Reveal);
    layout->addWidget(lowerSide);
    this->serv.addObserver(this);
    this->connect();

}

PlayerWindow::~PlayerWindow()
{
    this->serv.removeObserver(this);
}


void PlayerWindow::update() {

    this->fileModel = new MineTableModel{this->serv};
    this->fileTable->setModel(this->fileModel);

}

void PlayerWindow::connect() {
    QObject::connect(this->Mark,&QPushButton::clicked,this,&PlayerWindow::markMine);
    QObject::connect(this->Reveal,&QPushButton::clicked,this,&PlayerWindow::reveal);
}

void PlayerWindow::markMine() {
    if(this->count != this->serv.cont) {
        QMessageBox::critical(0, "Error", "It's not your turn yet!");
        return;
    }


    QString text = this->coordinates->text();
    string textStr = text.toStdString();

    int index = textStr[0] - 'A';
    string number;
    for(int i =0; i<textStr.size();i++)
        if(textStr[i] <= '9' && textStr[i]>= '0')
            number += textStr[i];
    int y = stoi(number);
    y--;
    if(index < 0 || index > this->serv.repo.dimension || y < 0 || y > this->serv.repo.dimension) {
        QMessageBox::critical(0, "Error", "Out of range selection!");
        return;
    }
    if(this->serv.repo.map[index][y] != -1) {
        QMessageBox::critical(0, "Error", "You can't mark that!");
    }
    else {
        this->serv.repo.nrBombs --;
        this->serv.repo.map[index][y] = 2;
        if(this->serv.repo.nrBombs == 0)
            QMessageBox::critical(0, "Winner!", "You WON!");
    }
    this->serv.notify();
    this->serv.cont++;


}

void PlayerWindow::reveal() {

    if(this->count != this->serv.cont) {
        QMessageBox::critical(0, "Error", "It's not your turn yet!");
        return;
    }
    QString text = this->coordinates->text();
    string textStr = text.toStdString();

    int index = textStr[0] - 'A';
    string number;
    for(int i =0; i<textStr.size();i++)
        if(textStr[i] <= '9' && textStr[i]>= '0')
            number += textStr[i];
    int y = stoi(number);
    y--;
    if(index < 0 || index > this->serv.repo.dimension || y < 0 || y > this->serv.repo.dimension) {
        QMessageBox::critical(0, "Error", "Out of range selection!");
        this->serv.cont++;
        return;
    }
    if(this->serv.repo.map[index][y] == 1 || this->serv.repo.map[index][y] == 2 ) {
        QMessageBox::critical(0, "Error", "You can't do that!");
        this->serv.cont++;
        return;
    }
    if(this->serv.repo.map[index][y] == -1) {
        this->status = "out";
        QMessageBox::critical(0, "Error", "You lost!");
        _sleep(5);
        this->serv.cont++;
        this->hide();
        this->serv.repo.map[index][y] = 2;
        return;
    }

    this->serv.repo.map[index][y] = 1;
    this->serv.notify();
}