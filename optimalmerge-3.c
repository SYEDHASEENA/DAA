#include <stdio.h>
#include <stdlib.h>

int merge(int arr[],int n){
int cost=0;

 int i;
 while(n>1){
        int min1=0;
 int min2=1;
    if(arr[min1]>arr[min2]){
      min2 = 0;
      min1=1;
    }
    for(i=2;i<n;i++){
        if(arr[min1]>arr[i]){
          min2  =min1;
          min1=i;
        }
        else if(arr[min2]>arr[i]){
            min2=i;
        }
    }



cost+=arr[min1]+arr[min2];
arr[min1]+=arr[min2];
arr[min2]=arr[--n];
 }
return cost;
}
void main(){
    int a[10],s,i;
printf("enter no of files:");
scanf("%d",&s);
for(i=0;i<s;i++){
scanf("%d",&a[i]);
}
printf("%d",merge(a,s));
}
