
class Node:
    def __init__(self):
        self.symbol =''
        self.frequency = 0.0
        self.array = [0]*20
        self.top = 0

def sortByFrequency(n,nodes):
    temp = Node()
    for j in range(1,n):
        for i in range(n):
            if ((nodes[i].frequency) > (nodes[i+1].frequency)):
                temp.frequency = nodes[i].frequency
                temp.symbol = nodes[i].symbol

                nodes[i].frequency = nodes[i+1].frequency
                nodes[i].symbol = nodes[i+1].symbol

                nodes[i+1].frequency = temp.frequency
                nodes[i+1].symbol = temp.symbol

def shannonCode(start,size,nodes):
    gr1 = 0;gr2 = 0; diff1 = 0 ; diff2 = 0 
    if((start+1) == size or (start == size) or (start > size)):
        if((start == size) or (start > size)):
            return
        nodes[size].top += 1
        nodes[size].array[(nodes[size].top)] = 0
        nodes[start].top +=1
        nodes[start].array[(nodes[start].top)] = 1

        return
    
    else:
        for i in range(start,size):
            gr1 = gr1 +  nodes[i].frequency
        gr2 += nodes[size].frequency
        diff1 = gr1 - gr2

        if(diff1 < 0):
            diff1 *= -1
        
        j = 2
        while(j != size - start + 1):
            k = size - j
            gr1 = gr2 = 0

            for i in range(start, k+1):
                gr1 += nodes[i].frequency

            for i in range(size,k,-1):
                gr2 += nodes[i].frequency

            diff2 = gr1 - gr2
            if(diff2 < 0):
                diff2 *= -1
            if(diff2 >= diff1):
                break
            diff1 = diff2
            j+=1
            
        k += 1
        for i in range(start,k+1):
            nodes[i].top += 1
            nodes[i].array[(nodes[i].top)] = 1

        for i in range(k+1,size+1):
            nodes[i].top += 1
            nodes[i].array[(nodes[i].top)] = 0

        shannonCode(start, k, nodes)
        shannonCode(k+1, size, nodes)

def printCodes(nodes, size):
    print("Symbol\t\tFrequency\tCode")
    for i in range(size-1, -1, -1):
        print(nodes[i].symbol, "\t\t" , nodes[i].frequency,"\t\t",end='')
        for j in range(nodes[i].top+1):
            print(nodes[i].array[j], end='')
        print()




nodes = [Node() for _ in range(20)]
letters = ['A','B','C','D','E','F','G','H','I','J','K']
prob = [0.01,0.02,0.15,0.13,0.23,0.09,0.14,0.1,0.07,0.02,0.04]
for i in range(11):
    nodes[i].symbol = letters[i]
    nodes[i].frequency = prob[i]

sortByFrequency(10,nodes)

shannonCode(0,10,nodes)
printCodes(nodes,10)