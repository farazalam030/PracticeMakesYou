amt=1e4
# print ("amtInvested=", amt)
rate=15
zakaat=0
print ("Initial Investment = INR %d LAKHS, Rate/Month=%d" % (amt/1e5,rate))

print ("Month, Final_Amount(INR),tax (INR), Zakaat(INR)")
for i in range(12*10):
    tax=amt*rate/100.0  * 0.2
    fAmt=amt*(1+rate/100.0*(1-20/100.0))
    rt=((fAmt-amt)/(amt*1.0))*100.0
    amt=fAmt
    if ((i+1)%12==0):
        zakaat=fAmt*2.5/100
        fAmt=fAmt-zakaat
    if fAmt/1e7 >= 1:
           print("%d,%.2f CRORE,%.2f LAKHS,%.2f" % (i+1,fAmt/1e7,tax/1e5,zakaat) )
    else: 
           print("%d,%.2f LAKHS,%.2f THOUSANDS,%.2f" % (i+1,fAmt/1e5,tax/1e3,zakaat) )
    zakaat=0