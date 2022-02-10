//
// Created by Tudor on 7/7/2021.
//

#include "TableModel.h"
#include <QBrush>

MineTableModel::MineTableModel(Service &serv, QObject *parent) : QAbstractTableModel{parent}, serv{serv} {

}
MineTableModel::~MineTableModel() {

}

int MineTableModel::rowCount(const QModelIndex &parent) const {
    int files = this->serv.repo.dimension;
    return files;
}

int MineTableModel::columnCount(const QModelIndex &parent) const {
    return this->serv.repo.dimension;
}

QVariant MineTableModel::data(const QModelIndex &index, int role) const {
    int row = index.row();
    int column = index.column();

    if(role == Qt::DisplayRole)
    {
        if(this->serv.repo.map[row][column] == 1)
        {
            int s = 0;
            if(this->serv.repo.map[row][column+1] == -1)
                s++;
            if(this->serv.repo.map[row+1][column+1] == -1)
                s++;
            if(this->serv.repo.map[row+1][column] == -1)
                s++;
            if(this->serv.repo.map[row-1][column] == -1)
                s++;
            if(this->serv.repo.map[row][column-1] == -1)
                s++;
            if(this->serv.repo.map[row-1][column+1] == -1)
                s++;
            if(this->serv.repo.map[row+1][column-1] == -1)
                s++;
            if(this->serv.repo.map[row-1][column-1] == -1)
                s++;
            return QString{QString::fromStdString(to_string(s))};
        }

        if(this->serv.repo.map[row][column] == 2)
            return QString{QString::fromStdString("*")};

    }
    if(role == Qt::BackgroundRole)
    {
        if(this->serv.repo.map[row][column] == -1 || this->serv.repo.map[row][column] == 0) // unrevealed
            return QBrush{QColor{50,205,50}};
        if(this->serv.repo.map[row][column] == 1) // revealed
            return QBrush{QColor{176,224,230}};
        if(this->serv.repo.map[row][column] == 2) // mined
            return QBrush{QColor{255,0,0}};

    }
    return QVariant();
}

QVariant MineTableModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if(role == Qt::DisplayRole && orientation == Qt::Horizontal){
        return section + 1;
    }
    if(role == Qt::DisplayRole && orientation == Qt::Vertical){
        char c = 'A'+section;
        return QString(c);
    }
    return QVariant();
}