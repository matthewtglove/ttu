/*
	Title:  PlainBox.cpp
*/

template<typename ItemType>
PlainBox<ItemType>::PlainBox()
{
	//empty....but necessary in order to create an object that doesn't get initialized when created
} 

template<typename ItemType>
PlainBox<ItemType>::PlainBox(const ItemType& theItem)
{
   item = theItem;
} 

template<typename ItemType>
void PlainBox<ItemType>::setItem(const ItemType& theItem)
{
   item = theItem;
} 

template<typename ItemType>
ItemType PlainBox<ItemType>::getItem() const
{
   return item;
} 