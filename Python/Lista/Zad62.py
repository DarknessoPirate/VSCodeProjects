class implementacjaPow:
    def __init__(self,x,n):
        self.x = x
        self.n = n

    def policzxn(self):
        print(pow(self.x,self.n))

testobj = implementacjaPow(4,3)
testobj.policzxn()