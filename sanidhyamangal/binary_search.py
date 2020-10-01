# function to perform binary search
def binary_search(array: list, num:int) -> tuple:
    """
    function to perform binary search on the given array
    :param array: sorted array on which searching is needed to perform
    :param num: number which is required to found
    :return: tuple of position and number
    """
    # apply merge sort to the function 
    # find out the values of high and low
    low,high = 0, len(array)
    # iterate until low is less than high
    while low <= high:
        # find the mid of the array
        mid = (low + high) // 2
        # check if mid of array is equal to number
        if num == array[mid]:
             # return mid and num
            return mid, num
        # if num is less than mid of array update high as mid-1 of array
        elif num < array[mid]:
            high = mid-1
        # else update low as mid+1 of array
        else:
            low = mid + 1
    # return none for the position of the number
    return None, num
