#ifndef AUCTIONMEMBER_H
#define AUCTIONMEMBER_H

#include "../MoneySum/MoneySum.hpp"
#include "../ItemStock/ItemStock.hpp"

class AuctionMember {
public:
    AuctionMember(unsigned long memberId, unsigned long moneySum);
    ~AuctionMember();

    unsigned long getMemberId();
    unsigned long getMemberSum();
    bool subtractMemberSum(unsigned long);
    void addItem(Item*);
    std::string getInfo();
private:
    unsigned long memberId;
    MoneySum * moneySum;
    ItemStock * itemStock;
};

#endif