// tiles.c
#include <stdio.h>
#define MAX_TILES 20

int scan_tiles(tile_t []);
float difference(tile_t [], int);

int main(void) {
	tile_t tiles[MAX_TILES];
	int num_tiles;

	printf("Largest difference = $%.2f\n",
	       difference(tiles, num_tiles));

	return 0;
}

// To read tiles' data into array tiles
// Return the number of tiles read
int scan_tiles(tile_t tiles[]) {
	int num_tiles;

	printf("Enter number of tiles: ");

	printf("Enter data for %d tiles:\n", num_tiles);

	return 20;
}

// Return the difference in cost between 
// the cheapest tile and the most expensive tile.
float difference(tile_t tiles[], int size) {

	return 1.5;
}

