iAmt = 10e5
n = 11
print("str(iAmt), str(fAmt), str(zakat)")
for y in range(1, n, 1):
    fAmt = iAmt*(1+5/100.0*(1-20/100.0))**(12)
    zakat = fAmt*2.5/100.0
    fAmt = fAmt-zakat
    print(str(iAmt) + ", " + str(fAmt) + ", " + str(zakat))
    iAmt = fAmt
