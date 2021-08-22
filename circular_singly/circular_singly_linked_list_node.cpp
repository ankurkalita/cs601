#include "./circular_singly_linked_list_node.h"
#include <iostream>

//  Create a linked list with value 0 or provided value
void circular_singly_linked_list::create(struct node** list, int value = 0){
    if(*list == NULL){
        *list = new node;

        if(*list != NULL){
            (*list)->data = value;
            (*list)->next = *list; 
            std::cout << "Created a Linked list with first node data " << value << std::endl;
        } else {
            std::cout << "Error Creating Linked List";
        }
    }
}

//  a. Insert a node at the beginning 
void circular_singly_linked_list::insert_at_the_beginning(struct node** list, int value){
    //  Create a new node
    struct node* temp = new node;

    //  Assign the head node address to the next of the temp node, also assign the data as the value provided
    temp->data = value;
    temp->next = *list;

    //Last node
    struct node* last = *list;

    //Iterate till we reach the end of the Linked list
    while(last->next!= *list){
        last = last->next;
    }
    last->next = temp;
    //  Change the head of the node to the new created node
    *list = temp;
}

//  b.Insert a node at the end
void circular_singly_linked_list::insert_at_the_end(struct node** list, int value){
    //  Create a new node
    struct node* temp = new node;
    //  Assign the temp node next as NULL, also assign the data as the value provided
    temp->data = value;
    temp->next = *list;

    //Last node
    struct node* last = *list;

    //Iterate till we reach the end of the Linked list
    while(last->next!= *list){
        last = last->next;
    }

    last->next = temp;
}

//  c.Insert a node at any random location
void circular_singly_linked_list::insert_at_any_random_location(struct node** list, int value, int location){
    //  Create a new node
    struct node* temp = new node;
    int count = 0;

    struct node* needed_node = *list;

    
    //  If location is 0, link the end to the new node
    if(location == 0){
        insert_at_the_beginning(list, value);
        return;
    }

    //Iterate till we reach the end of the Linked list or the provided location
    while(needed_node->next != *list){
        count++;
        if(count == location){
            break;
        }

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
void circular_singly_linked_list::delete_beginning_node(struct node** list){
    if(*list!=NULL){
        if((*list)->next == *list){
            *list = NULL;
            return;
        }
        struct node* head = *list;
        *list = (*list)->next;

        //Last node
        struct node* last = *list;

        //Iterate till we reach the end of the Linked list
        while(last->next != head){
            last = last->next;
        }

        last->next = *list;
        
        delete head;
    }
}

//  e.Delete last node 
void circular_singly_linked_list::delete_last_node(struct node** list){
    if(*list!=NULL){
        if((*list)->next == NULL){
            *list = NULL;
            return;
        }
        struct node* temp = *list;
        struct node* newlast = temp;
        
        while(temp->next != *list){
            newlast = temp;
            temp = temp->next;
        }
        newlast->next = *list;
        delete temp;
    }
}

//  f.Delete a node at any random location
void circular_singly_linked_list::delete_at_any_random_location(struct node** list, int location){
    int count = 0;

    struct node* needed_node = *list;
    struct node* prev_node = needed_node;

    if(location == 0){
        delete_beginning_node(list);
        return;
    }

    //Iterate till we reach the end of the Linked list or the provided location
    while(needed_node->next != *list){
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
void circular_singly_linked_list::search_for_an_element(struct node** list, int element){
    int count = 0;
    bool found = false;
    struct node* temp = *list;

    //Iterate till we reach the end of the Linked list or the provided location
    while(temp->next != *list){
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

void circular_singly_linked_list::display(struct node** list){
    std::cout << (*list)->data << " ";

    struct node* temp = (*list)->next;

    while(temp != *list){
        std::cout << temp->data << " ";
        temp = temp->next;
    }
}