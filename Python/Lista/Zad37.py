
import re
from urllib.request import urlopen
import urllib.request


url = "https://pypi.org/project/requests/"
webUrl = urllib.request.urlopen(url)
#htmlbinary = page.read()
#html = htmlbinary.decode()

#pattern = re.compile(r'href="*"', re.IGNORECASE)
#a= re.findall(pattern,html)S