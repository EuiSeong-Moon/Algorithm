#include <stdio.h>

long long data[100001];
long long sumData[100001];
int main (void) {
    int N,M,buf,start,end;
    scanf("%d",&N);
    scanf("%d",&M);

    scanf("%d",&buf);
    sumData[0]=buf;

    for (int i=1;i<N;i++) {
        scanf("%d",&buf);
        data[i]=buf;
        sumData[i]=data[i]+sumData[i-1];
    }

    for (int i=0;i<M;i++){
        scanf("%d %d",&start,&end);

        if(start == 1) {
            printf("%d\n",sumData[end-1]);
        } else {
            printf("%d\n",sumData[end-1]-sumData[start-2]);
        }
    }
    return 0;
}