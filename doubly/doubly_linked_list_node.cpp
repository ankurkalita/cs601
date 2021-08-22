#include "./doubly_linked_list_node.h"
#include <iostream>

//  Create a linked list with value 0 or provided value
void doubly_linked_list::create(struct node** list, int value = 0){
    if(*list == NULL){
        *list = new node;

        if(*list != NULL){
            (*list)->data = value;
            (*list)->next = NULL; 
            (*list)->prev = NULL;
            std::cout << "Created a Linked list with first node data " << value << std::endl;
        } else {
            std::cout << "Error Creating Linked List";
        }
    }
}

//  a. Insert a node at the beginning 
void doubly_linked_list::insert_at_the_beginning(struct node** list, int value){
    //  Create a new node
    struct node* temp = new node;

    //  Assign the head node address to the next of the temp node, also assign the data as the value provided
    temp->data = value;
    temp->next = *list;
    temp->prev = NULL;

    //  Assign the current head node prev to the new head
    (*list)->prev = temp;

    //  Change the head of the node to the new created node
    *list = temp;
}

//  b.Insert a node at the end
void doubly_linked_list::insert_at_the_end(struct node** list, int value){
    //  Create a new node
    struct node* temp = new node;
    //  Assign the temp node next as NULL, also assign the data as the value provided
    temp->data = value;
    temp->next = NULL;

    //Last node
    struct node* last = *list;

    //Iterate till we reach the end of the Linked list
    while(last->next != NULL){
        last = last->next;
    }

    last->next = temp;
    temp->prev = last;
}

//  c.Delete beginning node 
void doubly_linked_list::delete_beginning_node(struct node** list){
    if(*list!=NULL){
        if((*list)->next == NULL){
            *list = NULL;
            return;
        }
        struct node* head = *list;
        *list = (*list)->next;
        (*list)->prev = NULL;
        delete head;
    }
}

//  d.Delete last node 
void doubly_linked_list::delete_last_node(struct node** list){
    if(*list!=NULL){
        if((*list)->next == NULL){
            *list = NULL;
            return;
        }
        struct node* temp = *list;
        struct node* newlast = temp;
        
        while(temp->next != NULL){
            newlast = temp;
            temp = temp->next;
        }
        newlast->next = NULL;
        delete temp;
    }
}

//  e.Delete a node at any random location(In between nodes)
void doubly_linked_list::delete_at_any_random_location(struct node** list, int location){
    int count = 0;

    struct node* needed_node = *list;

    if(location == 0){
        delete_beginning_node(list);
        return;
    }
    //Iterate till we reach the end of the Linked list or the provided location
    while(needed_node->next != NULL){
        
        if(count == location){
            break;
        }

        count++;
        needed_node = needed_node->next;
    }

    if(count != location){
        std::cout << "\nLocation exceeds linked list size";
        return;
    }
    struct node* previous_node = needed_node->prev;

    previous_node->next = needed_node->next;
    delete needed_node;    
}

void doubly_linked_list::display(struct node** list){
    struct node* temp = *list;
    while(temp != NULL){
        std::cout << temp->data << " ";
        temp = temp->next;
    }
}