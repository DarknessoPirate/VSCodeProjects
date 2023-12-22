import datetime
import calendar
import math

res = calendar.monthrange(2023, 12)[1]
print(math.ceil(res/7))