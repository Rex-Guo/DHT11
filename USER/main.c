#include "stm32f4xx.h"
#include "dht.h"
#include "Wait_Clock.h"
#include "usart1.h"


int main(void)
{
	char c[5] = {0};
	Systick_Init();
	DHT11_Init();
	Usart1_Init(115200);
	
	printf("��ʼ���ɹ�����ʼ���ʪ�ȼ��¶ȣ�\r\n");
	
	while(1){
		if(Read_DHT11(c) == 0){
			printf("��ǰʪ��:%d.%d%%RH   �¶�:%d.%d��\r\n\r\n", c[0],c[1],c[2],c[3]);
		}else{
			printf("������\r\n");
		}
		delay_s(2);
	}
	
}
