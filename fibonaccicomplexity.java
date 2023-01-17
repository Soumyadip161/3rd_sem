public class fibonacci{
    static int complexity=0;
    int fibo(int n1,int a,int b)
    {
        //complexity++;
        if(n1==0||n1==1)
        {
            complexity+=2;
            return 0;
            
        }
        System.out.print((a+b)+"\t");
        complexity++;
       
            complexity+=1;
            return fibo(n1-1,b,a+b);
        
    }
    void print_fibo(int n)
    {
        System.out.print(0+"\t"+1+"\t");
    
        complexity+=1;
        fibo(n,0,1);

    }
    public static void main(String args[])
    {
        
         fibonacci fb=new fibonacci();
         
         fb.print_fibo(5);
         
         System.out.println();
         
         System.out.println("Time complexity="+complexity+"\t");
    }
}
