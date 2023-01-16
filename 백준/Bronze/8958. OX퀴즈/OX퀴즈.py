import sys
n = int(input())
for i in range(n):
    tmp =sys.stdin.readline()
    str = list(tmp)
    con =0
    result=0
    for i in range(len(str)):
        if str[i] == 'O':
            con = con+1
            result+=con
            continue
        con=0
    print(result)

