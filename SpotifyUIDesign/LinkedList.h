#pragma once
//#include <bits/stdc++.h>
//Single Linked List Class
#include"song.h"

class SinglyLinkedListNode
{
private:
    song data;
    SinglyLinkedListNode* next;
public:
    SinglyLinkedListNode(song node_data);
    song getData();
    void setData(song node_data);
    SinglyLinkedListNode* getNext();
    void setNext(SinglyLinkedListNode* next);

};


class SinglyLinkedList
{
private:
    SinglyLinkedListNode* head;
    SinglyLinkedListNode* tail;

public:
    SinglyLinkedList();
    SinglyLinkedListNode* getHead();
    void insert_node(song node_data);
    void sortLinkedList();
    void displayAll();
    void deleteN(int position);
    bool operator==(const SinglyLinkedList& L1);
    void reverseSort();
    bool has_cycle();
    SinglyLinkedListNode* makeListCircular();
   // void displayCircular();
    void deleteNode(std::string key);
    int getCount();
};

