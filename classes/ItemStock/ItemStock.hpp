#ifndef ITEMSTOCK_H
#define ITEMSTOCK_H

#include <vector>
#include "../Item/Item.hpp"

class ItemStock 
{
public:
    ItemStock();
    ItemStock(unsigned long);
    ~ItemStock();

    std::vector<Item *>& getItems();
    void addItem(Item* item);

private:
    std::vector<Item *> items;

    void generateItems(unsigned long);
};

#endif