#include "Item.hpp"

Item::Item(std::string itemName, unsigned long itemPrice)
{
    name = itemName;
    price = itemPrice;
}


std::string Item::getItemName()
{
    return name;
}

unsigned long Item::getItemPrice()
{
    return price;
}

void Item::setItemPrice(unsigned long newPrice)
{
    price = newPrice;
}

std::string Item::getItemNameInfo()
{
    return "Имя товара: " + name + "\n";
   
}

std::string Item::getItemPriceInfo()
{
    return "Цена товара: " + std::to_string(price) + "\n";
}