#ifndef STATES_H
#define STATES_H

#include <QObject>
#include <estate.h>
class States : public QObject {
Q_OBJECT
public:
    explicit States(QObject *parent = nullptr);
    ~States();
    void undo(); //Извлечение последнего сотояния
    bool hasStates(); //Проверка наличия элементов в массиве состояний
    bool myHasStates(); //Моя проверка наличия элементов в массиве состояний (истина если их 2 и более)
    Estate *getActualData(); //Обращение к последнему состоянию
    void add(Estate *value); //Добавление в массив состояний
    void Clear(); //Чистка массива состояний

private:
    QList<Estate *> mass; //Массив состояний
    Estate *actualData;

signals:
    void notifyObservers(); //Инициализация сигнала паттерну "Наблюдатель"
};

#endif // STATES_H
