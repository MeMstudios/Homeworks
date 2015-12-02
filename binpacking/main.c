#include <stdio.h>
#include <stdlib.h>
/*
Michael Murphy
CSC-362
Prof. Richard Fox
12/2/2015
Structs and Linked-list program. Nodes are items to placed in an array of bins.  Bins have a capacity of 1.0 and every item is some fraction of this.
This program uses the simple first fit strategy where each item will go into the first bin that can fit it.
*/
struct node {
    char *name;             //string to store the name of this item.
    double size;            //double for size of the item (will be a portion of 1.  (0.1 - 0.99)
    int put;                //boolean to know if it's been put in a bin or not.
    struct node *next;      //pointer to the next node in the list.
};

struct bin {
    double cap;             //cap = the bins capacity (starting at 1.0)
    struct node *list;      //pointer to the front of the list of items currently in the bin.
};

//function prototypes
struct node * insert(struct node *, struct bin *);  //Alphabetically insert an item into the bin using a linked list.  Each bin has a linked list in it, the main function will determine if this bin has enough capacity.
void traverse(struct node *, struct bin *);         //Traverse the list in this bin and print out what is inside.
void destroy(struct node *, struct bin *);          //Destroy the lists in each bin

int main()
{
    //two arrays of structs for the bins and the items to be placed in the bins.
    struct bin bins[10];
    struct node items[10];
    int i, j=0, n=10;                //n is the number of bins.
    //hardcode the items to be placed.
    items[0].name = "Vase";
    items[0].size = .5;
    items[0].put = 0;
    items[1].name = "Bowling_Ball";
    items[1].size = .9;
    items[1].put = 0;
    items[2].name = "Book";
    items[2].size = .3;
    items[2].put = 0;
    items[3].name = "Umbrella";
    items[3].size = .4;
    items[3].put = 0;
    items[4].name = "Gold_Medal";
    items[4].size = .7;
    items[4].put = 0;
    items[5].name = "Speaker1";
    items[5].size = .4;
    items[5].put = 0;
    items[6].name = "Walkman";
    items[6].size = .2;
    items[6].put = 0;
    items[7].name = "Speaker2";
    items[7].size = .4;
    items[7].put = 0;
    for (i=0; i<n; i++) {
        bins[i].cap = 1.0;
        bins[i].list = NULL;
    }
    for (i=0; i<n; i++) {
        j=0;
        while (items[i].put == 0) {

                if (bins[j].cap + items[i].size <= 1.0) {
                    insert(items[i], bins[j]);
                }
                else j++;
            }
        }
    }
    return 0;
}
