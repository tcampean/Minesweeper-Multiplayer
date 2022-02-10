//
// Created by Tudor on 7/7/2021.
//

#ifndef E3_912_CAMPEAN_TUDOR_ALEXANDRU_OBSERVER_H
#define E3_912_CAMPEAN_TUDOR_ALEXANDRU_OBSERVER_H

#include <vector>
#include <algorithm>

class Observer
{
public:
    virtual void update() = 0;
    virtual ~Observer() {}
};

class Observable
{
private:
    std::vector<Observer*> observers;
public:
    virtual ~Observable() {}

    void addObserver(Observer *obs)
    {
        observers.push_back(obs);
    }

    void removeObserver(Observer *obs)
    {
        auto it = std::find(observers.begin(), observers.end(), obs);
        if (it != observers.end())
            observers.erase(it);
    }

    void notify()
    {
        for (auto obs: observers)
        {
            obs->update();
        }
    }
};

#endif //E3_912_CAMPEAN_TUDOR_ALEXANDRU_OBSERVER_H
