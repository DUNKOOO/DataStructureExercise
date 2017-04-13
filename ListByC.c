//
//  ListByC.c
//  MyCtext
//
//  Created by chenshuai on 17/4/13.
//  Copyright © 2017年 chenshuai. All rights reserved.
//

#include "ListByC.h"
#include <stdlib.h>
struct Node {
    ElementType Element;
    Position Next;
};

/** Return true if L is empty*/
int
IsEmpty(List L)
{
    return L -> Next == NULL;
}

/** Return true if P is the last position in list L*/
int
IsLast(List L, Position P)
{
    return P -> Next == NULL;
}

/** Find an element in list*/
Position
Find(ElementType X, List L)
{
    Position P;
    P = L -> Next;
    while (P && P -> Element != X)
        P = P -> Next;
    return P;
}

/** Find the Element  before X*/
Position
FindPrevious(ElementType X, List L)
{
    Position P;
    P = L;
    while (P -> Next != NULL && P -> Next -> Element != X)
        P = P -> Next;
    return P;
}

/** Delete an element in list*/
void
Delete(ElementType X, List L)
{
    Position P, TmpCell;
    P = FindPrevious(X, L);
    if (! IsEmpty(L)) {
        TmpCell = P -> Next;
        P -> Next = TmpCell -> Next;
        free(TmpCell);
    }
}

/** Insert an element after P element*/
void
Insert(ElementType X, List L, Position P)
{
    Position TmpCell;
    TmpCell = malloc(sizeof(struct Node));
    if (TmpCell == NULL) {
        printf("out of space");
    }
    P -> Element = X;
    TmpCell -> Next = P -> Next;
    P -> Next = TmpCell;
}

/** Delete list*/
void
DeleteList(List L)
{
    Position P, Tmp;
    P = L -> Next;
    L -> Next = NULL;
    while (P != NULL) {
        Tmp = P -> Next;
        free(P);
        P = Tmp;
    }
}





