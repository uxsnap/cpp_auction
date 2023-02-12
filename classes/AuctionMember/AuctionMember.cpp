#include "AuctionMember.hpp"

AuctionMember::AuctionMember(unsigned long memberId, unsigned long newMoneySum)
{
    memberId = memberId;
    moneySum = new MoneySum(newMoneySum);
    itemStock = new ItemStock();
}

AuctionMember::~AuctionMember()
{
    delete moneySum;
    delete itemStock;
};

unsigned long AuctionMember::getMemberId()
{
    return memberId;
}

unsigned long AuctionMember::getMemberSum()
{
    return moneySum->getSum();
}

bool AuctionMember::subtractMemberSum(unsigned long sum)
{
    return moneySum->subtract(sum);
}

void AuctionMember::addItem(Item *item)
{
    itemStock->addItem(item);
}

std::string AuctionMember::getInfo()
{
    std::string res = "Номер участника: " + std::to_string(memberId) + "\n"
        "Сумма на счету: " + std::to_string(getMemberSum()) + "\n"
        "Купленные предметы: " + "\n";

    for (Item* item: itemStock->getItems())
    {
        res += "\t" + item->getItemInfo();
    }

    return res;
}