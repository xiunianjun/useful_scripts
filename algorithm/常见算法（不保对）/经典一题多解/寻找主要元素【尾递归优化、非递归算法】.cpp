#include<stdio.h>
#include<stdlib.h>
#define INF 1000
//非递归 
//思想解析
//	https://blog.csdn.net/zdavb/article/details/48675869?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522164154601216780265483024%2522%252C%2522scm%2522%253A%252220140713.130102334..%2522%257D&request_id=164154601216780265483024&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~sobaiduend~default-1-48675869.pc_search_insert_es_download&utm_term=%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84%E4%B8%8E%E7%AE%97%E6%B3%95%E5%88%86%E6%9E%902.19&spm=1018.2226.3001.4187 
//可以当作把主要元素和其他元素摞成两堆，相同则累加，不相同消除
//但对于整体来说，其实访问到一个就算是消除一个
//由于主要元素较多，故最后剩下的一定是主要元素 
int majorityElement(int* nums, int numsSize){
    int candidate=nums[0];
    int count=0;
    for(int i=0;i<numsSize;i++){
        if(count==0){
            candidate=nums[i];
        }
        if(candidate==nums[i])  count++;
        else    count--;
    }
    return candidate;
}
//分治 
//int FindMajor(int* nums,int numsSize,int left,int right){
//    if(numsSize==1) return nums[left];
//    int center=(left+right)/2;
//    int majorLeft=FindMajor(nums,center-left+1,left,center);
//    int majorRight=FindMajor(nums,right-center,center+1,right);
//    if(majorLeft==majorRight)   return majorRight;
//    else{
//        int countLeft=0,countRight=0;
//        for(int i=center;i>=left;i--){
//            if(nums[i]==majorLeft)  countLeft++;
//        }
//        for(int i=center+1;i<=right;i++){
//            if(nums[i]==majorRight) countRight++;
//        }
//        if(countLeft>countRight)    return majorLeft;
//        else    return majorRight;
//    }
//}


//尾递归优化 1
//int FindMayBeV2(int *a,int n){
//	start:
//	if(n==0){
//		return -INF;
//		//TODO
//	}
//	if(n==1){
//		return a[0];
//		//TODO
//	}
//	int *b=(int*)malloc(sizeof(n/2+1));
//	int count=0;
//	for(int i=0;i<n/2*2-1;i+=2){
//		if(a[i]==a[i+1]){
//			b[count]=a[i];
//			count++;
//			//TODO
//		}
//		//TODO
//	}
//	//如果n为奇数且找不到候选元，则返回最后那玩意 
//	if(n%2!=0){
//		if(FindMayBeV2(b,count)==-INF){
//			return a[n-1];
//			//TODO
//		}
//		//TODO
//	}
//	a=b;
//	n=count;
//	goto start;
//}
//尾递归优化2 
int FindMayBeV2(int *a,int n){
	while(1){
		if(n==0){
			return -INF;
			//TODO
		}
		if(n==1){
			return a[0];
			//TODO
		}
		int *b=(int*)malloc(sizeof(n/2+1));
		int count=0;
		for(int i=0;i<n/2*2-1;i+=2){
			if(a[i]==a[i+1]){
				b[count]=a[i];
				count++;
				//TODO
			}
			//TODO
		}
		//如果n为奇数且找不到候选元，则返回最后那玩意 
		if(n%2!=0){
			if(FindMayBeV2(b,count)==-INF){
				return a[n-1];
				//TODO
			}
			//TODO
		}
		a=b;
		n=count;
	}
}

int main() {
	int a[]={3,3,4,2,4,4,2,4,4};
	int n=sizeof(a)/sizeof(a[0]);
	int result1=majorityElement(a,n);
	int count=0;
	for(int i=0;i<n;i++){
		if(a[i]==result1){
			count++;
			//TODO
		} 
	}
	if(count>=n/2+1){
		printf("%d\n",result1); 
		//TODO
	}
	else{
		printf("Can't find it!\n");
	}
	int result2=FindMayBeV2(a,n);
	if(result2!=-INF){
		printf("%d\n",result2);
		//TODO
	}
	else{
		printf("Can't find it!\n");
	}
	return 0;
}
