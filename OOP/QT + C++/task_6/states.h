#ifndef STATES_H
#define STATES_H

#include <QObject>
#include <estate.h>
class States : public QObject {
Q_OBJECT
public:
    explicit States(QObject *parent = nullptr);
    ~States();
    void undo();
    bool hasStates();
    bool myHasStates();
    Estate *getActualData();
    void add(Estate *value);
    void Clear();

private:
    QList<Estate *> mass;
    Estate *actualData;

signals:
    void notifyObservers();
};

#endif // STATES_H
