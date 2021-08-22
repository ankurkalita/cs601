#include "./doubly_linked_list_node.h"
#include <iostream>

int main(){
    doubly_linked_list instance = doubly_linked_list();

    struct doubly_linked_list::node* list = NULL;

    instance.doubly_linked_list::create(&list, 1);

    std::cout << "After creation" << std::endl;
    instance.doubly_linked_list::display(&list);
    
    instance.doubly_linked_list::insert_at_the_beginning(&list, 7);

    std::cout << "\nAfter insert at the beginning" << std::endl;
    instance.doubly_linked_list::display(&list);

    instance.doubly_linked_list::insert_at_the_end(&list, 6);

    std::cout << "\nAfter insert at the End" << std::endl;
    instance.doubly_linked_list::display(&list);
    
    instance.doubly_linked_list::delete_beginning_node(&list);

    std::cout << "\nAfter Delete Beginning Node" << std::endl;
    instance.doubly_linked_list::display(&list);

    instance.doubly_linked_list::delete_last_node(&list);

    std::cout << "\nAfter Delete last Node" << std::endl;
    instance.doubly_linked_list::display(&list);

    instance.doubly_linked_list::insert_at_the_end(&list, 9);

    std::cout << "\nAfter insert at the End" << std::endl;
    instance.doubly_linked_list::display(&list);    
    
    instance.doubly_linked_list::insert_at_the_end(&list, 10);

    std::cout << "\nAfter insert at the End" << std::endl;
    instance.doubly_linked_list::display(&list);

    instance.doubly_linked_list::delete_at_any_random_location(&list, 2);
    std::cout << "\nAfter delete at the location 2 randomly" << std::endl;
    instance.doubly_linked_list::display(&list);
}