import calendar
import datetime

y = int(input("Podaj rok: "))
w = int(input("Podaj tydzien: "))

first_day_of_year = datetime.datetime(y,1,1)
first_day_of_week = first_day_of_year - datetime.timedelta(days=first_day_of_year.weekday())
difference = w - 1
first_monday = first_day_of_week + datetime.timedelta(weeks=difference)
date = first_monday.strftime("%Y-%m-%d")
print(f"Data pierwszego poniedzialku: {date}")