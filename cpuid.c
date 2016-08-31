	#include <stdio.h>
	#include <string.h>

	int a;
	int b;
	int c;
	int d;

	void main(void){
		a = 0;
		b = 0;
		c = 0;
		d = 0;
	

		asm(".intel_syntax noprefix");
		asm("mov %eax,0");
		asm("CPUID");
		asm("mov b,%ebx");
		asm("mov c,%ecx");
		asm("mov d,%edx");
		asm(".att_syntax noprefix");

	
	    char vendor[sizeof(int) * 3]; 
	    strncpy(vendor, (const char*) &b, sizeof(int));
	    strncpy(&vendor[8], (const char*) &c, sizeof(int));
	    strncpy(&vendor[4], (const char*) &d, sizeof(int));
	   

	    printf("CPU: %s\n", vendor);


	}


