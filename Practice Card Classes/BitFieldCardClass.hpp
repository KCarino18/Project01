#pragma once

#include <cassert>
#include <vector>
#include <iosfwd>

enum Rank {
  Ace : 2,
  Two : 4,
  Three : 6,
  Four : 8,
  Five : 10,
  Six : 12,
  Seven : 14,
  Eight : 16,
  Nine : 18,
  Ten : 20,
  Jack : 22,
  Queen : 24,
  King : 26,
};

// Represents the suits of a card.
enum Suit {
  Spades : 28,
  Clubs : 30,
  Diamonds : 32,
  Hearts : 34,
};

enum Color {
  Black : 36,
  Red : 38
};

struct caawrd
{
    int suite;
    int colore;
    int Ranke;
};

