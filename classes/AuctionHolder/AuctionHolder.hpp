#ifndef AUCTIONHOLDER_H
#define AUCTIONHOLDER_H

#include "../MoneySum/MoneySum.hpp"
#include "../ItemStock/ItemStock.hpp"

class AuctionHolder {
public:
    AuctionHolder(unsigned long, unsigned long);
    ~AuctionHolder();

    void printAllItems();

    ItemStock* getItemStock();
    unsigned long getSum();
    void addSum(unsigned long);
    
private:
    MoneySum* moneySum;
    ItemStock* itemStock;
};

#endif