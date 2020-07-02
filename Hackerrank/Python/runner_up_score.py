if __name__ == '__main__':
    n = int(raw_input())
    arr = map(int, raw_input().split())

    x = -101
    for i in range(0,len(arr)):
        if x<arr[i]:
            y = x
            x = arr[i]
        elif y<arr[i] and arr[i]!=x:
            y=arr[i]
    print(y)