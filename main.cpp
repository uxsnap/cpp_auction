#include <iostream>
#include <vector>
#include "classes/AuctionHolder/AuctionHolder.hpp"
#include "classes/AuctionMember/AuctionMember.hpp"
#include "classes/Auction/Auction.hpp"

int main() {
    Auction* auction = new Auction();

    auction->start();

    delete auction;

    return 0;
}