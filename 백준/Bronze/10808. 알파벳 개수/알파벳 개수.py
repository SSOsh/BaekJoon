if __name__ == '__main__':
    str = input()
    result = [0] * 26
    for i in str:
        result[ord(i) - 97] += 1

    for i in result:
        print(i, end=' ')