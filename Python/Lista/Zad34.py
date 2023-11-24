plcie = ["Mezczyzna", "Kobieta"]
rozmiary = ["XXL","XL","L","M","S","XS"]
kolory = ["bialy","czarny","zielony","czerwony","niebieski","zolty","szary"]
metki = []
i = 1
for p in plcie:
    for r in rozmiary:
        for k in kolory:
            metki.append([p,r,k])
            with open(f"C:\\Users\\daw78\\Desktop\\VSCodeProjects\\Python\\Lista\\metki\\metka_{i}.txt","w") as myFile:
                myFile.write(f"{p} , {r} , {k}")
                i += 1  


for i in metki:
    print(i)