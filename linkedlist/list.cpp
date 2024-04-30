#include "list.h"
#include <string>
#include <iostream>

LinkedList::LinkedList()
    : p_head(nullptr)
{}

// insert at head means we're going to create a new node, and put it at the head of the list
void LinkedList::insert_at_head(std::string new_data)
{
    Node * new_node = new Node();
    new_node->data = new_data;
    new_node->p_next = p_head;
    p_head = new_node;
}

void LinkedList::insert_at_tail(std::string new_data)
{
    Node * new_node = new Node();
    new_node->data = new_data;

    Node * current = p_head;
    if(p_head == nullptr) // !p_head
    {
        p_head = new_node;
        return;
    }
    // assume that current isn't null at least the first time
    while(current->p_next)
    {
        current = current->p_next;
    }
    current->p_next = new_node;
    // did i set the new_node->next = nullptr? [yes because it's automatic]
}


void LinkedList::insert_at_position(std::string new_data, int pos)
{
    if (!pos)
    {
        insert_at_head(new_data);
        return;
    }

    Node * p_current = p_head;
    if(!p_head)
    {
        std::cout << "Cannot insert at position, head is null" << std::endl;
    }
    for(int i = 0; i < pos - 1; i++)
    {
        if (p_current == nullptr)
        {
            std::cout << "list is not long enough for this operation" << std::endl; 
            return;
        }
        p_current = p_current->p_next;
    }
    if (p_current == nullptr)
    {
        std::cout << "list is not long enough for this operation" << std::endl; 
        return;
    }
    Node * next_node = p_current->p_next;
    p_current->p_next = new Node();
    Node * new_node = p_current->p_next;
    new_node->data = new_data;
    new_node->p_next = next_node;
}

void LinkedList::display_list() const
{
    Node * p_current = p_head;
    if(!p_head)
    {
        std::cout << "The list is empty" << std::endl;
        return;
    }
    while(p_current)
    {
        std::cout << p_current->data << " : "; 
        p_current = p_current->p_next;
    }
    std::cout << std:: endl;
}


void LinkedList::remove_from_position(int pos)
{
    if (pos == 0 && p_head)
    {
        Node * old_head = p_head;
        p_head = p_head->p_next;
        delete old_head;
        return;
    }

    Node * p_current = p_head;
    if(!p_head)
    {
        std::cout << "Cannot remove from position, head is null" << std::endl;
    }
    for(int i = 0; i < pos - 1; i++)
    {
        if (p_current == nullptr)
        {
            std::cout << "list is not long enough for this operation" << std::endl; 
            return;
        }
        p_current = p_current->p_next;
    }
    if (p_current == nullptr)
    {
        std::cout << "list is not long enough for this operation" << std::endl; 
        return;
    }
    // this relies on the fact that p_current exists and p_current->p_next
    // is the one we want to kill
    // BUT if pos = 0, then we want to kill the head, the head doesn't have 
    // a previous (which here is set to p_current)
    Node * save_killnode = p_current->p_next;
    p_current->p_next = p_current->p_next->p_next;
    delete save_killnode;
}

void LinkedList::clear()
{
    Node * p_next;
    while(p_head)
    {
        p_next = p_head->p_next;
        delete p_head;
        p_head = p_next;
    }
    p_head = nullptr;
}

LinkedList::~LinkedList()
{
    clear();
}