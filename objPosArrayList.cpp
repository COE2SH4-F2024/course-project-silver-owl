#include "objPosArrayList.h"

// Check lecture contents on general purpose array list construction, 
// and modify it to support objPos array list construction.

objPosArrayList::objPosArrayList()
{
    listSize = 0;
    arrayCapacity = ARRAY_MAX_CAP;
    aList = new objPos[ARRAY_MAX_CAP];
}

objPosArrayList::~objPosArrayList()
{
    delete[] aList;
}

int objPosArrayList::getSize() const
{
    return listSize;
}

void objPosArrayList::insertHead(objPos thisPos)
{
    if(listSize >= ARRAY_MAX_CAP) return; //safety check 

    for(int i = listSize; i > 0; i--)
    {
        aList[i] = aList[i-1];
    }
    aList[0] = thisPos;
    listSize++;
    //why doesnt alist[0] = thispos work? 
}

void objPosArrayList::insertTail(objPos thisPos)
{
    if(listSize >= ARRAY_MAX_CAP) return; //safety check

    aList[listSize++] = thisPos;
    //listSize++; above is post opertaion incremnet
}

void objPosArrayList::removeHead()
{

    if(listSize == 0) return; //safety check

    for(int i = 1; i < listSize; i++)
    {
        aList[i-1] = aList[i];
    }
    listSize--;
}

void objPosArrayList::removeTail()
{
    if(listSize == 0) return;

    if(listSize > 0)
        listSize--;
}

objPos objPosArrayList::getHeadElement() const
{
    return aList[0];
}

objPos objPosArrayList::getTailElement() const
{
    return aList[listSize - 1];
}

objPos objPosArrayList::getElement(int index) const
{
    // check if index is out of bound
    // then apply respective updates

    //WHATTT IF LISTSIZE = 0??? 

    if(index < 0)
    {
        index = 0;
    } 

    else if(index >= listSize && listSize != 0)  // != 0 case it will push it to -1 , if 3 will go to 2
    {
        index = listSize - 1;
    }

    // Option: You can also "throw exceptions in C++"
    // Option: You can also return an absurd integer to indicate error

    // finally, get element
    return aList[index];
}