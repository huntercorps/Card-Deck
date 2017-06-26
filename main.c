#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef struct {
    char *face;
    char *suit;
} Card;

typedef struct {
    Card cards[52];
    int is_shuffled;
} Deck;


void shuffle(Deck *deck){
   int random_number;
    Card temp;

        srand((unsigned int)time(NULL));
        for (int i = 0; i < 52; i++) {
            //get random number between 0 and 51
            random_number = rand() % 52;
            //perform swap
            temp = deck->cards[i];
            deck->cards[i] = deck->cards[random_number];
            deck->cards[random_number] = temp;
        }
    deck->is_shuffled = 1;
}

void print_deck(Deck *deck){
    for (int i = 0; i < 52; i++) {
        printf("%s of %s\n", deck->cards[i].face, deck->cards[i].suit);
    }
}

int main(){
    Deck deck;
    char *suits[4] = {"Hearts", "Diamonds", "Clubs", "Spades"};
    char *faces[13] = {"2", "3","4", "5", "6", "7",
                       "8", "9", "10", "Jack", "Queen", "King","Ace"};

    deck.is_shuffled = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 13; j++) {
            deck.cards[i * 13 + j].face = faces[j];
            deck.cards[i * 13 + j].suit = suits[i];
        }
    }
    print_deck(&deck);
    shuffle(&deck);
    printf("\n----Deck has been shuffled---- \n\n");
    print_deck(&deck);
    return 0;
}
