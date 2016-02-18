//
//  String.cpp
//  HW5
//
//  Created by Han Pham on 2/5/16.
//  Copyright © 2016 45C. All rights reserved.
//

#include "String.h"

String::String(const char* s)
//:head (new String::ListNode(*s, head = nullptr))
:head(nullptr)
{
    head = String::ListNode::stringToList(s);
}

String::String(const String &s)
:head(String::ListNode::copy(s.head))
{
}

String String::operator = (const String &s)
{
    String::ListNode::deleteList(head);
    head = String::ListNode::copy(s.head);
    return *this;
}

char &String::operator [] (const int index)
{
    if (!inBounds(index))
    {
        String::error("Out of Bounds");
    }
    else
    {
        int i = 0;
        for (String::ListNode* p = head; p != nullptr; p = p -> next)
        {
            if (index == i)
            {
                return p -> info;
            }
            i++;
        }
    }
}

int String::indexOf(char c) const
{
    int i = 0;
    for (ListNode* p = head; p != nullptr; p = p->next)
    {
        if (p -> info == c)
        {
            return i;
        }
        i++;
    }
    return -1;
}

bool String::operator == (const String &s) const
{
    return String::ListNode::equal(head, s.head);
}

bool String::operator < (const String &s) const
{
    return String::ListNode::compare(head, s.head) < 0;
}

String String::operator + (const String &s) const
{
    String answer;
    String::ListNode* headCopy = String::ListNode::copy(head);
    answer.head = String::ListNode::concat(headCopy, s.head);
    String::ListNode::deleteList(headCopy);
    return answer;
}

String String::operator += (const String &s)
{
    String::ListNode* headCopy = String::ListNode::copy(head);
    String::ListNode::deleteList(head);
    head = String::ListNode::concat(headCopy, s.head);
    String::ListNode::deleteList(headCopy);
    return *this;
}

void String::print(ostream & out)
{
    /*String::ListNode* result = nullptr;
    for (String::ListNode* p = head; p != nullptr; p = p -> next)
    {
        result = new String::ListNode(p -> info, result);
    }*/
    for (String::ListNode* p = head; p != nullptr; p = p->next) //Because p is already a ListNode, so I don't need to specify String::ListNode::next
    {
        out << p -> info;
    }
}

void String::read(istream &in)
{
    char* input;
    in.getline(input, 10000);
    String::ListNode::deleteList(head);
    head = String::ListNode::stringToList(input);
}

void String::getAllocation()
{
    if (allocation > 0)
    {
        String::error("Memory Leak in class String");
    }
    if (allocation < 0)
    {
        String::error("Too many delete[]s in class String");
    }
    if (allocation == 0)
    {
        cout << "Allocations - deallocations is 0!! Yay!!!\n";
    }
}

String::~String()
{
    String::ListNode::deleteList(head);
}

String::ListNode* String::ListNode::stringToList(const char* s)
{
    /*String::ListNode* result = nullptr;               //This costs the LN goes other way around
    for (int i = 0; s[i] != '\0'; ++i)                  //Also, this cost dangling pointer!
    {
        result = new String::ListNode(s[i], result);
    }
    return result;*/
    return s[0] == '\0' ? nullptr : makeNode(s[0], stringToList(s + 1));
}

String::ListNode* String::ListNode::copy(ListNode* L)
{
    return L == nullptr ? nullptr : makeNode(L -> info, copy(L -> next));
}

bool String::ListNode::equal(ListNode* L1, ListNode* L2)
{

    return L1 == nullptr || L2 == nullptr ? L1 == L2 : L1->info == L2 -> info && equal(L1 -> next, L2 -> next);
}

String::ListNode* String::ListNode::concat(String::ListNode* L1, String::ListNode* L2)
{
    return L1 == nullptr ? copy(L2) :  makeNode(L1 -> info, concat(L1 -> next, L2));
}

int String::ListNode::compare(ListNode* L1, ListNode* L2)
{
    int L1Length, L2Length;
    L1Length = String::ListNode::length(L1);
    L2Length = String::ListNode::length(L2);
    if (L1Length == L2Length)
    {
        while (L1 != nullptr && L2 != nullptr)
        {
            if (L1 -> info != L2 -> info)
            {
                return (int)L1 -> info - (int)L2 -> info;
            }
            L1 = L1 -> next;
            L2 = L2 -> next;
        }
        return 0;
    }
    return L1Length - L2Length;
}

void String::ListNode::deleteList(ListNode* L)
{
    /*String::ListNode* temp;
    for (String::ListNode* p = L; p != nullptr; )
    {
        temp = p;
        p = p -> next;
        delete temp;
    }*/
    if (L != nullptr)
    {
        String::ListNode::deleteList(L -> next);
        deleteNode(L);
    }
}

int String::ListNode::length(String::ListNode *L)
{
    /*int i = 0;
    ListNode* p = L;
    if (p != nullptr)
    {
        while (p != nullptr)
        {
            i++;
            p = p -> String::ListNode::next;
        }
        String::ListNode::deleteList(p);
        return i;
    }
    String::ListNode::deleteList(p);
    return 0;*/
    return L == nullptr ? 0 : 1 + length(L->next);
}

int String::allocation = 0;

String::ListNode* String::makeNode(char s, String::ListNode* L)
{
    allocation++;
    return new String::ListNode(s, L);
}

void String::deleteNode(String::ListNode* L)
{
    allocation--;
    delete L;
}

ostream & operator << ( ostream & out, String str )
{
    str.print(out);
    return out;
}

istream & operator >> ( istream & in, String & str)
{
    str.read(in);
    return in;
}

/* for the find function,
 return l == nullptr ? 0 : l -> info == i ? l : find(i, l-> next); 
 
 for remove,
 return !l ? 0 : l->info == i? copy(l->next) : new intLIstNode(l->info, remove(i, l-> next)) */
