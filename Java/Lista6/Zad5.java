class Stack{
    int capacity;
    int data[];
    int currSize;
    public Stack(int size){
        capacity = size;
        currSize = 0;
        data = new int[size];
    }
    protected boolean isFull(){
        if(capacity == 0)
            return true;
        else
            return false;
    }
    public void push(int item){
        if(isFull())
            return;

        else{
            ++currSize;
            data[currSize] = item;
        }
    }

    public int peek(){
        return data[currSize];
    }

    public int pop(){
        return data[currSize--];
    }
}

public class Zad5 {
    public static void main(String[] args) {
        Stack s = new Stack(10);
        s.push(5);
        s.push(10);
        System.out.println(s.peek());
    }
}
