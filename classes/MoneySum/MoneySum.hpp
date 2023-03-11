#ifndef MONEYSUM_H
#define MONEYSUM_H

class MoneySum 
{
public:
    MoneySum(unsigned long);

    unsigned long getSum();
    void add(unsigned long);
    bool subtract(unsigned long);

private:
    unsigned long sum;
};

#endif