import datetime


v = input("Podaj date: ")
data = datetime.datetime.fromisoformat(v)
print(data)
