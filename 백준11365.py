if __name__ == '__main__':
    while True :
        string = input()
        if string == "END":
            break
        backString = string[::-1]
        print(backString)