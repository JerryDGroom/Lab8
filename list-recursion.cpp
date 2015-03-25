/*
*******************************************************************

Laboratory 8
Recursion Lab || Group Project

Jerry Groom & Dani Breon
3/29/2015

*******************************************************************
*/


#include <iostream>
#include "list-recursion.h"

using namespace std;


template < class DT >
ListNode<DT>:: ListNode ( const DT &nodeDataItem, ListNode<DT> *nextPtr )

// Creates a list node containing item elem and next pointer
// nextPtr.

    : dataItem(nodeDataItem),
      next(nextPtr)
{}

//--------------------------------------------------------------------

template < class DT >
List<DT>:: List ( int ignored )

// Creates an empty list. The argument is included for compatibility
// with the array implementation and is ignored.

    : head(0),
      cursor(0)
{}

//--------------------------------------------------------------------

template < class DT >
List<DT>:: ~List ()

// Frees the memory used by a list.

{
    clear ();
}

//--------------------------------------------------------------------

template < class DT >
void List<DT>:: insert ( const DT &newDataItem )

// Inserts newDataItem after the cursor. If the list is empty, then
// newDataItem is inserted as the first (and only) data item in the
// list. In either case, moves the cursor to newDataItem.

{
    if ( head == 0 )             // Empty list
    {
        head = new ListNode<DT>(newDataItem,0);
        cursor = head;
    }
    else                         // After cursor
    {
        cursor->next = new ListNode<DT>(newDataItem,cursor->next);
        cursor = cursor->next;
    }
}

//--------------------------------------------------------------------

template < class DT >
void List<DT>:: clear ()

// Removes all the data items from a list.

{
    ListNode<DT> *p,      // Points to successive nodes
             *nextP;  // Points to next node
    p = head;
    while ( p != 0 )
    {
        nextP = p->next;
        delete p;
        p = nextP;
    }

    head = 0;
    cursor = 0;
}

//--------------------------------------------------------------------

template < class DT >
void List<DT>:: showStructure () const

// Outputs the data items in a list. If the list is empty, outputs
// "Empty list". This operation is intended for testing and
// debugging purposes only.

{
    ListNode<DT> *p;   // Iterates through the list

    if ( head == 0 )
        cout << "Empty list" << endl;
    else
    {
        for ( p = head ; p != 0 ; p = p->next )
            if ( p == cursor )
                cout << "[" << p->dataItem << "] ";
            else
                cout << p->dataItem << " ";
        cout << endl;
    }
}











template < class DT >
void List<DT>:: write () const

// Outputs the data items in a list from beginning to end. Assumes that
// objects of type DT can be output to the cout stream.

{
    cout << endl;
    cout << "List :\t\t";
    writeSub(head);
    cout << endl;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template < class DT >
void List<DT>:: writeSub ( ListNode<DT> *p ) const

// Recursive partner of the write() function. Processes the sublist
// that begins with the node pointed to by p.

{
    // YOUR CODE HERE
    if(p == NULL)
    {
    }
    else
    {
        cout << p->dataItem;
        writeSub(p->next);
    }
    return;
}

//--------------------------------------------------------------------

template < class DT >
void List<DT>:: insertEnd ( const DT &newDataItem )

// Inserts newDataItem at the end of a list. Moves the cursor to
// newDataItem.

{
    cout << "Insert item :\t";
    insertEndSub(head,newDataItem);
    cout << endl;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template < class DT >
void List<DT>:: insertEndSub ( ListNode<DT> *&p,
                               const DT &newDataItem )

// Recursive partner of the insertEnd() function. Processes the
// sublist that begins with the node pointed to by p.

{
    // YOUR CODE HERE
    if(p == NULL)
    {
        insert(newDataItem);
        cout << p->dataItem;
    }
    else
    {
        cout << p->dataItem;
        insertEndSub(p->next,newDataItem);
    }
    return;
}

//--------------------------------------------------------------------

template < class DT >
void List<DT>:: writeBackward () const

// Outputs the data items in a list from beginning to end and back
// again. Assumes that objects of type DT can be output to the cout
// stream.

{
    cout << "Mirror List :\t";
    writeBackwardSub(head);
    cout << endl;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template < class DT >
void List<DT>:: writeBackwardSub ( ListNode<DT> *p ) const

// Recursive partner of the writeMirror() function. Processes the
// sublist that begins with the node pointed to by p.

{
    // YOUR CODE HERE
    /*
    ======================
    a b c d d c b a
    ======================
    */

    if(p == NULL)
    {
    }
    else
    {
        cout << p->dataItem;
        writeBackwardSub(p->next);
        cout << p->dataItem;
    }
    return;
}

//--------------------------------------------------------------------

template < class DT >
void List<DT>:: reverse ()

// Reverses the order of the data items in a list.

{
    reverseSub(0,head);
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template < class DT >
void List<DT>:: reverseSub ( ListNode<DT> *p, ListNode<DT> *nextP )

// Recursive partner of the reverse() function. Processes the sublist
// that begins with the node pointed to by nextP.

{

    if ( nextP == NULL) // base case
        head = p; // move head to end of list
    else(p->next != nextP); // recursive case
    {
        if( nextP !=0 )
        {
            reverseSub(nextP,nextP->next);
            nextP->next = p;
        }
        else {}
    }
}

//--------------------------------------------------------------------

template < class DT >
int List<DT>:: getLength () const

// Returns the number of data items in a list.

{
    return getLengthSub(head);
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template < class DT >
int List<DT>:: getLengthSub ( ListNode<DT> *p ) const

// Recursive partner of the getLength() function. Processes the sublist
// that begins with the node pointed to by p.

{
    int length = 0;
    // YOUR CODE HERE

    if(p == NULL) // base case
    {
        for(p = head ; p != 0 ; p = p->next)
        {
            length++;
        }
        return length;
    }
    else // recursive case
    {
        getLengthSub(p->next);
    }
}












