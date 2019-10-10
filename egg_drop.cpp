#include <iostream>
#include <limits.h>

//F（N，K）= Min（Max（ F（N-X，K）+ 1， F（X-1，K-1） + 1）），1<=X<=N
using namespace std;

//Compares 2 values and returns the bigger one
int max(int a,int b) {
    int ans=(a>b)?a:b;
    return ans;
}

//Compares 2 values and returns the smaller one
int min(int a,int b){
    int ans=(a<b)?a:b;
    return ans;
}

int egg(int n,int h){

    //Basis case
    //一个鸡蛋,最坏情况下最少尝试h次
    if(n==1) return h;
    //没有楼层,不需要尝试
    if(h==0) return 0;
    //一层一次就够
    if(h==1) return 1;

    int minimum=INT_MAX;

    //从1,2,3...层开始扔,寻找所有最坏情况里的最小值
    for(int x=1;x<=h;x++) minimum=min(minimum,(1+max(egg(n,h-x),egg(n-1,x-1))));

    return minimum;
}
