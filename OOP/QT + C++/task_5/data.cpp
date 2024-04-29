#include "data.h"

Data::Data(QObject *parent)
    : QObject{parent}
{

}

int Data::Summ() //Сумма элементов
{
    int summ = 0;
    for (int i = 0; i < count; i++) {
        summ += mass[i];
    }
    return summ;
}

int Data::SummEven() //Сумма четных элементов
{
    int summ = 0;
    for (int i = 0; i < count; i++) {
        if (mass[i] % 2 == 0) {
            summ += mass[i];
        }
    }
    return summ;
}

void Data::Task_1() //Задание 1
{
    QList<int> mass_other;
    int count_zeroes = 0;
    for (int i = 0; i < count; i ++) {
        if (mass[i] == 0) {
            count_zeroes ++;
        }
        else {
            mass_other.append(mass[i]);
        }
    }
    mass.clear();
    for (int i = 0; i < count_zeroes; i ++){
        mass.append(0);
    }
    for (int i = 0; i < count - count_zeroes; i ++){
        mass.append(mass_other[i]);
    }
}

QList<int> Data::Check_task() //Поиск четных индексов для задания 2
{
    int c = 0;
    QList <int> index;
    for (int i = 0; i < count; i ++){
        if (mass[i] % 2 == 0){
            if (c == 0){
                c ++;
            }
            index.push_back(i);
        }
    }
    return index;
}

int Data::Task_2() //Задание 2
{
    QList <int> index = Check_task();
    int summ = 0;
    if (index.size() > 1){
        for (int i = index[0] + 1; i < index[index.size()-1]; i ++) {
            summ += mass[i];
        }
    }
    return summ;
}
