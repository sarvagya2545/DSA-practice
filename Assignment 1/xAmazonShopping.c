#include <stdio.h>
#include<math.h>

int m;
int n;
int a[25];
int count=0;

int i, j;

 
void grayCode(int N) {
    int grayCode[(int) pow(2, N)];
    int binary[(int) pow(2, N)];
 
    for (i = 0; i < pow(2, N); i++)
        grayCode[i] = (i >> 1) ^ i;
 
    for (i = 0; i < pow(2, N); i++) {
        int b = 1;
        binary[i] = 0;
        while (grayCode[i] > 0) {
            binary[i] += (grayCode[i] % 2) * b;
            grayCode[i] /= 2;
            b = b * 10;
        }
    }
    int sm=0;
    
    
    for (i = 0; i < pow(2, N); i++) {
       sm=0;
       int kk=0;
        for (j = 0; j < N; j++) {
            if (binary[i] % 10 == 1){
                sm+=a[j];
                kk++;
            }
            binary[i] /= 10;
        }
        
        if(sm<=m){
            if(kk>count){
                count=kk;
                
            }
        }
        
    }
}
 


int main()
{
    
    
    scanf("%d",&m);
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&(a[i]));
    }
     
    
 
    int mask[(int) pow(2, n)];
    grayCode(n);
    
    
   printf("%d",count);
   
    
    
    

    return 0;
}