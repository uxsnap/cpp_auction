#ifndef ITEM_H
#define ITEM_H

#include <string>

class Item
{
public:
    Item(std::string, unsigned long);

    unsigned long getItemPrice();
    std::string getItemInfo();

private:
    std::string name;
    unsigned long price;
};

#endif