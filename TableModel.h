//
// Created by Tudor on 7/7/2021.
//

#ifndef E3_912_CAMPEAN_TUDOR_ALEXANDRU_TABLEMODEL_H
#define E3_912_CAMPEAN_TUDOR_ALEXANDRU_TABLEMODEL_H
#include <QAbstractTableModel>
#include <Service.h>

class MineTableModel : public QAbstractTableModel
{
    public:
        Service& serv;
    public:
        MineTableModel(Service &service, QObject* parent = NULL);
        ~MineTableModel();
        int rowCount(const QModelIndex &parent = QModelIndex{}) const override;
        int columnCount(const QModelIndex& parent = QModelIndex{}) const override;
        QVariant data(const QModelIndex &index,int role = Qt::DisplayRole) const override;
        QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

};

#endif //E3_912_CAMPEAN_TUDOR_ALEXANDRU_TABLEMODEL_H
