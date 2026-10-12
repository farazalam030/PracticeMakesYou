investedValue=10e4
targetChange=2

for year in range(1, 11):
    investedValue *= targetChange
    print(f"Year {year}: Invested Value = {investedValue:.2f}")