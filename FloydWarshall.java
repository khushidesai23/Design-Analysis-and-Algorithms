import java.lang.Math.*;
import java.util.Arrays;
import java.util.Scanner;
public class FloydWarshall {
    int min(int y, int z){
        int w = z;
        if (y<z){
            w = y;
        }
        return w;
    }
    public void fw(int a[][]){
        for(int k=0; k<a.length; k++){
            for(int i=0; i<a.length; i++){
                for(int j=0; j<a.length; j++){
                    if(a[i][k]!=Integer.MAX_VALUE && a[k][j]!=Integer.MAX_VALUE){
                   a[i][j]=min(a[i][j], (a[i][k]+a[k][j]));
                    }
                }
            }
        }
    }
    public void display(int[][] c){
        if (c==null){
            System.out.print("null"+Arrays.deepToString(c));
        }
        System.out.print("[");
        for (int i=0; i<c.length; i++){
            if(i != 0){
                System.out.print(" ");
            }
            for (int j=0; j<c[0].length; j++){
                if(c[i][j] != Integer.MAX_VALUE){
                System.out.print(c[i][j]);
                }
                if(c[i][j] == Integer.MAX_VALUE){
                System.out.print("INF");
                }
                if (j != c[0].length-1){
                    System.out.print("     ");
                }
        }
        if(i!= (c.length-1)){
            System.out.print("\n");
        }   
        }
        System.out.print("]");
        System.out.print("\n");
        System.out.print("\n");
    }
    public static void main(String[] args) {
        Scanner x = new Scanner(System.in);
        System.out.print("Enter number of vertices: ");
        int n = x.nextInt();
        int edges[][]= new int[n][n];
        
        System.out.print("Enter number of edges: ");
        int e = x.nextInt();
        for (int i=0; i<e; i++){
        System.out.print("Enter source of edge "+(i+1)+" : ");
        int s = x.nextInt();
        System.out.print("Enter destination of edge "+(i+1)+" : ");
        int d = x.nextInt();
        System.out.print("Enter weight of edge "+(i+1)+" : ");
        edges [s][d] = x.nextInt();
        }
        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                if (edges[i][j] == 0){
                    edges[i][j] = Integer.MAX_VALUE;
                }
                if (i==j){
                    edges[i][j]=0;
            }
        }  
    }
    FloydWarshall obj = new FloydWarshall();
    obj.display(edges);
    obj.fw(edges);
    obj.display(edges);
    }
    
}