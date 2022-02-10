//
// Created by Tudor on 7/7/2021.
//

#ifndef E3_912_CAMPEAN_TUDOR_ALEXANDRU_GUI_H
#define E3_912_CAMPEAN_TUDOR_ALEXANDRU_GUI_H
#include <qwidget.h>
#include <QListWidget>
#include <QFormLayout>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QLabel>
#include <QMainWindow>
#include <QWidget>
#include <Service.h>
#include <QRadioButton>
#include <QButtonGroup>
#include <QTableView>
#include <QSortFilterProxyModel>
#include <QHeaderView>
#include <QSlider>
#include <QTableWidgetItem>
#include "TableModel.h"

class PlayerWindow: public QWidget, public Observer {
Q_OBJECT
public:
    Service &serv;
    Player p;
    string status = "playing";
    int count;
public:
    PlayerWindow(Service &serv, Player p,int count, QWidget *parent = Q_NULLPTR);

    ~PlayerWindow();

    void update() override;

    void markMine();

    void reveal();

    void connect();

    QLabel* coord;
    QTableView* fileTable;
    QPushButton* Mark;
    QPushButton* Reveal;
    QLineEdit* coordinates;
    MineTableModel* fileModel;

};

#endif //E3_912_CAMPEAN_TUDOR_ALEXANDRU_GUI_H
