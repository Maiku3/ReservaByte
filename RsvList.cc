#include <iostream>
using namespace std;
#include <string>

#include "RsvList.h"

RsvList::RsvList() : head(NULL)
{
}

RsvList::~RsvList()
{
    Node *currNode = head;
    Node *nextNode;

    while (currNode != NULL)
    {
        nextNode = currNode->next;
        delete currNode->data;
        delete currNode;
        currNode = nextNode;
    }
}

void RsvList::add(Reservation *r)
{
    Node *newNode = new Node;
    newNode->data = r;
    newNode->next = NULL;

    Node *prevNode = NULL;
    Node *currNode = head;

    while (currNode != NULL)
    {
        if (r->lessThan(currNode->data))
        {
            break;
        }
        prevNode = currNode;
        currNode = currNode->next;
    }

    if (prevNode == NULL)
    {
        head = newNode;
    }
    else
    {
        prevNode->next = newNode;
    }

    newNode->next = currNode;
}

void RsvList::convertToArray(Reservation **arr, int &size)
{
    size = 0;
    Node *currNode = head;
    while (currNode != NULL)
    {
        arr[size++] = currNode->data;
        currNode = currNode->next;
    }
}

void RsvList::print()
{
    cout << endl
         << "RESERVATIONS:" << endl;

    Node *currNode = head;
    while (currNode != NULL)
    {
        currNode->data->print();
        currNode = currNode->next;
    }
}