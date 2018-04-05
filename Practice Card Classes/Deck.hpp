//DECK THAT IS SHUFFLED.
#pragma once

#include <cassert>
#include <vector>
#include <iosfwd>

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

enum Suit {
  Spades,
  Clubs,
  Diamonds,
  Hearts,
};

enum Color {
  Black, Red
};


class StandardCard {
public:
  StandardCard() = default;

  StandardCard(Rank r, Suit s)
    : rank(r), suit(s)
  { }

  Rank get_rank() const {
    return rank;
  }

  Suit get_suit() const {
    return suit;
  }

private:
  Rank rank;
  Suit suit;
};


class JokerCard
{
public:
  JokerCard(Color c)
    : color(c)
  { }

  Color get_color() const {
    return color;
  }

private:
  Color color;
};


class Card
{
public:
  enum Kind {
    Standard,
    Joker
  };

private:
  union Value {
    Value(StandardCard c) : sc(c) { }
    Value(JokerCard c) : jc(c) { }

    StandardCard sc;
    JokerCard jc;
  };

public:
  Card(StandardCard c)
    : kind(Standard), val(c)
  { }
  Card(JokerCard c)
    : kind(Joker), val(c)
  { }

  Kind get_kind() const { return kind; }
  bool is_standard() const { return kind == Standard; }
  bool is_joker() const { return kind == Joker; }

  StandardCard get_standard_card() const {

    assert(is_standard());
    return val.sc;
  }

  JokerCard get_joker_card() const {
    assert(is_joker());
    return val.jc;
  }


  Suit get_suit() const {
    return get_standard_card().get_suit();
  }

  Rank get_rank() const {
    return get_standard_card().get_rank();
  }

  Color get_color() const {
    return get_joker_card().get_color();
  }

private:
  Kind kind;
  Value val;
};
//CREATES DECK OF CARDS And shuffles.
Card createDeck
{
    srand(time(0));
    std::vector<Card> deck;
    int sueit,ranke,colore;
    int suitr,rankr,colorr;

    Card *f1;

    for (int n=0; n<=52; n++)
    {

        bool dupe = 0
        while(dupe == 0)
        {
            bool doublec;
            sueit = (rand() % 4)+1;
            ranke = (rand() % 13)+1;
            colore = (rand() % 2)+1;

            f1 = new Card;
            suitr = Suit[sueit]
            f1.setSuit = suitr;
            rankr = Rank[ranke];
            f1.setrank = rankr;
            colorr = color[colore];


            sort(Deck.begin(), Deck.end());
            Deck.erase(unique(Deck.begin(),Deck.end()), Deck.end());
            Deck.push_back(*f1);

        }
    }
    random_shuffle(Deck.begin(),Deck.end());
    return Deck;
}
Card PrintDeck (vector<Card> x )
