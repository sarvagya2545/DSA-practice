#include <stdio.h>
#include <string.h>
int count = 0;

int fd(int sum, int a) {
	count++;
	return sum + a;
}

int loop(int sum, int mul) {
	int answer = 0;
	count++;

	while(1) {
		char str[5];

		scanf("%s", str);

		if(strcmp(str, "FD") == 0) {
			int a;
			scanf("%d", &a);
			answer = fd(answer, a);
		} else if(strcmp(str, "LOOP") == 0) {
			int a;
			scanf("%d", &a);
			answer = loop(answer, a);
		} else {
			count++;
			break;
		}
	}

	return sum + answer * mul;
}

int main() {
	int N;
	int ans = 0;
  scanf("%d", &N);

  while(count != N) {
		char str[5];
		scanf("%s", str);

		if(strcmp("FD", str) == 0) {
			int a;
			scanf("%d", &a);
			ans = fd(ans, a);
		}

		if(strcmp("LOOP", str) == 0) {
			int mul;
			scanf("%d", &mul);
			ans = loop(ans, mul);
		}

		if(count == N) {
			break;
		}
	}

	printf("%d", ans);
}