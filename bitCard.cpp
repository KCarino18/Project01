// Kyle Carino Practice 4
// Email: ksc44@zips.uakron.edu
// Card Class

#include <iostream>
#pragma once



class Card {
public:

  Card() = default;

  Card Rank r, Suit s
    : bits((unsigned)s << 4 | (unsigned)r);

  Rank get_rank() const {
    return (Rank)(0b001111 & bits); // 0xf & bits
  }

  Suit get_suit() const {
    return (Suit)((0b110000 & bits) >> 4);
  }

  // We can somewhat optimize the performance of the
  // == operator by comparing integer values.
  bool operator==(Card c) const {
    return bits == c.bits;
  }

  bool operator!=(Card c) const {
    return bits != c.bits;
  }

private:

unsigned char bits;
enum CardRanks
{
    Ace,Two,Three,Four,Five,Six,Seven,Eight,Nine,Ten,Jack,Queen,King,
};

enum CardSuits
{
    Hearts,Diamond,Clubs,Spades,
}
}


// A deck is a sequence of cards. This is OK
// for now.
//
// This is called a type alias.
using Deck = std::vector<Card>;


int main()
{
 return 0;
}

