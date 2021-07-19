// removeElement preserves the order of the remaining elements in the array.
// @param: char array that is ordered in some way.
// @param: int numElems is the number of elements
// @param: int position of the element being removed
// @returns true if the element is removed, false otherwise.
// be careful to use reference parameters where necessary!

bool removeElement (char array[], int& numElems, int position)
{
    int i, index = position;
    if (position <0 || position >= numElems)
        return false; 
        //condition check: whether the position is out of range or not exist -- remove failed
    /* else if (position = numElems)
    {
        //removing the last element of the array
        array[index]=''; 
    } */
    for( i= index; i< numElems; i++)
    {
        array[i] = array[i+1];
    }
    numElems = numElems -1;
    return true;
}