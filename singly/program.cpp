#include "singly_linked_list_node.h"
#include <iostream>

int main(){
    singly_linked_list instance = singly_linked_list();

    struct singly_linked_list::node* list = NULL;

    instance.singly_linked_list::create(&list, 1);

    std::cout << "After creation" << std::endl;
    instance.singly_linked_list::display(&list);
    
    instance.singly_linked_list::insert_at_the_beginning(&list, 7);

    std::cout << "\nAfter insert at the beginning" << std::endl;
    instance.singly_linked_list::display(&list);

    instance.singly_linked_list::insert_at_the_end(&list, 6);

    std::cout << "\nAfter insert at the End" << std::endl;
    instance.singly_linked_list::display(&list);

    instance.singly_linked_list::insert_at_any_random_location(&list, 8, 1);

    std::cout << "\nAfter insert at the location 1 randomly" << std::endl;
    instance.singly_linked_list::display(&list);

    instance.singly_linked_list::insert_at_any_random_location(&list, 9, 2);

    std::cout << "\nAfter insert at the location 2 randomly" << std::endl;
    instance.singly_linked_list::display(&list);
    
    instance.singly_linked_list::delete_beginning_node(&list);

    std::cout << "\nAfter Delete Beginning Node" << std::endl;
    instance.singly_linked_list::display(&list);

    instance.singly_linked_list::delete_last_node(&list);

    std::cout << "\nAfter Delete last Node" << std::endl;
    instance.singly_linked_list::display(&list);

    instance.singly_linked_list::delete_at_any_random_location(&list, 2);

    std::cout << "\nAfter delete at the location 2 randomly" << std::endl;
    instance.singly_linked_list::display(&list);

    instance.singly_linked_list::search_for_an_element(&list, 2);
    instance.singly_linked_list::search_for_an_element(&list, 8);
}