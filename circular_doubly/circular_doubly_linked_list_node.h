class circular_doubly_linked_list{
    public:
        struct node{
            int data;
            struct node* next;
            struct node* prev;
        };
        void create(struct node**, int);
        void insert_at_the_beginning(struct node**, int);
        void insert_at_the_end(struct node**, int);
        void display(struct node**);
        void delete_beginning_node(struct node** list);
        void delete_last_node(struct node** list);
        void delete_at_any_random_location(struct node** list, int location);
};