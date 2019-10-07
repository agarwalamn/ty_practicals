import java.util.* ;


class Solution {
    static class Node {
        int data;
        int priority;
        Node next;
    }
    static Node node = new Node();
    static Node newNode(int d, int p)  
    {  
        Node temp = new Node();  
        temp.data = d;  
        temp.priority = p;  
        temp.next = null;  
        
        return temp;  
    }  

    static int peek(Node head)  
    {  
        return (head).data;  
    }  

    static int pop(Node head)  
    {  
        Node temp = head;  
        (head)  = (head).next;  
        return head.data; 
    }  
    static Node push(Node head, int d, int p)  
    {  
        Node start = (head);  
        Node temp = newNode(d, p);  
        if ((head).priority > p) {  
            temp.next = head;  
            (head) = temp;  
        }  
        else {  
            while (start.next != null &&  
                start.next.priority < p) {  
                start = start.next;  
            }   
            temp.next = start.next;  
            start.next = temp;  
        }  
        return head; 
    }  
    static int isEmpty(Node head)  
    {  
        return ((head) == null)?1:0;  
    }  
    public static void main(String args[]) 
    {  
        Node pq[]=new Node[3];
        int count=0;
        Scanner sc = new Scanner(System.in);
        for(int i=0;i<3;i++){
            System.out.println("Enter value and priority of "+i+" queue!");
            while(true){
                if(count==0){
                    pq[i]=newNode(sc.nextInt(), sc.nextInt());
                    count+=1;
                }
                else{
                    pq[i]=push(pq[i],sc.nextInt(), sc.nextInt());
                }
                System.out.println("Do you want to contnue(1/0)");
                if(sc.nextInt()==1){
                    continue;
                }
                count=0;
                break;
            }
        }
        int arr[] =new int[3];
        for(int i=0;i<3;i++){
            if(isEmpty(pq[i])==0){
                arr[i]=pop(pq[i]);
            }
        }
        Arrays.sort(arr);
        System.out.println("Higest value is :"+arr[2]);
       
    }
}
    