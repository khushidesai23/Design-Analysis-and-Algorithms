//KHUSHI DESAI

import java.util.*;
class add
{
    public static void main(String args[])
    {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the number of elements in the first list");
        int n=sc.nextInt();
        System.out.println("Enter the number of elements in the second list");
        int m=sc.nextInt();
        System.out.println("Enter the elements of the first list");
        LinkedList<Integer> l1=new LinkedList<Integer>();
        for(int i=0;i<n;i++)
        {
            l1.add(sc.nextInt());
        }
        System.out.println("Enter the elements of the second list");
        LinkedList<Integer> l2=new LinkedList<Integer>();
        for(int i=0;i<m;i++)
        {
            l2.add(sc.nextInt());
        }
        LinkedList<Integer> l3=new LinkedList<Integer>();
        int carry=0;
        int i=n-1;
        int j=m-1;
        while(i>=0 && j>=0)
        {
            int sum=l1.get(i)+l2.get(j)+carry;
            l3.addFirst(sum%10);
            carry=sum/10;
            i--;
            j--;
        }
        while(i>=0)
        {
            int sum=l1.get(i)+carry;
            l3.addFirst(sum%10);
            carry=sum/10;
            i--;
        }
        while(j>=0)
        {
            int sum=l2.get(j)+carry;
            l3.addFirst(sum%10);
            carry=sum/10;
            j--;
        }
        if(carry!=0)
        {
            l3.addFirst(carry);
        }
        System.out.println("The sum of the two lists is");
        for(int k=0;k<l3.size();k++)
        {
            System.out.print(l3.get(k)+" ");
        }
    }
}

