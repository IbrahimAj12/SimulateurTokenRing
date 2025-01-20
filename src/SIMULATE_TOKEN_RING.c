#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

struct Semaphore {
    int value;
};

void init_semaphore(struct Semaphore* s, int value) {
    s->value = value;
}


void down(struct Semaphore* s) {
    while (s->value <= 0) {
    }
    s->value--;
}


void up(struct Semaphore* s) {
    s->value++;
}


void simulate_token_ring(int num_nodes) {
    struct Semaphore token;  
    init_semaphore(&token, 1);  
    int current_node = 0;       

    int node_status[num_nodes];  // État des nœuds (1 = actif, 0 = en panne)

    printf("Initialisation des états des nœuds :\n");
    for (int i = 0; i < num_nodes; i++) {
        node_status[i] = rand() % 2;  
        printf("Nœud %d : %s\n", i, node_status[i] ? "Actif" : "En panne");
    }

    while (1) {
        while (node_status[current_node] == 0) {
            printf("Le nœud %d est en panne. On passe au suivant...\n", current_node);
            current_node = (current_node + 1) % num_nodes;
        }
        down(&token);
        printf("Le nœud %d a reçu le jeton\n", current_node);

        printf("Le nœud %d traite ses données\n", current_node);
  
        // Décider aléatoirement si le nœud tombe en panne
        if (rand() % 10 < 2) {  // 20% de chance de panne
            printf("Le nœud %d tombe en panne\n", current_node);
            node_status[current_node] = 0; 
        }

        printf("Le nœud %d passe le jeton\n", current_node);

        current_node = (current_node + 1) % num_nodes;
        up(&token);
    }
}

