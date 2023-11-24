from urllib.request import urlopen
import re

url = "https://platforma.polsl.pl/rms/"

page = urlopen(url)
html_in_bytes = page.read()
html = html_in_bytes.decode()
a = re.findall('(?<=href=")(.*?)(?=")' ,html)
for i in a:
    print(i)
