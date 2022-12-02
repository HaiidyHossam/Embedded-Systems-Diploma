#include "FIFO.h"

FIFO_Buf_status FIFO_init (FIFO_Buf_t* fifo ,element_type* buf,uint32_t length){
	if(buf==NULL)
		return FIFO_Null;
	fifo->base=buf;
	fifo->head=buf;
	fifo->tail=buf;
	fifo->length=length;
	fifo->count=0;
	
	return FIFO_no_error;
	
}
FIFO_Buf_status FIFO_enqueue (FIFO_Buf_t* fifo ,element_type item){
	if(!fifo->base || !fifo->head ||!fifo->tail )
		return FIFO_Null;
	//fifo is full
	if(FIFO_IS_FULL (fifo) == FIFO_full)
		return FIFO_full;
	
	*(fifo->head)= item;
	fifo->count++;
	//circular fifo
	if(fifo->head == (fifo->base + (fifo->length *sizeof(element_type))))
		fifo->head=fifo->base;
	else
		fifo->head++;
	
	return FIFO_no_error;
	
}
FIFO_Buf_status FIFO_dequeue (FIFO_Buf_t* fifo ,element_type* item){
	if(!fifo->base || !fifo->head ||!fifo->tail )
		return FIFO_Null;
	//check empty
if(fifo->count ==0)
return FIFO_empty;	
*item=*(fifo->tail);
fifo->count--;

//circular fifo
if(fifo->tail == (fifo->base + (fifo->length *sizeof(element_type))))
	fifo->tail=fifo->base;
	else
		fifo->tail++;
	
	return FIFO_no_error;
	

}
FIFO_Buf_status FIFO_IS_FULL (FIFO_Buf_t* fifo){
	if(!fifo->base || !fifo->head ||!fifo->tail )
		return FIFO_Null;
	if(fifo->count==fifo->length)
		return FIFO_full;
	
	return FIFO_no_error;
}
void FIFO_print(FIFO_Buf_t* fifo){
	element_type*temp;
	int i;
	if(fifo->count ==0){
		printf("Fifo is empty \n");
	}
	else{
		temp=fifo->tail;
		printf("\n fifo print \n");
		for(i=0;i<fifo->count;i++){
			printf("%x \n",*temp);
			temp++;
		}
	}
}