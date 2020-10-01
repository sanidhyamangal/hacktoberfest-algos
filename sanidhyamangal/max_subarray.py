# function to find max subarray
from sys import maxsize


def find_max_crossing_subarray(array: list, low: int, mid: int,
                               high: int) -> tuple:
    """
    A function to perform max sub array in array cross section
    :param array: array in which we need to find array cross subarray
    :param low: lowest index for the array
    :param mid: middle index for the array
    :param high: highest index for the array
    :return: left index, right index and sum of crossing subarray
    """
    # init left sum
    left_sum = -maxsize - 1
    # int sum
    _sum = 0

    # iterate in range from mid downto low-1
    for i in range(mid, low - 1, -1):
        # add array[i] in sum
        _sum += array[i]
        # check if sum is greater than left_sum
        if _sum >= left_sum:
            # update left sum with current sum
            left_sum = _sum
            # assign max left to current index
            max_left = i

    # inti sum to 0
    _sum = 0
    # init right sum to -inf
    right_sum = -maxsize - 1
    # iterate from mid+1 to high
    for i in range(mid + 1, high + 1):
        # update sum with current value
        _sum += array[i]
        # check if sum is greater than right_sum
        if _sum >= right_sum:
            # update right_sum
            right_sum = _sum
            # assign or update max right index to max_right
            max_right = i

    # return max left, max right index and sum of right sum and left sum
    return max_left, max_right, right_sum + left_sum


def find_max_subarray(array: list, low: int, high: int) -> tuple:
    """
    A function to find max sub array
    :param array: array in which we need to find array cross subarray
    :param low: lowest index for the array
    :param high: highest index for the array
    :return: left index, right index and sum of max subarray
    """
    # check if array has only one index
    if high == low:
        # return low index, right index and sum
        return low, high, array[low]
    # when array has more than one element
    else:
        # find middle index of array
        mid = (low + high) // 2
        # find the left subarray by making a recursive call
        left_low, left_high, left_sum = find_max_subarray(array, low, mid)
        # find right subarray by making recursive call
        right_low, right_high, right_sum = find_max_subarray(
            array, mid + 1, high)
        # find cross subarray by making call find max_crossing_subarray
        cross_low, cross_high, cross_sum = find_max_crossing_subarray(
            array, low, mid, high)

        # check if lef sum is greater than right and cross sum
        if left_sum >= right_sum and left_sum >= cross_sum:
            return left_low, left_high, left_sum

        # check if right sum is greater than cross and left sum
        elif right_sum >= left_sum and right_sum >= cross_sum:
            return right_low, right_high, right_sum

        # return when cross sum is greatest
        else:
            return cross_low, cross_high, cross_sum