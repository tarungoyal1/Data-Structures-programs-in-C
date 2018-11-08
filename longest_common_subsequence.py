from pprint import pprint



def main():

    print("Note: when computing matrix, elements of seq x will be drawn vertically and that of seq y will go horizontally:")
    s1 = list(str(input("Enter seq for x:")))
    s2 = list(str(input("Enter seq for y:")))
    x = [int(ord(i)) for i in s1]
    y = [int(ord(i)) for i in s2]



    # x  = [1,0,0,1,0,1,0,1]
    # y  = [0,1,0,1,1,0,1,1,0]

    numbmatrix = [[0 for _ in range(0, len(y)+1)] for _ in range(0, len(x)+1)]
    arrowmatrix = [[0 for _ in range(0, len(y)+1)]]

    i = 1

    while i<=len(x):
        arrowrow = [0]
        j=1
        while j<=len(y):

            # this is the main logic of computing number
            if x[i-1] == y[j-1]:
                numbmatrix[i][j] = numbmatrix[i - 1][j - 1] + 1
                # diagonal arrow
                arrowrow.append(chr(int('0x2196', 16)))
            else:
                if numbmatrix[i-1][j]>=numbmatrix[i][j-1]:
                    numbmatrix[i][j] = numbmatrix[i-1][j]
                    # up arrow
                    arrowrow.append(chr(int('0x2191', 16)))

                else:
                    numbmatrix[i][j] = numbmatrix[i][j-1]
                    # left arrow
                    arrowrow.append(chr(int('0x2190', 16)))

            #########

            j+=1
        arrowmatrix.append(arrowrow)
        i+=1

    # this is just for printing
    printFinalMatrix(numbmatrix, arrowmatrix)


    # computing the lcs
    lastIndex = [len(numbmatrix)-1, len(numbmatrix[0])-1]

    r = lastIndex[0]

    lcs = []

    while r>0:
        if arrowmatrix[lastIndex[0]][lastIndex[1]] == chr(int('0x2196', 16)):
            # diag
            lcs.append(x[lastIndex[0]-1])
            lastIndex[0]-=1
            lastIndex[1]-=1
            r-=1
        elif arrowmatrix[lastIndex[0]][lastIndex[1]] == chr(int('0x2191', 16)):
            # up arrow
            lastIndex[0]-=1
            r-=1
        else:
            lastIndex[1] -= 1

    # note: lcs list is appended so it is in reverse order, do reverse it again
    lcs = [chr(x) for x in lcs[::-1]]
    print("\nLCS ({}) = {}".format(len(lcs), lcs))

def printFinalMatrix(numbmatrix, arrowmatrix):


    fmat = [[0 for _ in range(0, len(numbmatrix[0]))] for _ in range(0, len(numbmatrix))]

    a=1
    while a<len(numbmatrix):
        b=1
        while b<len(numbmatrix[0]):
            fmat[a][b] = arrowmatrix[a][b]+str(numbmatrix[a][b])
            b+=1
        a+=1

    pprint(fmat)





    # pprint(numbmatrix)
    # pprint(arrowmatrix)


if __name__ == "__main__":
    main()