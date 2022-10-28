#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <QObject>
#include <vector>
#include <thread>

class Thread;
class Functions : public QObject
{
    Q_OBJECT
public:
    explicit Functions(QObject *parent = nullptr);
public:

    int inc(int n);
    int prime(int begin,int end);
public:

};

#endif // FUNCTIONS_H
