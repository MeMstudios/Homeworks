#include <stdio.h>

void main () {
	int x=3, y, max=100, sum=6, dy=2, dx=2, px=0, py=0, poop=0;
	for (sum; sum<=max; sum+=2) {
		y = sum - x;
		
		while (dy < y) {			
			if (y%dy == 0) {
				x+=2;
				y = sum - x;
				dy=2;
				//px=0;
				while (dx < x) {
					if (x%dx == 0) {
						x+=2;
						y = sum - x;
						dx=2;
						//py=0;
					}
					else {dx++;}
				}
				//px = 1;
			}
			else {dy++;}
		}
		//py = 1;
		
		
		dx=2;				
		dy=2;
		
		
		
		printf("%d = %d + %d\n", sum, x, y);
	}
	
	
	scanf_s("%d", poop);
}