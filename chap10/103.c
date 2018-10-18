#include <stdio.h>
#include <stdlib.h>

int search(int Ary[],int left, int right, int target){

    int mid=(left+right)/2;
    if(target==Ary[mid]){
        return mid;
    }
    if(right<left){
        return -1;
    }

    /* 左または右半分のいずれかは普通の並び順
     * どちらの並びの半分が普通の並び順になっているかをみつけ、
     * それを用いてxがどちらの半分にあるかを判定する */
    if(Ary[left]<Ary[mid]){ // 左半分が普通の並び順となっている
        if(target >= Ary[left] && target < Ary[mid]){
            return(search(Ary,left,mid-1,target)); // 右半分を探す
        }else{
            return(search(Ary,mid+1,right,target)); //左半分を探す
        }
    }else if(Ary[mid]<Ary[left]){ // 右半分が普通の並び順になっている
        if(target >= Ary[mid] && target < Ary[right]){
            return(search(Ary,mid+1,right,target)); //右半分を探す
        }else{
            return(search(Ary,left,mid-1,target)); // 左半分を探す
        }
    }else if(Ary[left]==Ary[mid]){i // 左端もしくは右端が中央が同じ値の場合
        if(Ary[mid] != Ary[right]){ //右橋と異なる場合、右半分を調べる
            return search(Ary, mid+1, right,target); //右半分を調べる
        }else{ // 右、左端が中央と同じ値の場合、両方調べる必要がある。
            int result = search(Ary,left,mid-1,target); // 左半分を探す
            if(result == -1){
                return search(Ary,mid+1,right,target);//右半分を探す
            }else{
                return result;
            }
        }
    }

    return -1;
}

int main(void){
    int Ary[] = {15,16,19,20,25,1,3,4,5,7,10,14};
    int index = sizeof(Ary)/sizeof(Ary[0])-1;
    int target = 5;
    int i,output;

    printf("Input: find %d in { ",target);
    for(i=0;i<=index;i++){
        printf("%d ",Ary[i]);
    }
    printf("}\n");

    output = search(Ary,0,index,target);
    printf("Output: %d\n",output);

    return 0;
}
