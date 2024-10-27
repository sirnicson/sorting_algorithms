#include <stdlib.h>
#include "deck.h"

/**
 * card_value - Returns the value of the card for sorting.
 * @card: Pointer to the card.
 *
 * Return: An integer representing the value.
 */
int card_value(const card_t *card)
{
    if (card->value[0] == 'A')
        return 0; /* Ace */
    if (card->value[0] == '2')
        return 1;
    if (card->value[0] == '3')
        return 2;
    if (card->value[0] == '4')
        return 3;
    if (card->value[0] == '5')
        return 4;
    if (card->value[0] == '6')
        return 5;
    if (card->value[0] == '7')
        return 6;
    if (card->value[0] == '8')
        return 7;
    if (card->value[0] == '9')
        return 8;
    if (card->value[0] == '1' && card->value[1] == '0')
        return 9; /* Ten */
    if (card->value[0] == 'J')
        return 10; /* Jack */
    if (card->value[0] == 'Q')
        return 11; /* Queen */
    if (card->value[0] == 'K')
        return 12; /* King */

    return 13; /* Should not happen */
}

/**
 * card_compare - Comparison function for qsort.
 * @a: Pointer to the first card.
 * @b: Pointer to the second card.
 *
 * Return: Negative if a < b, positive if a > b, 0 if equal.
 */
int card_compare(const void *a, const void *b)
{
    const deck_node_t *card_a = *(const deck_node_t **)a;
    const deck_node_t *card_b = *(const deck_node_t **)b;

    int value_diff = card_value(card_a->card) - card_value(card_b->card);
    if (value_diff != 0)
        return value_diff;

    return card_a->card->kind - card_b->card->kind;
}

/**
 * sort_deck - Sorts a deck of cards.
 * @deck: Pointer to the head of the deck.
 */
void sort_deck(deck_node_t **deck)
{
    deck_node_t **array;
    deck_node_t *current;
    size_t count = 0, i;

    /* Count the number of cards in the deck */
    current = *deck;
    while (current)
    {
        count++;
        current = current->next;
    }

    /* Allocate memory for an array of pointers to deck nodes */
    array = malloc(sizeof(deck_node_t *) * count);
    if (!array)
        return;

    /* Fill the array with the deck nodes */
    current = *deck;
    for (i = 0; i < count; i++)
    {
        array[i] = current;
        current = current->next;
    }

    /* Sort the array using qsort */
    qsort(array, count, sizeof(deck_node_t *), card_compare);

    /* Rebuild the sorted linked list */
    for (i = 0; i < count; i++)
    {
        if (i > 0)
            array[i]->prev = array[i - 1];
        else
            *deck = array[i]; /* Update the head of the deck */

        if (i < count - 1)
            array[i]->next = array[i + 1];
        else
            array[i]->next = NULL; /* Last element points to NULL */
    }
    array[0]->prev = NULL; /* The head's previous should be NULL */

    /* Free the array of pointers */
    free(array);
}

