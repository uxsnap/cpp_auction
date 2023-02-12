#include <iostream>
#include <fstream>
#include "Auction.hpp"

Auction::Auction() {}

Auction::~Auction()
{
    delete auctionHolder;
    auctionMembers.clear();
}


void Auction::getAuctionHolder()
{
    uint auctionHolderSum;
    uint auctionHolderItemQuantity;

    std::cout << "Введите сумму счета аукциониста и кол-во предметов: ";
    std::cin >> auctionHolderSum >> auctionHolderItemQuantity;

    assert(auctionHolderSum > 0);
    assert(auctionHolderItemQuantity > 0);

    auctionHolder = new AuctionHolder(auctionHolderSum, auctionHolderItemQuantity);
}

void Auction::getAuctionMembers()
{
    uint auctionMembersQuantity;

    std::cout << "Введите количество участников аукциона: ";
    std::cin >> auctionMembersQuantity;

    assert(auctionMembersQuantity > 0);

    unsigned long currentSum;

    for (uint i = 0; i < auctionMembersQuantity; i++)
    {

        std::cout << "Введите сумму участника номер " + std::to_string(i) + ": ";
        std::cin >> currentSum;

        assert(currentSum > 0);

        auctionMembers.push_back(new AuctionMember(i, currentSum));
    }
}


unsigned long Auction::findTheNewOwner(Item *curItem)
{
    unsigned long max = curItem->getItemPrice();
    AuctionMember* neededAuctionMember;

    unsigned long curSum;

    std::cout << "Стартовая цена товара: " + std::to_string(max);

    for (AuctionMember* am : auctionMembers)
    {
        if (am->getMemberSum() < max) continue;

        do {
            std::cout << "Ставка участника " + std::to_string(am->getMemberId()) + ": ";
            std::cin >> curSum;
        } while (curSum > 0);

        if (curSum > max)
        {
            neededAuctionMember = am;
            max = curSum;
        }
    }

     std::cout << "Победителем стал участник " + std::to_string(neededAuctionMember->getMemberId());

    neededAuctionMember->addItem(curItem);
    neededAuctionMember->subtractMemberSum(max);
    
    return max;
}

void Auction::start()
{
    getAuctionHolder();
    getAuctionMembers();
    
    ItemStock* itemStock = auctionHolder->getItemStock();
    std::vector<Item*> &items = itemStock->getItems();

    while (items.size() != 0)
    {
        Item* curItem = items.back();

        unsigned long revenue = findTheNewOwner(curItem);

        auctionHolder->addSum(revenue);

        items.pop_back();
    }

    printRequiredInfoInFile();
}


void Auction::printRequiredInfoInFile()
{   
    for (AuctionMember* am : auctionMembers)
    {
        std::cout << am->getInfo();
    }
}