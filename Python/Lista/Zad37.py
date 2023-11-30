
import re
import requests


url = "https://platforma.polsl.pl/rms/"
page = requests.get(url)
html = page.text



pattern = re.compile(r'^(href=")(.*")', re.IGNORECASE)
a= re.findall('href="([^#].*?)"',html)
for i in a:
    print(i)

print(f"Ilosc linkow na stronie: {len(a)}")
