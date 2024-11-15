#include <stdio.h>

typedef struct Box{
	int weight;
	struct Box **nestedBox;
	int numofnestedBoxes;
} Box;

int totalWeight(Box *box){
	int totalweight = box->weight;
	for(int i = 0; i < box->numofnestedBoxes ; i++ ){
		totalweight += totalWeight(box->nestedBox[i]);
	}
	return totalweight;
}

Box* createBox(int weight, int numofnestedBoxes){
	Box *newBox = (Box*)malloc(sizeof(Box));
	newBox->weight = weight;
	newBox->numofnestedBoxes = numofnestedBoxes;
	newBox->nestedBox = (Box**)malloc(numofnestedBoxes * sizeof(Box*));
	return newBox;
}

int main(){
	
	Box *box1 = createBox(15, 0);
	Box *box2 = createBox(20, 1);
	Box *box3 = createBox(30, 2);
	box2->nestedBox[0] = box1;
	box3->nestedBox[0] = box1;
	box3->nestedBox[1] = box2;
	int weight = totalWeight(box3);
	printf("Total weight of the box is : %d", weight);
	free(box1->nestedBox);
	free(box1);
	free(box2->nestedBox);
	free(box3->nestedBox);
	free(box3);
	
	return 0;
}