if __name__ == '__main__':
    length = int(input())
    str = list(input())
    for i in range(length):
        if str[i] == "?" and str[length - i - 1] == "?":
            str[i] = "a"
        elif str[i] == "?":
            str[i] = str[length - i - 1]
    print("".join(str))