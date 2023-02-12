#include "ItemStock.hpp"

unsigned long generateRandomNumber()
{
    return rand() % 50000;
}

std::string generateRandomString()
{
    static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
    std::string result;

    int len = generateRandomNumber() % 20;
    result.reserve(len == 0 ? 1 : len);

    for (int i = 0; i < len; ++i) {
        result += alphanum[rand() % (sizeof(alphanum) - 1)];
    }
    
    return result;
}

ItemStock::ItemStock() {}

ItemStock::ItemStock(unsigned long quantity)
{
    quantity = quantity;

    generateItems(quantity);
}

ItemStock::~ItemStock()
{
    items.clear();
}

void ItemStock::generateItems(unsigned long quantity)
{
    srand((unsigned) time(NULL));

    for (int i = 0; i < quantity; i++)
        items.push_back(new Item(
            generateRandomString(),
            generateRandomNumber()
        ));
}

std::vector<Item *> &ItemStock::getItems()
{
    return items;
}

void ItemStock::addItem(Item* item)
{
    items.push_back(item);
}