#ifndef AUCTION_H
#define AUCTION_H

#include "../AuctionHolder/AuctionHolder.hpp"
#include "../AuctionMember/AuctionMember.hpp"

class Auction {
public:
    Auction();
    ~Auction();

    void start();
    void stop();

    void getAuctionHolder();
    void getAuctionMembers();
    void printRequiredInfoInFile();
    unsigned long findTheNewOwner(Item *);

private:
    AuctionHolder* auctionHolder;
    std::vector<AuctionMember*> auctionMembers;
};

#endif