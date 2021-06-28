def LCS(str1, str2):
    len1 = len(str1)
    len2 = len(str2)
    a = [[0 for i in range(len2 + 1)] for j in range(len1 + 1)]
    for i in range(len1):
        for j in range(len2):
            if str1[i] == str2[j]:
                a[i + 1][j + 1] = a[i][j] + 1
            elif a[i + 1][j] > a[i][j + 1]:
                a[i + 1][j + 1] = a[i + 1][j]
            else:
                a[i + 1][j + 1] = a[i][j + 1]
    i = len1
    j = len2
    res = ""
    while (a[i][j]):
        if (a[i][j] == a[i-1][j]):
            i -= 1
        elif(a[i][j] == a[i][j-1]):
            j -= 1
        elif(a[i][j] > a[i-1][j-1]):
            i -= 1
            j -= 1
            res += str(str1[i])
    print(res[::-1])

    return a[-1][-1]

print(LCS("fengchunlin", "sffednagchdurnnldfibvnp"))