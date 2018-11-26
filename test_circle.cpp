/* small program which testing if a point is inside a circle 
	below condition need to be met: 
	(x-x0)^2 + (y-y0)^2 <= r^2
	where; x & y = coordinates of a random point
	x0 & y0 = coordinates of a centre of a circle
	r = radius of a circle
*/
#include <iostream>
#include <cmath>
#include <omp.h>


bool  IsInCircle(int x, int y, int x0, int y0, int R)
{  
	int dx = abs(x - x0);
	if (dx > R) return false; 
	int dy = abs(y - y0);
	if (dy >  R) return false;
	if (dx + dy <= R) return true;
	return (dx*dx + dy*dy <= R*R);
}



int main()
{
    // get number of processors in this system
	int threads = omp_get_num_procs();
    // set the number of threads
	omp_set_num_threads(threads);

	int x, y, x0, y0, R;
    // x0, y0 in the range 0 to 99
	x0 = rand() % 100; y0 = rand() % 100; R = 1;
	// n = counter & N = condition value
	int n = 0; int N = 100000;
	// parallel for loop
	#pragma omp parallel for
	for (int i = 0; i < N; i++)
	{
		// x, y in the range 0 to 99
		x = rand() % 100; y = rand() % 100;
		   if ( IsInCircle(x,y,x0,y0,R)  )
		{
		   n++;
		}
	}
	printf("%d points of %d inside circle\n", n, N);
	system("pause");
	return(0);
}