# include<stdio.h>
# define INF 99999
int main(){
int n;
int a[10][10];
printf("Enter the no of vertices");
scanf("%d",&n);
for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
            scanf("%d",&a[i][j]);
            if(a[i][j]==0){
                a[i][j]=0;
            }
    }
}
for(int k=0;k<n;k++){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(a[i][j]>a[i][k]+a[k][j]){

                a[i][j]=a[i][k]+a[k][j];
            }
        }
    }
}
for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        if(a[i][j]==INF){
            printf("INF");
        }else{
            printf("%d",a[i][j]);
        }
    }
    printf("\n");
}
for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
            if(i!=j){
                printf("%d-%d==%d",i,j,a[i][j]);
            }
    }
}
}
