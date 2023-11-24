import math

name = "Imie Nazwisko"
first_name = name[0:name.find(" ")]
last_name = name[name.find(" ")+1:]
website = "https://www.google.com"
slice = slice(website.find(".")+1,website.find(".com"))
print(website[slice])
