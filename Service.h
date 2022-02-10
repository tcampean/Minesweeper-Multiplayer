//
// Created by Tudor on 7/7/2021.
//

#ifndef E3_912_CAMPEAN_TUDOR_ALEXANDRU_SERVICE_H
#define E3_912_CAMPEAN_TUDOR_ALEXANDRU_SERVICE_H

#include <Repository.h>
#include "Observer.h"

class Service: public Observable
{
public:
    Repository repo;
    int cont = 0;
public:
    void addPlayer(Player p)
    {
        this->repo.addPlayer(p);
    }

};

#endif //E3_912_CAMPEAN_TUDOR_ALEXANDRU_SERVICE_H
