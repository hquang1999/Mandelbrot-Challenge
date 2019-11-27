#include <iostream>
extern "C"
{
	#include "gfx.h"
}

int main()
{
	gfx_open(1000, 1000, "Acid Trip");
	
	for (int x = 0; x < 1000; x++)
	{
		for (int y = 0; y < 1000; y++)
		{
			float zoom = 0.0038; // shifting in coordinate plane
			
			float a = 0;
			a = ((x - 600) * zoom); //modified by Nigel
			
			float b = 0;
			b = ((y - 500) * zoom); //modified by Nigel
		
			float A = a; // previous copies
			float B = b;

			int n = 0;
			while (n < 1000)
			{
				float real = (a * a) - (b * b); // computing reals 
				float imag = (2 * a * b); // computing i

				a = real + A;
				b = imag + B;

				if (((a * a) + (b * b)) > 16.0)
				{
					break;
				}
				n++;
			}
				
			double red = n * n * n % 256; 
			double green = n % 256; 
			double blue = n * 256; 
		
			gfx_color(red, green, blue);
			gfx_point(x,y);
		}
	}
	
	std::cout << "X to ESCAPE" << std::endl;

	while (true)
	{
		if (gfx_event_waiting())
		{
			int button = gfx_wait();
			if (button == 'x')
			{
				break;
			} 	
		}
	}

	return 0;
}
               
