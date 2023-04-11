#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 20

int graph[MAX_VERTICES][MAX_VERTICES];
int colors[MAX_VERTICES];
int num_vertices, num_colors, chromatic_num = 0, solution_count = 0;

int is_safe(int v, int c) {
    for (int i = 0; i < num_vertices; i++) {
        if (graph[v][i] && colors[i] == c) {
            return 0;
        }
    }
    return 1;
}

void graph_color(int v) {
    if (v == num_vertices) {
        // found a solution
        solution_count++;
        printf("Solution %d: ", solution_count);
        for (int i = 0; i < num_vertices; i++) {
            printf("Vertex %d: Color %d  ", i, colors[i]);
        }
        printf("\n");

        // update chromatic number
        int max_color = 0;
        for (int i = 0; i < num_vertices; i++) {
            if (colors[i] > max_color) {
                max_color = colors[i];
            }
        }
        if (max_color < chromatic_num || chromatic_num == 0) {
            chromatic_num = max_color;
        }
        return;
    }
    for (int c = 1; c <= num_colors; c++) {
        if (is_safe(v, c)) {
            colors[v] = c;
            graph_color(v + 1);
            colors[v] = 0;
        }
    }
}

int main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &num_vertices);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter the maximum number of colors: ");
    scanf("%d", &num_colors);

    graph_color(0);

    if (solution_count == 0) {
        printf("No solutions found.\n");
    } else {
        printf("Chromatic number: %d\n", chromatic_num);
    }

    return 0;
}
