// #include<stdio.h>
// int main(){
// 	int n;
// 	int cages;
// 	int fight=0;
// 	scanf("%d",&n);
// 	scanf("%d",&cages);
// 	char codes[n][20];
// 	for(int i=0;i<n;i++){
// 		scanf("%s",codes[i]);
// 	}
 
// 	for(int i=0;i<n;i++){
// 		if(codes[i][0]=='?'){
// 			continue;
// 		}
// 		int frequency=1;
// 		for(int j=i+1;j<n;j++){
// 			if(codes[i][0]==codes[j][0] && codes[i][0]!='?'){
// 				frequency++;
// 				codes[j][0]='?';
// 			}
// 		}
// 		if(frequency>cages){
// 			int distributionArray[cages];
// 			for(int k=0;k<cages;k++){
// 				distributionArray[k]=frequency/cages;
// 			}
// 			int iterator=frequency%cages;
// 			for(int k=0;k<iterator;k++){
// 				distributionArray[k]+=1;
// 			}
// 			for(int k=0;k<cages;k++){
// 				fight+= (distributionArray[k] *(distributionArray[k]-1))/2;
// 			}
// 		}
// 	}
// 	printf("%d",fight);
	
 
// 	return 0;
// }


#include <stdio.h>

long long cnt[470];

long long comb(long long x) {
    return x * (x - 1) / 2;
}

int main() {    
  long long n, C;
  scanf("%lld",&n);
  scanf("%lld",&C);
  char s[105];
  for(int i = 0; i < n ; ++i) {
    scanf("%s",s);
    cnt[s[0] - '0']++;
  }
  long long ans = 0;
  for(int i = 0; i <= 300; ++i) {
    long long now = cnt[i];
    long long rem = cnt[i] % C;
    ans += comb(cnt[i] / C) * ((cnt[i]) / C) + comb(cnt[i] / C + 1) * rem;
  }
  printf("%lli", ans);
  return 0;
}