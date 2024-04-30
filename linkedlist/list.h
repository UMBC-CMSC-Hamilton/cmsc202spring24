#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

#include<string>

struct Node {

    Node()
        : data(""), p_next(nullptr)
    {}

    std::string data;
    Node * p_next;
};

class LinkedList
{
    public:
        LinkedList();
        void insert_at_head(std::string new_data);
        void insert_at_tail(std::string new_data);
        void insert_at_position(std::string new_data, int pos);

        void remove_from_position(int pos);

        void display_list() const;
        void clear();
        ~LinkedList();
    private:
        Node * p_head;
};

#endif 