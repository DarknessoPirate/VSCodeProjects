
try:
    numerator = int(input("Enter a number to divide: "))
    denominator = int(input("Enter a number to divide by: "))
    result = numerator / denominator
    print(result)
except ZeroDivisionError:
    print("Can't divide by zero")
except Exception:
    print("Something went wrong!")