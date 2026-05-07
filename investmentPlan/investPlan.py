amt=40e5
# print ("amtInvested=", amt)
rate=10
zakaat=0
print ("Initial Investment = INR %d , Rate/Month=%d" % (amt,rate))

print ("TIME, Final_Amount(INR),tax (INR), Zakaat(INR)")
for i in range(12*15):
    tax=amt*rate/100.0  * 0.2
    fAmt=amt*(1+rate/100.0*(1-20/100.0))-3e3
    rt=((fAmt-amt)/(amt*1.0))*100.0
    amt=fAmt
    if ((i+1)%12==0):
        zakaat=fAmt*2.5/100
        fAmt=fAmt-zakaat
    if fAmt/1e7 >= 1:
           print("%d years %d months,%.2f CRORE,%.2f LAKHS,%.2f" % ((i+1)/12,(i+1)%12,fAmt/1e7,tax/1e5,zakaat) )
    else: 
           print("%d years %d months,%.2f LAKHS,%.2f THOUSANDS,%.2f" % ((i+1)/12,(i+1)%12,fAmt/1e5,tax/1e3,zakaat) )
    zakaat=0