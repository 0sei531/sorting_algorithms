#include "deck.h"
#include <stdlib.h>

#define NUM_CARDS 52

void sort_deck(deck_node_t **deck);
void from_array(deck_node_t **head, deck_node_t **array);
int get_val(const card_t *card);
void to_array(deck_node_t *deck, deck_node_t **D);

void sort_deck(deck_node_t **deck)
{
    deck_node_t *D[NUM_CARDS];

    to_array(*deck, D);
    from_array(deck, D);
}

void from_array(deck_node_t **head, deck_node_t **array)
{
    int i;
    for (i = 0; i < NUM_CARDS; i++)
    {
        if (i == 0)
        {
            *head = array[i];
            array[i]->prev = NULL;
            array[i]->next = array[i + 1];
        }
        else if (i < NUM_CARDS - 1)
        {
            array[i]->next = array[i + 1];
            array[i]->prev = array[i - 1];
        }
        else
        {
            array[i]->prev = array[i - 1];
            array[i]->next = NULL;
        }
    }
}

int get_val(const card_t *card)
{
    char vals[13] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', '1', 'J', 'Q', 'K'};
    size_t i;
    for (i = 0; i < 13; ++i)
    {
        if (vals[i] == card->value[0])
        {
            return i + card->kind * 13;
        }
    }
    /* Default value if the card value is not found */
    return 0;
}

void to_array(deck_node_t *deck, deck_node_t **D)
{
    deck_node_t *node;
    for (node = deck; node; node = node->next)
    {
        D[get_val(node->card)] = node;
    }
}

