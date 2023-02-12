#include "Item.hpp"

Item::Item(std::string itemName, unsigned long itemPrice)
{
    name = itemName;
    price = itemPrice;
}

unsigned long Item::getItemPrice()
{
    return price;
}

std::string Item::getItemInfo()
{
    return 
        "Имя товара: " + name + "\n" +
        "Цена товара: " + std::to_string(price) + "\n";
}