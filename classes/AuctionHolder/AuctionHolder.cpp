#include <iostream>
#include "AuctionHolder.hpp"

AuctionHolder::AuctionHolder(unsigned long newMoneySum, unsigned long newItemQuantity)
{
    moneySum = new MoneySum(newMoneySum);
    itemStock = new ItemStock(newItemQuantity);
}

AuctionHolder::~AuctionHolder()
{
    delete moneySum;
    delete itemStock;
}

ItemStock* AuctionHolder::getItemStock()
{
    return itemStock;
}

unsigned long AuctionHolder::getSum()
{
    return moneySum->getSum();
}

void AuctionHolder::addSum(unsigned long sum)
{
    moneySum->add(sum);
}