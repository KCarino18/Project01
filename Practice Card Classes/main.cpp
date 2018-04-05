#include <iostream>


#include <vector>

// NEVER include <iostream> in a header file.
// #include <iostream>

// Use this instead. You can declare functions involving
// iostreams here, and implement them in corresponding
// .cpp file.
#include <iosfwd>

#include <vector>

// Defines a new type (user-defined type). Sometimes called
// a kind of type constructor (ignore that).
enum Rank {
  Ace,
  Two,
  Three,
  Four,
  Five,
  Six,
  Seven,
  Eight,
  Nine,
  Ten,
  Jack,
  Queen,
  King,
};

// Represents the suits of a card.
enum Suit {
  Spades,
  Clubs,
  Diamonds,
  Hearts,
};


// A card is a Rank AND a SUIT.
//
// I want to do this:
//
//    Card c1{Ace, Spades}; // Construct from values
//    Card c2 = c1; // Copy constructor
//    c2 = c1; // Assignment operator
//    c1 == c2;
//    c1 != c2;
//
// Our representation has this layout:
//
//    ssrrrr
//
// where s is a suit bit and r is a rank bit.
class Card {
public:
  Card() = default;

  Card(Rank r, Suit s)
    : bits((unsigned)s << 4 | (unsigned)r)
  { }

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
};


// A deck is a sequence of cards. This is OK
// for now.
//
// This is called a type alias.
using Deck = std::vector<Card>;

// Sometimes, you'll see this. It's basically the
// same things.
// typedef std::vector<Card> Deck;

