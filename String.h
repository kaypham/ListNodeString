//
//  String.hpp
//  HW5
//
//  Created by Han Pham on 2/5/16.
//  Copyright © 2016 45C. All rights reserved.
//

#include <iostream>

using namespace std;

class String
{
public:
    /// Both constructors should construct
    /// from the parameter s
    String( const char * s = "");
    String( const String & s );
    String operator = ( const String & s );
    char & operator [] ( const int index );
    int length() const {return ListNode::length(head);}
    int indexOf( char c ) const;
    bool operator == ( const String & s ) const;
    bool operator < ( const String & s ) const;
    /// concatenates this and s
    String operator + ( const String & s ) const;
    /// concatenates s onto end of this
    String operator += ( const String & s );
    void print( ostream & out );
    void read( istream & in );
    static void getAllocation();                //make this method static so all instances can share
    ~String();
private:
    bool inBounds( int i )
    {
        return i >= 0 && i < length();
    }
    struct ListNode
    {
        char info;
        ListNode * next;
        ListNode(char newInfo, ListNode * newNext)
        : info( newInfo ), next( newNext )
        {
        }// HINT: some primitives you *must* write and use, recursion?
        static ListNode * stringToList(const char *s);
        static ListNode * copy(ListNode * L);
        static bool equal(ListNode * L1, ListNode * L2);
        static ListNode * concat(ListNode * L1, ListNode * L2);
        static int compare(ListNode * L1, ListNode * L2);
        static void deleteList(ListNode * L);
        static int length(ListNode * L); // O(N) so call rarely
    };
    ListNode * head; // no other data members!! - especially no len!
    static void error( char * p )
    {
        cerr << "Error (class String): " << p << endl;
    }
    static int allocation;
    static ListNode* makeNode(char s, ListNode* p);
    static void deleteNode(ListNode* p);
};
ostream & operator << ( ostream & out, String str );
istream & operator >> ( istream & in, String & str );