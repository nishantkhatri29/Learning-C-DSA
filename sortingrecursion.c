#include<stdio.h>
int main(){
    int i,j ,a[100],n,temp;
    printf("Enter the no. of elements to be stored in the array");
    printf("\n");
    scanf("%d",&n);
    printf("Enter the Elements\n");
    for ( i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
    for ( i = 1; i < n; i++)
    {
        for ( j =i-1; j > -1 ; j--)
        {
            if (a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
            
        }
        
    }
    printf("Sorted Array is as folows\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    
    return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
void insertion_recursion(int a[100],int n, int low){
    int temp,i;
    if (low>=n)
    {
        return ;
    }
    for ( i = low-1; i>-1; i--)
    {
       if (a[i]>a[i+1])
       {
           temp=a[i];
           a[i]=a[i+1];
           a[i+1]=temp;
       }
       
    }
    insertion_recursion(a,n,low+1);

    

}
int main(){
    int i, n, a[100];
    printf("Enter the no. of elements to be stored in the array");
    printf("\n");
    scanf("%d",&n);
    printf("Enter the Elements\n");
    for ( i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
    insertion_recursion(a,n,1);
    printf("Sorted Array is as folows\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");

}
//Count sort
void count(int a[100],int n,int place ){
    int i;
    int output[n+1];
    int count[10];
    for ( i = 0; i < 10; i++)
    {
        count[i]=0;
    }

    for ( i = 0; i < n; i++)
    {
        count[(a[i]/place)%10]++;
    }

    for ( i = 1; i < 10; i++)
    {
       count[i]=count[i]+count[i-1];
    }
    for ( i = n-1; i >-1; i--)
    {
        output[count[(a[i]/place)%10]-1]=a[i];
        count[(a[i]/place)%10]--;
    }
    
    for ( i = 0; i < n; i++)
    {
        a[i]=output[i];
    }
    
    
    
}

//Radix sort

    void radix_sort(int a[100],int n)
    {
        int i;
        int max=a[0];
        for ( i = 0; i < n; i++)
        {
            if (a[i]>max)
            {
                max=a[i];
            }
            
        }
        for ( int place = 1; max/place>0; place=place*10)
        {
            count(a,n,place);
        }
    }
    int main(){
    int a[100],n,i;
    printf("Enter the numbers to be stored\n");
    scanf("%d",&n);
    printf("enter the value of elements\n");
    for ( i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
    radix_sort(a,n);
    for ( i = 0; i < n; i++)
    {
        printf("%d ",a[i]);
    }
    
    
    return 0;
}
void radic_sort(int a[100],int n){
    int place;
    int max,i;
    for ( i = 0; i < n; i++)
        {
            if (a[i]>max)
            {
                max=a[i];
            }
            
        }
        for ( place = 1; max/place >0; place=place*10)
        {
        count(a,n,place);
        }
        

}
void count(int a[100],int n,int place){
    int count[10],i;
    int output[n];
    for ( i = 0; i < 10; i++)
    {
       count[i]=0;
    }
    for ( i = 0; i < n; i++)
    {
        count[(a[i]/place)%10]++;
    }
    for ( i = 1; i < 10; i++)
    {
        count[i]=count[i]+count[i-1];
    }
    for ( i = n-1; i >-1; i--)
    {
        output[count[(a[i]/place)%10]-1]=a[i];
    }
    
    

}