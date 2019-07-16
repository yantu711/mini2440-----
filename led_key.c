/*作者：wn
 * 时间：2019.7.11
 * 嵌入式学习：用键盘控制LED灯*/

/*配置寄存器地址*/
#define GPBCON (*(volatile unsigned long *) 0x56000010) /*取地址中的数*/
#define GPBDAT (*(volatile unsigned long *) 0x56000014) 
/*#define GPFCON (*(volatile unsigned long *) 0x56000050) 
#define GPFDAT (*(volatile unsigned long *) 0x56000054)*/
#define GPGCON (*(volatile unsigned long *) 0x56000060)
#define GPGDAT (*(volatile unsigned long *) 0x56000064)

/*配置LED1-LED4的端口为输出
 * GPB5 GPB6 GPB7 GOB8*/
#define GPB5_OUT (1<<(5*2))
#define GPB6_OUT (1<<(6*2))
#define GPB7_OUT (1<<(7*2))
#define GPB8_OUT (1<<(8*2))

/*配置K1-K4的端口为输入
 * GPG0 GPG3 GPG5 GPG6*/
#define GPG0_IN ~(3<<(0*2))
#define GPG3_IN ~(3<<(3*2))
#define GPG5_IN ~(3<<(5*2))
#define GPG6_IN ~(3<<(6*2))

int main()
{
    unsigned long dwdata;
    //设置led1-led4为输出
    GPBCON=GPB5_OUT | GPB6_OUT | GPB7_OUT | GPB8_OUT;
    //设置key1-key4为输入
    GPGCON=GPG0_IN & GPG3_IN & GPG5_IN & GPG6_IN;
   // GPFCON=GPF2_IN & GPF0_IN;
    while(1)
    {
    dwdata=GPGDAT;
    if(dwdata & (1<<0))        //KEY1 没有按下led1熄灭，key1按下led1点亮
            GPBDAT |= (1<<5);
    else
	    GPBDAT &= ~(1<<5);
    if(dwdata & (1<<3))         //KEY2 没有按下led2熄灭，key2按下led2点亮
            GPBDAT |= (1<<6);
    else
            GPBDAT &= ~(1<<6);
    
    if(dwdata & (1<<5))        //KEY3 没有按下led3熄灭，key3按下led3点亮
            GPBDAT |= (1<<7);
    else
            GPBDAT &= ~(1<<7);
    if(dwdata & (1<<6))         //KEY4 没有按下led4熄灭，key4按下led4点亮
            GPBDAT |= (1<<8);
    else
            GPBDAT &= ~(1<<8);

    }
       return 0;

}




