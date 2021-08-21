#include "./singly_linked_list_node.h"
#include <iostream>

//  Create a linked list with value 0 or provided value
void singly_linked_list::create(struct node** list, int value = 0){
    if(*list == NULL){
        *list = new node;

        if(*list != NULL){
            (*list)->data = value;
            (*list)->next = NULL; 
            std::cout << "Created a Linked list with first node data " << value << std::endl;
        } else {
            std::cout << "Error Creating Linked List";
        }
    }
}

//  a. Insert a node at the beginning 
void singly_linked_list::insert_at_the_beginning(struct node** list, int value){
    //  Create a new node
    struct node* temp = new node;

    //  Assign the head node address to the next of the temp node, also assign the data as the value provided
    temp->data = value;
    temp->next = *list;

    //  Change the head of the node to the new created node
    *list = temp;
}

//  b.Insert a node at the end
void singly_linked_list::insert_at_the_end(struct node** list, int value){
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
}

//  c.Insert a node at any random location
void singly_linked_list::insert_at_any_random_location(struct node** list, int value, int location){
    //  Create a new node
    struct node* temp = new node;
    int count = 1;

    struct node* needed_node = *list;

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

    //  Assign the node next address to the next of the temp node, also assign the data as the value provided
    temp->data = value;
    temp->next = needed_node->next;
    
    needed_node->next = temp;
}

//  d.Delete beginning node 
void singly_linked_list::delete_beginning_node(struct node** list){
    if(*list!=NULL){
        if((*list)->next == NULL){
            *list = NULL;
            return;
        }
        struct node* head = *list;
        *list = (*list)->next;
        delete head;
    }
}

//  e.Delete last node 
void singly_linked_list::delete_last_node(struct node** list){
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

//  f.Delete a node at any random location
void singly_linked_list::delete_at_any_random_location(struct node** list, int location){
    int count = 1;

    struct node* needed_node = *list;
    struct node* prev_node = needed_node;

    //Iterate till we reach the end of the Linked list or the provided location
    while(needed_node->next != NULL){
        
        if(count == location){
            break;
        }

        count++;
        prev_node = needed_node;
        needed_node = needed_node->next;
    }

    if(count != location){
        std::cout << "\nLocation exceeds linked list size";
        return;
    }

    //  Assign the node next address to the next of the previous node
    prev_node->next = needed_node->next;
    delete needed_node;    
}

//  g.Search for an element
void singly_linked_list::search_for_an_element(struct node** list, int element){
    int count = 0;
    bool found = false;
    struct node* temp = *list;

    //Iterate till we reach the end of the Linked list or the provided location
    while(temp->next != NULL){
        if(temp->data == element){
            found = true;
            break;
        }
        temp = temp->next;
        count++;
    }

    if(!found){
        std::cout << "\nNot Found";
        return;
    } else {
        std::cout << "\nFound at " << count;
    }   
}

void singly_linked_list::display(struct node** list){
    struct node* temp = *list;
    while(temp != NULL){
        std::cout << temp->data << " ";
        temp = temp->next;
    }
}