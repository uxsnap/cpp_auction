#include <iostream>
#include <fstream>
#include <sstream>
#include <cassert>
#include "Auction.hpp"

Auction::Auction() {}

Auction::~Auction()
{
    delete auctionHolder;
    auctionMembers.clear();
}

void Auction::getAuctionHolder()
{
    long int auctionHolderSum;
    long int auctionHolderItemQuantity;

    std::cout << "Введите сумму счета аукциониста и кол-во предметов: ";
    std::cin >> auctionHolderSum >> auctionHolderItemQuantity;

    assert(auctionHolderSum > 0);
    assert(auctionHolderItemQuantity > 0);

    auctionHolder = new AuctionHolder(auctionHolderSum, auctionHolderItemQuantity);
}

void Auction::getAuctionMembers()
{
    long int auctionMembersQuantity;

    std::cout << "Введите количество участников аукциона: ";
    std::cin >> auctionMembersQuantity;

    assert(auctionMembersQuantity > 0);

    long int currentSum;

    for (unsigned int i = 0; i < auctionMembersQuantity; i++)
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
    AuctionMember *neededAuctionMember = nullptr;

    long int curSum;

    std::cout << "Стартовая цена товара " + curItem->getItemName() + ": " + std::to_string(max) << std::endl;

    for (AuctionMember *am : auctionMembers)
    {
        if (am->getMemberSum() < max)
            continue;

        do
        {
            std::cout << "Ставка участника " + std::to_string(am->getMemberId()) + ": ";
            std::cin >> curSum;
        } while (curSum <= 0);

        if (curSum > max && am->getMemberSum() >= curSum)
        {
            neededAuctionMember = am;
            max = curSum;
        }
    }

    if (neededAuctionMember == nullptr)
    {
        std::cout << "Никто не приобрел предмет!" << std::endl;
        std::cout << "=======================" << std::endl;

        return 0;
    }
    else
    {
        std::cout << "Победителем стал участник " + std::to_string(neededAuctionMember->getMemberId()) << std::endl;
        std::cout << "=======================" << std::endl;

        curItem->setItemPrice(max);

        neededAuctionMember->addItem(curItem);
        neededAuctionMember->subtractMemberSum(max);

        return max;
    }
}

void Auction::start()
{
    getAuctionHolder();
    std::cout << "=======================" << std::endl;
    getAuctionMembers();
    std::cout << "=======================" << std::endl;

    ItemStock *itemStock = auctionHolder->getItemStock();
    std::vector<Item *> &items = itemStock->getItems();
    std::vector<Item *>::iterator curItem;

    for (curItem = items.begin(); curItem != items.end(); curItem++)
    {
        unsigned long revenue = findTheNewOwner((*curItem));

        auctionHolder->addSum(revenue);
    }

    std::cout << "=======================" << std::endl;

    printRequiredInfoInFile();
}

void Auction::printRequiredInfoInFile()
{
    std::ofstream file;
    file.open("result.txt");

    file << "Счет аукциониста: " + std::to_string(auctionHolder->getSum()) << std::endl;
    file << "=======================" << std::endl;

    for (AuctionMember *am : auctionMembers)
    {
        file << am->getInfo();
        file << "=======================" << std::endl;
    }

    file.close();
}