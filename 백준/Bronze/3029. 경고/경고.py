if __name__ == '__main__':
    startHour, startMinute, startSecond = map(int, input().split(':'))
    endHour, endMinute, endSecond = map(int, input().split(":"))

    result = ((endHour*60*60 + endMinute*60 + endSecond) -
              (startHour*60*60 + startMinute*60 + startSecond))
    if result <= 0:
        result += 24*60*60

    resultHour = result // 60 // 60
    resultMinute = result // 60 % 60
    resultSecond = result % 60

    print("%02d:%02d:%02d" % (resultHour, resultMinute, resultSecond))