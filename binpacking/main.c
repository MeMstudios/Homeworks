#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
struct node * insert(struct node*, struct bin*);  //Alphabetically insert an item into the bin using a linked list.  Each bin has a linked list in it, the main function will determine if this bin has enough capacity.
void traverse(struct bin);         //Traverse the list in this bin and print out what is inside.
void destroy(struct bin*);          //Destroy the lists in each bin

int main()
{
    //two arrays of structs for the bins and the items to be placed in the bins.
    struct bin bins[20];
    struct node items[20];
    int i, j, n=20;                //n is the number of items.

    //hardcode the items to be placed.
    items[0].name = "Small_dog";
    items[0].size = .63;
    items[0].put = 0;
    items[1].name = "Moose_Skull";
    items[1].size = .25;
    items[1].put = 0;
    items[2].name = "Squirrel";
    items[2].size = .41;
    items[2].put = 0;
    items[3].name = "Mouse";
    items[3].size = .15;
    items[3].put = 0;
    items[4].name = "Goldfish";
    items[4].size = .06;
    items[4].put = 0;
    items[5].name = "Snake";
    items[5].size = .52;
    items[5].put = 0;
    items[6].name = "Human_finger";
    items[6].size = .09;
    items[6].put = 0;
    items[7].name = "Pig_head";
    items[7].size = .39;
    items[7].put = 0;
    items[8].name = "Eagle_feather";
    items[8].size = .02;
    items[8].put = 0;
    items[9].name = "Shark_teeth";
    items[9].size = .11;
    items[9].put = 0;
    items[10].name = "Camel_hump";
    items[10].size = .24;
    items[10].put = 0;
    items[11].name = "Crocodile";
    items[11].size = .94;
    items[11].put = 0;
    items[12].name = "Elephant_tusk";
    items[12].size = .63;
    items[12].put = 0;
    items[13].name = "Cat";
    items[13].size = .28;
    items[13].put = 0;
    items[14].name = "Horse_manure";
    items[14].size = .04;
    items[14].put = 0;
    items[15].name = "Monkey_hand";
    items[15].size = .21;
    items[15].put = 0;
    items[16].name = "Octopus_eye";
    items[16].size = .05;
    items[16].put = 0;
    items[17].name = "Sheep_coat";
    items[17].size = .33;
    items[17].put = 0;
    items[18].name = "Bat";
    items[18].size = .42;
    items[18].put = 0;
    items[19].name = "Chicken_wing";
    items[19].size = .12;
    items[19].put = 0;
    for (i=0; i<n; i++) {  //initialize all the bins with capacity 1.0
        bins[i].cap = 1.0;
        bins[i].list = NULL;
    }


    for (i=0; i<n; i++) {  //iterate through the items
        j=0;
        while (items[i].put == 0) {                     //while this item has not been placed in a bin
            if (items[i].size <= bins[j].cap) {                  //if there is still room in this bin
                bins[j].list = insert(&items[i], &bins[j]);     //insert here
                items[i].put = 1;                               //this item has been placed
                bins[j].cap -= items[i].size;                   //reduce the capacity of this bin
            }
            else j++;                                   //if it didn't fit go to the next bin
        }
    }
    for(i=0; i<n && bins[i].list!=NULL; i++) {          //while the bins list is not null
        printf("bin: %d, (%.2f remaining)\n", i, bins[i].cap);  //tell us the bin number and remaining capacity
        traverse(bins[i]);                                      //then traverse the bins which will print out the contents
    }
    for(i=0; i<n && bins[i].list!=NULL; i++) {                  //de-allocate all the bins

        destroy(&bins[i]);
    }
    return 0;
}
struct node * insert(struct node *i, struct bin *b) {
    struct node *temp=i, *previous=NULL, *current;        //setup the node pointers
    temp->next = NULL;

    if (b->list==NULL) {                  //if this is the first one just return temp

        return temp;
    }

    else if (strcmp(temp->name, b->list->name)<0) {     //if this one is alphabetically before the current first one, replace it and set the next pointer to the previous first
        temp->next = b->list;

        return temp;
    }
    else {                                          //otherwise we need to find where to insert it
        current = b->list;                          //set current to the front of the list
        while (current != NULL && strcmp(current->name, temp->name)<=0){        //while there are still items and this one is less than the new one
            previous = current;                                             //set the previous pointer to current and current to the next
            current = current->next;
        }
        temp->next = current;                                           //once found we set this one before the current and previous' next will point here. Putting the new one in between
        previous->next = temp;

    }

    return b->list;  //return the front.

}
void traverse(struct bin b){
    struct node *temp = b.list;
    while (temp!=NULL) {
        printf("%s (%f)\n", temp->name, temp->size);
        temp = temp->next;
    }
}
void destroy(struct bin *b)
{
    struct node *temp, *front=b->list;          // points to current node to be deallocated
    while(front!=NULL) {        // while still nodes in the list
        temp=front;             // point at current node
        front=front->next;      // move front pointer to next node
        free(temp);             // dispose of current node
    }
}

