import java.util.Scanner;
 import java.io.*;
 class operation
 {
int x[]=new int[20];
int count=0;
public boolean place(int row,int column)
{
int i;
for(i=1;i<=row-1;i++)
{ 
if(x[i] == column)
return false;
else
if (Math.abs(x[i]-column)== Math.abs(i-row))
return false;
}
return true;
}
public void Queen(int row,int n)
{
int column;
for(column=1;column<=n;column++)
{
if(place(row,column))
{
x[row] = column;
if(row==n)
{
print_board(n); 
}
else 
Queen(row+1,n);
}
}
}
public void print_board(int n)
{
int i;
System.out.println("\n\nSolution :"+(++count));
for(i=1;i<=n;i++)
{
System.out.print(" " +i);
}
for(i=1;i<=n;i++)
{
System.out.print("\n\n"+i);
for(int j=1;j<=n;j++)
{
if(x[i]==j)
System.out.print(" Q");
else
System.out.print(" -");
} 
}
}
}
class NQueens
{
public static void main (String args[] )throws IOException
{
 Scanner scanner = new Scanner(System.in);
 System.out.print("Enter the size of the chessboard (N): ");
 int n = scanner.nextInt();
 if(n==2 || n==3)
 {
 System.out.print("Not Possible");
}
scanner.close();
 operation op=new operation();
 op.Queen(1,n);
}
}