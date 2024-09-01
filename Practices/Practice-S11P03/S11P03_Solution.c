// Solution
// tiles.c
#include <stdio.h>
#include <limits.h>
#define MAX_TILES 20

typedef struct {
    int length;
    int width;
    float perCost;
} tile_t;

int scan_tiles(tile_t []);
float difference(tile_t [], int);

int main(void) {
    tile_t tiles[MAX_TILES];
	int num_tiles;

    num_tiles = scan_tiles(tiles);

	printf("Largest difference = $%.2f\n",
	       difference(tiles, num_tiles));

	return 0;
}

// To read tiles' data into array tiles
// Return the number of tiles read
int scan_tiles(tile_t tiles[]) {
	int num_tiles;

	printf("Enter number of tiles: ");
    scanf("%d", &num_tiles);

	printf("Enter data for %d tiles:\n", num_tiles);
    for (int i = 0; i < num_tiles; i++) {
        scanf("%d", &tiles[i].length);
        scanf("%d", &tiles[i].width);
        scanf("%f", &tiles[i].perCost);
    }

	return num_tiles;
}

// Return the difference in cost between 
// the cheapest tile and the most expensive tile.
float difference(tile_t tiles[], int size) {
    float greatestCost = 0;
    float lowestCost = INT_MAX;
    float currentCost; 

    for (int i = 0; i < size; i++) {
        currentCost = tiles[i].length * tiles[i].width * tiles[i].perCost;

        if (currentCost > greatestCost) {
            greatestCost = currentCost;
        }

        if (currentCost < lowestCost) {
            lowestCost = currentCost;
        }
    }

	return (greatestCost - lowestCost);
}