if __name__ == '__main__':
    loop = int(input())

    for _ in range(loop):
        result = input().replace(' ', '')
        countResult = [0] * 26
        for i in result:
            countResult[ord(i) - 97] += 1

        if countResult.count(max(countResult)) > 1:
            print('?')
        else :
            print(chr(97 + countResult.index(max(countResult))))