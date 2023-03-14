#include <iostream>
#include <vector>
#include "classes/Auction/Auction.hpp"

int main()
{
    Auction *auction = new Auction();

    auction->start();

    delete auction;

    return 0;
}