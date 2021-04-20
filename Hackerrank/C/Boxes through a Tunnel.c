#include <stdio.h>


struct box {
	int length, width, height;
};

typedef struct box box;

int get_volume(box b){
	
	return b.length*b.width*b.height;
}

int is_lower_than_max_height(box b){
	if(b.height>=41) return 0;
	else return 1;
}


int main(){
	
	
	int n;
	scanf("%d", &n);
	
	box boxes[n];
	for(int i=0;i<n;i++){
		scanf("%d%d%d", &boxes[i].length, &boxes[i].width, &boxes[i].height);
				
	}
	
	for(int i=0;i<n;i++){
		if(is_lower_than_max_height(boxes[i])){
			printf("%d\n", get_volume(boxes[i]));
		}
	}
	
	return 0;
}
