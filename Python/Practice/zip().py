#zip(*iterables) - creates a zip object by connecting iterables into pairs or sets of more  of tuples

usernames = ["Gamer", "User", "Guest"]
passwords = ("p@ssw0rd", "zaq1@WSX", "abcd1234")

users = zip(usernames,passwords) 

for i in users:
    print(i)