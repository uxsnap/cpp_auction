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

void AuctionHolder::printAllItems()
{
    std::vector<Item *> items = itemStock->getItems();

    for (unsigned long i = 0; i < items.size(); i++)
    {
        std::cout << items[i]->getItemNameInfo() + "\n" + items[i]->getItemPriceInfo() << std::endl;
    }
}

void AuctionHolder::addSum(unsigned long sum)
{
    moneySum->add(sum);
}