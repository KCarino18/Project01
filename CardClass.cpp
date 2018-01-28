// Kyle Carino Practice 1
// Email: ksc44@zips.uakron.edu
// Card Class

#include <iostream>
#pragma once

enum CardRanks
{
    Ace,Two,Three,Four,Five,Six,Seven,Eight,Nine,Ten,Jack,Queen,King,
};

enum CardSuits
{
    Hearts,Diamond,Clubs,Spades,
};

class Card
{
private:
    CardRanks rank;
    CardSuits suit;

public:
    Card(CardRanks r, CardSuits s)
        : rank(r),suit(s);


};

void trialCards()
{
    Card c(Ace,Spades);
};

int main()
{
 trialCards();
 return 0;
}
