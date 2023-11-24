import ast

def checkType():
    try:
        val = ast.literal_eval(input("Podaj liczbę: "))
    except ValueError:
        pass
    return type(val)

print(checkType());