#include "functions.h"
#include <thread>
#include <mutex>
#include <iostream>
#include <QDebug>

#define STEPSIZE 200

int prime_count = 0;

std::mutex mtx;

Functions::Functions(QObject *parent) : QObject(parent)
{

}

int Functions::inc(int n)
{
    return n+1;
}

static bool is_prime(int n)
{
    bool flag = true;
    if (n==1 || n==2)
        flag = false;
    for (int i = 2; i <= n - 1; i++) {
        if (n%i == 0) {
            flag = false;
            break;
        }
    }
    return flag;
}

static void _prime(const int begin, const int end)
{
    int count = 0;
    for (int i = begin; i <= end; i++)
    {
        if (is_prime(i))
            count++;
    }
    prime_count += count;
}

/**
 *  @brief Functions::prime
 *  求解指定范围内有多少个质数
 *  @param begin 起点
 *  @param end 终点
 */
int Functions::prime(int begin, int end)
{
    int begin_tmp;
    int end_tmp;
    int tmp;

    prime_count = 0;

    do{
        begin_tmp = begin;
        end_tmp = end;
        tmp = end_tmp + STEPSIZE;
        end_tmp = (tmp <= end ? tmp : end);
        if(begin_tmp < end_tmp)
        {
            std::thread t(_prime,begin_tmp,end_tmp);
            t.join();
            begin_tmp += STEPSIZE;
            end_tmp += STEPSIZE;
        }
    }while(begin_tmp <= end);

    return prime_count;
}
