#include <stdio.h>

typedef struct {
    float X;
    float Y;
} Ponto;

float calcularArea(Ponto *vertices, int n) {
    float area = 0.0;

    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n; 
        area += (vertices[i].X * vertices[j].Y) - (vertices[j].X * vertices[i].Y);
    }

    area = 0.5 * area;
    if (area < 0) {
        area = -area; 
    }

    return area;
}
int main() {
    int n;
    FILE *arquivo;
    
    
    arquivo = fopen("vertices.txt", "r");
    
    if (arquivo == NULL) {
        printf("Não foi possível abrir o arquivo.\n");
        return 1;
    }
    fscanf(arquivo, "%d", &n); 
    
    Ponto vertices[n];
       
    for (int i = 0; i < n; i++) {
        fscanf(arquivo, "%f %f", &vertices[i].X, &vertices[i].Y);
    }
    
    fclose(arquivo); 
    
    float area = calcularArea(vertices, n);
    
    printf("A área do polígono é %.2f\n", area);
    
    return 0;
}
