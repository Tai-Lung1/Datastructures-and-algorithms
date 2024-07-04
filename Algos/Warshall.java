<<<<<<< HEAD
package Algos;
import java.util.Scanner;
public class Warshall
{
void warshall(int[][] w,int n)
{
int i,j,k; 
for(k=1;k<=n;k++)
for(i=1;i<=n;i++)
for(j=1;j<=n;j++)
if(w[i][k]==1&&w[k][j]==1)
{
 w[i][j]=1;
}
else
{
 w[i][j]=w[i][j];
}
}
public static void main(String[] args)
{
int a[][]=new int[10][10];
int n,i,j;
System.out.println("Enter the number of vertices");
Scanner sc=new Scanner(System.in);
n=sc.nextInt();
System.out.println("Enter the adjacency matrix of a digraph");
for(i=1;i<=n;i++)
for(j=1;j<=n;j++)
a[i][j]=sc.nextInt();
Warshall f=new Warshall();
f.warshall(a, n);
System.out.println("The transitive closure of the digraph is");
for(i=1;i<=n;i++)
{
for(j=1;j<=n;j++)
{
System.out.print(a[i][j]+" ");
}
System.out.println();
}
sc.close();
}
=======
import java.util.Scanner;
public class Warshall
{
void warshall(int[][] w,int n)
{
int i,j,k; 
for(k=1;k<=n;k++)
for(i=1;i<=n;i++)
for(j=1;j<=n;j++)
if(w[i][k]==1&&w[k][j]==1)
{
 w[i][j]=1;
}
else
{
 w[i][j]=w[i][j];
}
}
public static void main(String[] args)
{
int a[][]=new int[10][10];
int n,i,j;
System.out.println("Enter the number of vertices");
Scanner sc=new Scanner(System.in);
n=sc.nextInt();
System.out.println("Enter the adjacency matrix of a digraph");
for(i=1;i<=n;i++)
for(j=1;j<=n;j++)
a[i][j]=sc.nextInt();
Warshall f=new Warshall();
f.warshall(a, n);
System.out.println("The transitive closure of the digraph is");
for(i=1;i<=n;i++)
{
for(j=1;j<=n;j++)
{
System.out.print(a[i][j]+" ");
}
System.out.println();
}
sc.close();
}
>>>>>>> da1cbb7eab4957e31ed45da215807bc00d3fd62e
}