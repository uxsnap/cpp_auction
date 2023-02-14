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

std::string Item::getItemNameInfo()
{
    return "Имя товара: " + name + "\n";
   
}

std::string Item::getItemPriceInfo()
{
    return "Цена товара: " + std::to_string(price) + "\n";
}