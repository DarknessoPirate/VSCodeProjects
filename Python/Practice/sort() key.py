
students = [("Matthew", "F", 60),
            ("Tom","A",33),
            ("Patrick","D",36),
            ("John","B",20),
            ("Dominic","C",78)]

grade = lambda grades:grades[1] # no fucking idea why it works like that
students.sort(key=grade,reverse=True)

for i in students:
    print(i)