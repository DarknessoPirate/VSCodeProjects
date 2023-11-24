#map() - applies a function to each item in an iterable (list,tuple,etc.)

store = [("shirt",20.00),
         ("pants",25.00),
         ("jacket",50.00),
         ("socks",10.00)]

def to_euros(data):
    return(data[0],data[1]*0.82)

def to_dollar(data):
    return(data[0],data[1]/0.82)

store_euros = list(map(to_euros, store))

print(store_euros)

store_dollars = list(map(to_dollar,store_euros))

print(store_dollars)