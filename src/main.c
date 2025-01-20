int main() {
    int num_nodes;

    
    srand(time(NULL));

   
    printf("Entrez le nombre de nœuds dans le réseau (max 10) : ");
    scanf("%d", &num_nodes);

    if (num_nodes <= 0 || num_nodes > 10) {
        printf("Nombre de nœuds invalide\n");
        return 1;
    }

   
    simulate_token_ring(num_nodes);

    return 0;
}
