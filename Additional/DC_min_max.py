def findMinMax(arr: list, l: int, h:int) -> tuple:
    if l == h:
        return (arr[l], arr[l])
    if h == l + 1:
        if(arr[l] < arr[h]):
            return (arr[l], arr[h])
        else:
            return (arr[h], arr[l])
    mid = (l + h)//2
    l_min, l_max = findMinMax(arr, l, mid)
    r_min, r_max = findMinMax(arr, mid + 1, h)

    return (min(l_min, r_min),max(l_max, r_max))

if __name__ == "__main__" :
    arr = list(map(int, input("Enter the array: ").split()))
    min, max = findMinMax(arr, 0, len(arr) - 1)
    print(f"Min = {min}, Max = {max}")