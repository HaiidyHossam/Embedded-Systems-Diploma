#include "FIFO.h"


void main(){
FIFO_Buf_t FIFO_UART;
element_type i,temp;
if(	FIFO_init (&FIFO_UART,buff,5)==FIFO_no_error)
	printf("fifo init --- Done \n");
for(i=0;i<5;i++){
		printf("FIFO enqueue: %x \n",i);
	if(	FIFO_enqueue (&FIFO_UART ,i)==FIFO_no_error)
		printf("FIFO enqueue done \n");
	else
		printf("FIFO enqueue failed \n");
	}
FIFO_print(&FIFO_UART);
	if(	FIFO_dequeue (&FIFO_UART ,&temp)==FIFO_no_error)
		printf("FIFO dequeue %x done \n",temp);
	if(	FIFO_dequeue (&FIFO_UART ,&temp)==FIFO_no_error)
		printf("FIFO dequeue %x done \n",temp);
	FIFO_print(&FIFO_UART);
}