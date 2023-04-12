#ifndef SORTS_H
#define SORTS_H
#include <iostream>
#include <string>


enum Suit {Clubs,Diamonds,Hearts,Spades, NUM_SUITS};
enum CardValue {Ace,_2,_3,_4,_5,_6,_7,_8,_9,_10,Jack,Queen,King, NUM_CARD_VALUES};

struct Card{
    Suit s;
    CardValue v;

    Card(Suit s,CardValue v) : s(s), v(v) 
    {};
};

std::string SuitValueString(Suit s ){
    std::string suits[] = {"Clubs", "Diamonds","Hearts","Spades"};
    return suits[s];
} 

std::string CardValueString(CardValue cv){
    switch(cv){
        case Ace:
        return "Ace";
        case Jack:
        return "Jack";
        case Queen:
        return "Queen";
        case King:
        return "King";
        default:
        return std::to_string(cv-Ace+1);
    }
}

//https://stackoverflow.com/questions/2719136/overloading-with-a-struct-no-class-cout-style
std::ostream& operator << (std::ostream& o, Card& card){
    o 
    << "[" 
    << CardValueString(card.v)
    <<","
    <<SuitValueString(card.s)
    <<"]";
    return o;
}

#endif //SORTS_H