import heapq 
  
  
class node: 
    def __init__(self, frequency, symbol, left=None, right=None): 
        # frequencyuency
        self.frequency = frequency 
        # character 
        self.symbol = symbol 
        # left child
        self.left = left 
        # right child
        self.right = right 
        # kod lewo/prawo
        self.huff = '' 
        #operator overload <
    def __lt__(self, nxt): 
        return self.frequency < nxt.frequency 
  
  
# print drzewa
def printNodes(node, val=''): 
  
    # kod obecnego node
    newVal = val + str(node.huff) 
  
    # jeśli node nie jest liściem to ostatni to szukamy dalej
    if(node.left): 
        printNodes(node.left, newVal) 
    if(node.right): 
        printNodes(node.right, newVal) 
  
        #jeśli node jest liściem to wyświetl jego kod
    if(not node.left and not node.right): 
        print(f"{node.symbol} -> {newVal}") 
  
  
# characters
chars = ['a', 'b', 'c', 'd', 'e', 'f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'] 
# frequencies
frequency = [5, 9, 12, 13, 16, 45,23,22,21,32,33,31,17,14,11,7,8,6,4,3,2,1,101,24,29,30] 
# nieużyte node'y
nodes = [] 
  
# konwertowanie list wyżej na node'y w drzewie huffmana
for x in range(len(chars)): 
    heapq.heappush(nodes, node(frequency[x], chars[x])) 
  
while len(nodes) > 1: 
  
    # posortowanie node'ow ze wzgledu na czestotliwosci wystapien
    left = heapq.heappop(nodes) 
    right = heapq.heappop(nodes) 
  
    # przypisz do node odpowiedni value 0 lub 1
    left.huff = 1
    right.huff = 0
  
    # polacz 2 najmniejsze node i stworz jeden ktory ma sume ich czestotliwosci
    newNode = node(left.frequency + right.frequency, left.symbol + right.symbol, left, right) 
  
    heapq.heappush(nodes, newNode) 
  

printNodes(nodes[0]) 