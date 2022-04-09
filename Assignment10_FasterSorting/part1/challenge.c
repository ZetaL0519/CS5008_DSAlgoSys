#include <stdio.h>

// Modify this function
void merge(int* nums1, int m, int* nums2, int n){
	if (m == 0) {
		nums1 = nums2;
		return;
	}

	int nums3[m];

	int i;
	for (i = 0; i < m; i ++) {
		nums3[i] = nums1[i];
	}

	int p1 = 0, p2 = 0;
	int p;
	for (p = 0; p < m + n; p ++){
		if (p2 >= n || p1 < m && nums3[p1] < nums2[p2]){
			nums1[p] = nums3[p1 ++];
		} else {
			nums1[p] = nums2[p2 ++];
		}
	}
}


void printArray(int* array, unsigned int size){
	unsigned int i;
	for (i = 0; i < size; i ++){
		printf("%d", array[i]);
	}
	printf("\n");
}

int main(){
	int nums1[] = {1,2,3,0,0,0};
	int nums2[] = {2,5,6};

	merge(nums1, 3, nums2, 3);
	
	printArray(nums1, 6);
	return 0;  
}
