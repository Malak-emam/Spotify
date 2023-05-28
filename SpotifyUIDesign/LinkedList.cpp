#include "LinkedList.h"
#include<iostream>
//using namespace std;

song SinglyLinkedListNode::getData()
{
    //implement getter for the data
    return data;

}

void SinglyLinkedListNode::setData(song node_data)
{
    //implement setter for the data
    data.setName(node_data.getName());
    data.setOccurrence(node_data.get_occurrence());

}

void SinglyLinkedListNode::setNext(SinglyLinkedListNode* next)
{
    //implement set next
    this->next = next;

}

SinglyLinkedListNode*::SinglyLinkedListNode::getNext()
{
    //implement get next
    return next;

}



//pre made ** do not touch  **
SinglyLinkedListNode::SinglyLinkedListNode(song node_data)
{
    data.setName(node_data.getName());
    data.setOccurrence(node_data.get_occurrence());
    this->next = nullptr;
}

//pre made ** do not touch  **
SinglyLinkedList::SinglyLinkedList()
{
    this->head = nullptr;
    this->tail = nullptr;
}

SinglyLinkedListNode* SinglyLinkedList::getHead()
{
    return head;
}

void SinglyLinkedList::insert_node(song node_data)
{
    //implement insertion of the node
    SinglyLinkedListNode* newNode = new SinglyLinkedListNode(node_data);
    if (tail == nullptr && head == nullptr) {
        tail = newNode;
        head = newNode;
    }
    else {
        tail->setNext(newNode);
        tail = newNode;

    }
    std::cout << "done" << std::endl;

}
//Sort List
void SinglyLinkedList::sortLinkedList()
{
    SinglyLinkedListNode* currentMinimum = head;
    SinglyLinkedListNode* currentItem = head;
    SinglyLinkedListNode* temp = head;
    while (temp->getNext() != nullptr) {
        while (temp != nullptr) {
            temp = temp->getNext();
            if (currentMinimum->getData().get_occurrence()>temp->getData().get_occurrence()) {
                currentMinimum = temp;
            }
            if (temp->getNext() == nullptr) {
                break;
            }
        }
        song Node_Data = currentItem->getData();
        currentItem->setData(currentMinimum->getData());
        currentMinimum->setData(Node_Data);
        currentItem = currentItem->getNext();
        currentMinimum = currentItem;
        temp = currentItem;
    }

}

//Display values
void SinglyLinkedList::displayAll()
{
    //function to display elements of linked list
    SinglyLinkedListNode* temp = head;
    while (temp != nullptr) {
        if (temp->getNext() == nullptr) {
            std::cout << temp->getData().getName();
            break;
        }
        else {
            std::cout << temp->getData().getName() << "->";

        }
        temp = temp->getNext();
    }
    std::cout << std::endl;
}


bool  SinglyLinkedList::operator==(const SinglyLinkedList& L1) {
    bool Flag = false;
    SinglyLinkedListNode* temp1 = this->head;
    SinglyLinkedListNode* temp2 = L1.head;
    while (temp1 != nullptr && temp2 != nullptr) {
        if (temp1->getData() == temp2->getData()) {
            Flag = true;
        }
        else {
            Flag = false;
        }
        temp1 = temp1->getNext();
        temp2 = temp2->getNext();
    }
    if (temp1 == nullptr && temp2 == nullptr && Flag == true) {
        return 1;
    }
    else {
        return 0;
    }
    // Compare the data in the nodes of the linked lists to check if they are equal.
    // If all data attributes are equal and the lists are the same length, return 1 .
    // Otherwise, return 0 .

}

void SinglyLinkedList::deleteN(int position)
{
    SinglyLinkedListNode* temp = head;
    SinglyLinkedListNode* prev = head;
    if (position == 1) {
        head = head->getNext();
        return;
    }
    else {
        temp = temp->getNext();
        for (int i = 1; i < position - 1; i++) {
            prev = prev->getNext();
            temp = temp->getNext();
        }
    }
    if (temp->getNext()) {
        prev->setNext(temp->getNext());
    }
    else {
        prev->setNext(NULL);
        tail = prev;
    }
    delete temp;
}

void SinglyLinkedList::reverseSort() {
    // print each  value from the reversed list.
        // If the given list is empty, do not print anything.
    if (head != nullptr && tail != nullptr) {
        SinglyLinkedListNode* temp1, * temp2, * temp3, * mytail;
        mytail = head;
        temp1 = head;
        temp2 = temp1->getNext();
        temp3 = temp2->getNext();
        while (1) {
            if (temp2 == nullptr) {
                break;
            }

            temp2->setNext(temp1);
            temp1 = temp2;
            if (temp3 == nullptr)
                break;

            temp2 = temp3;
            if (temp2->getNext() == nullptr) {
                temp3 = nullptr;
            }
            else {
                temp3 = temp3->getNext();
            }
        }

        head = tail;
        tail = mytail;
        tail->setNext(nullptr);
    }
    //displayAll();
}

SinglyLinkedListNode* SinglyLinkedList::makeListCircular() {

    //Given a singly linked list,
    // we have to convert it into circular linked list.
   //by making the tail points to the head
    tail->setNext(head);
    return nullptr;
}
/*
void SinglyLinkedList::displayCircular()
{

    SinglyLinkedListNode* temp = head;
    std::cout << temp->getData() << "->";
    temp = temp->getNext();
    while (temp != head) {

        if (temp->getNext() == head) {
            std::cout << temp->getData();
        }
        else {
            std::cout << temp->getData() << "->";
        }
        temp = temp->getNext();
    }
    std::cout << std::endl;
    //function to display elements of linked list
}
*/
bool SinglyLinkedList::has_cycle() {
    
    SinglyLinkedListNode* step1 = head;
    SinglyLinkedListNode* step2 = head;
    while (1) {
        step1 = step1->getNext();
        step2 = step2->getNext()->getNext();
        if (step1 == step2) {
            return 1;
        }
        else if (step2 == nullptr) {
            return 0;
        }

    }
}
 void SinglyLinkedList::deleteNode( std::string key){
    
        // Store head node
        SinglyLinkedListNode* temp = head;
        SinglyLinkedListNode* prev = NULL;

        // If head node itself holds
        // the key to be deleted
        if (temp != NULL && temp->getData() == key)
        {
            head = temp->getNext(); // Changed head
            delete temp;            // free old head
            return;
        }

        // Else Search for the key to be deleted,
        // keep track of the previous node as we
        // need to change 'prev->next' */
        else
        {
            while (temp != NULL && temp->getData() != key)
            {
                prev = temp;
                temp = temp->getNext();
            }

            // If key was not present in linked list
            if (temp == NULL)
                return;

            // Unlink the node from linked list
            prev->setNext(temp->getNext());

            // Free memory
            delete temp;
        }
    }

    // This function prints contents of
    // linked list starting from the
    // given node
    
 int SinglyLinkedList::getCount(){
    
        int count = 0; // Initialize count
        SinglyLinkedListNode* current = head; // Initialize current
        while (current != NULL) {
            count++;
            current = current->getNext();
        }
        return count;
 }

