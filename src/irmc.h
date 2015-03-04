/* Definitions for tone generator */
#define PITCH 650		// frequency of the tone
#define CYCLE (1000000 / PITCH)
#define HALFCYCLE CYCLE / 2

/* Definitions for the hardware wiring */
/* Definition of the hardware interface on the arduino */
#define PIN_KEY PC5 	/* key is connected at PC5(ADC7) */
#define PIN_SPEAKER PD6 /* Use PD6 as speaker output */
#define PIN_LED_CONNECT PD7 /* Status LED ON=connected to irmc */
#define BLINK
#define PIN_LED_DATA PD4

/* Definitions for the CWCom protocol */
#define TXTIME 1000
#define KEYUPTIMEOUT 200
#define STATUSTIMER 3000

#define KEEPALIVE_CYCLE 80000
#define MAXDATASIZE 498

#define DIS 0x0002
#define DAT 0x0003
#define CON 0x0004
#define ACK 0x0005

#define IRMC_VERSION "irmc avr 0.01"

struct cp{
        unsigned short command;
        unsigned short channel;
};

#define LEN_ID 128
#define LEN_STATUS 128
#define LEN_CODE 51
#define SIZE_DP 492
struct dp{
        unsigned short command;
        unsigned short length;
        char id[LEN_ID];
        char a1[4];
        unsigned long sequence;
        unsigned long a21;
        unsigned long a22;
        unsigned long a23;
        signed long code[LEN_CODE];
        unsigned long n;
        char status[LEN_STATUS];  /* This is called version in MorseKob */
        char a4[8];
};

/* Definitions for the IP connection */

struct node{
	unsigned char ipaddr[4];
	unsigned int port;
	unsigned int ch;
	char myid[128];
};

void setnode(struct node *);
