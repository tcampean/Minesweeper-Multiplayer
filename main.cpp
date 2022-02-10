//
// Created by Tudor on 7/7/2021.
//

#include <iostream>
#include "Service.h"
#include <QApplication>
#include "GUI.h"

int main(int argc,char *argv[]) {

    QApplication a(argc, argv);
    Service serv;
    vector<PlayerWindow*> vec;
    int count = 0;
    for(auto i: serv.repo.players)
    {
        PlayerWindow *p = new PlayerWindow{serv,i,count};
        vec.push_back(p);
        p->show();
        count++;
    }
    int players = serv.repo.players.size();
    /*while(players > 0)
    {
        for(int i =0 ;i<vec.size();i++) {
            if (vec[i]->status == "playing") {
                vec[i]->status == "play";
                while (vec[i]->status == "play") {
                    if (vec[i]->status == "playing")
                        break;
                }
                vec[i]->status == "playing";
            }
        }


    }
     */

    return a.exec();

}