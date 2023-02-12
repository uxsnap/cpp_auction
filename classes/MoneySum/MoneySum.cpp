#include <iostream>
#include "MoneySum.hpp"

MoneySum::MoneySum(unsigned long newSum)
{
    sum = newSum;
}

unsigned long MoneySum::getSum()
{
    return sum;
}

void MoneySum::setSum(unsigned long newSum)
{
    sum = newSum;
}

void MoneySum::add(unsigned long toAdd)
{
    sum += toAdd;
}

bool MoneySum::subtract(unsigned long toSubtract)
{
    if (sum < toSubtract)
    {
        std::cout << "Сумма превышает остаток: невозможно отнять" << std::endl;

        return false;
    }

    sum -= toSubtract;
    return true;
}

