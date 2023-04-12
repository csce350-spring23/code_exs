#include "sorts.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <random>
#include <algorithm>

void printCards(std::vector<Card> cards){
    using namespace std;
    cout<<"{"<<"\n";
    for(Card card:cards){
        cout<<'\t'<<card<<"\n";
    }
    cout<<"}"<<endl;
}

int main(){
    using namespace std;
    
    const int num_cards = 20;
    vector<Card> cards;
    for(int i=0; i< num_cards; ++i){
        Card c();
        cards.push_back(Card(
            static_cast<Suit>(rand() % NUM_SUITS),
            static_cast<CardValue>(rand() % NUM_CARD_VALUES))
        );
    }

    //https://stackoverflow.com/questions/6926433/how-to-shuffle-a-stdvector
    // vector<Card> shuffled = cards;
    // auto rng = default_random_engine {};
    // shuffle(begin(shuffled),end(shuffled),rng);

    // cout<<"original"<<endl;
    // printCards(cards);
    // cout<<"\n"<<"shuffled"<<endl;
    // printCards(shuffled);

    vector<Card> sorted_suit = cards;
    sort(sorted_suit.begin(),sorted_suit.end(), 
        [](Card& a, Card& b){
            return a.s<b.s;
        }
    );

    vector<Card> sorted_val = cards;
    sort(sorted_val.begin(),sorted_val.end(), 
        [](Card& a, Card& b){
            return a.v<b.v;
        }
    );

    vector<Card> sorted_suit_val = sorted_suit;
    sort(sorted_suit_val.begin(),sorted_suit_val.end(), 
        [](Card& a, Card& b){
            return a.v<b.v;
        }
    );

    vector<Card> stable_sorted_suit_val = sorted_suit;
    stable_sort(stable_sorted_suit_val.begin(),
                stable_sorted_suit_val.end(), 
        [](Card a, Card b){
            return a.v<b.v;
        }
    );

    cout<<"original"<<endl;
    printCards(cards);
    cout<<"sorted_suit"<<endl;
    printCards(sorted_suit);
    cout<<"sorted_val"<<endl;
    printCards(sorted_val);
    cout<<"sorted_suit_val"<<endl;
    printCards(sorted_suit_val);
    cout<<"stable_sorted_suit_val"<<endl;
    printCards(stable_sorted_suit_val);




    

    return 0;
}