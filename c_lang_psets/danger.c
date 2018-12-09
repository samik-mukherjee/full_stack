#include <stdio.h>
#include <stdlib.h>
#define A (65)
#define T (84)
#define Esc (27)

void Esc_pressed();
void a_pressed();
void t_pressed();
void switch_a_t(); 
void myvoidfuncion();
void ifelse();
void print_lut();

int main()
{
	puts("press Esc to get out");
	system("stty -icanon -echo");
	switch_a_t();
	t_pressed();
	ifelse();
	print_lut();


	return 0;
}


void switch_a_t()
{
	char input;
	
	
	do
	{
		input = getchar();
		switch(input)
		{
			case 'a':
			printf("A pressed\t\n");
			break;

			case 't':
			printf("T pressed\t\n");
			break;

			case 27:
			system("stty icanon echo");
			exit(0);
		}
	} while(1);
}


void ifelse()
{
	char input;
	do
	{
		input = getchar();
		system("stty -icanon -echo");

		if(input == 'a')
		{
			printf("A pressed\n");	
		}
		if (input == 't')
		{
			printf("T pressed\t");
		}
		if(input == 27)
		{
			system("stty icanon echo");
			exit(0);
		}

	} while(1);

}

void print_lut()
{
	short i = 0;
	char input;
	static void (*pointer_to_function[256])(void);

	while (i < 256)
	{
		pointer_to_function[i] = myvoidfuncion;
		i++;
	}

	pointer_to_function[T] = t_pressed;
	pointer_to_function[A] = a_pressed;
	pointer_to_function[Esc] = Esc_pressed;

	system("stty -icanon -echo");

	do
	{
		input = getchar();
		pointer_to_function[(unsigned)input]();

	} while(1);


}

void myvoidfuncion()
{}

void t_pressed()
{
	printf("T pressed\n");	
}

void a_pressed()
{
	printf("A pressed\n");	
}

void Esc_pressed()
{
	system("stty icanon echo");
	exit(0);
}
