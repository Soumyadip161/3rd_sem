
public class fibo2{
    static int complexity=0;
    int fibo(int n1,int a,int b)
    {
        //complexity++;
        if(n1==0)
        {
            complexity+=2;
            return a;
            
        }
        else if(n1==1){
            complexity+=2;
            return  b;
        }
            else{
                complexity+=1;
            return fibo(n1-1,b,a+b);
            }
    }
    void print_fibo(int n)
    {
        complexity++;
      for(int i=0;i<n;i++)
      {
        int a=0;int b=1;
        System.out.print(fibo(i,a,b)+"\t");
        complexity+=4;
      }
    }
    public static void main(String args[])
    {
        
         fibo2 fb=new fibo2();
         
         fb.print_fibo(5);
         
         System.out.println();
         
         System.out.println("Time complexity="+complexity+"\t");
    }
}
