#include "libasm.h"

int main(void){
    // Différentes chaînes pour les tests
    const char *test_strings[] = {
        "",
        "Hello, World!",
        "This is a longer string to test the function.",
        "Another\nstring with\nnewlines.",
        "1234567890",
        "A very very very very long string just to make sure it works correctly.",
        NULL  // Fin de la liste
    };

    // Itération sur les chaînes de test
    for (int i = 0; test_strings[i] != NULL; i++) {
        const char *str = test_strings[i];
        size_t len_std = strlen(str);       // Longueur avec la fonction standard
        size_t len_ft = ft_strlen(str);     // Longueur avec votre fonction

        // Affichage des résultats
        printf("Test %d: \"%s\"\n", i + 1, str);
        printf("strlen   : %zu\n", len_std);
        printf("ft_strlen: %zu\n", len_ft);

        // Comparaison des résultats
        if (len_std == len_ft) {
            printf("Result: OK\n");
        } else {
            printf("Result: Mismatch!\n");
        }
        printf("--------------------------\n");
    }

    char dest1[100];
    char dest2[100];

    // Itération sur les chaînes de test
    for (int i = 0; test_strings[i] != NULL; i++) {
        const char *str = test_strings[i];

        // Copie avec la fonction standard strcpy
        strcpy(dest1, str);

        // Copie avec votre fonction ft_strcpy
        ft_strcpy(dest2, str);

        // Affichage des résultats
        printf("Test %d: \"%s\"\n", i + 1, str);
        printf("strcpy   : \"%s\"\n", dest1);
        printf("ft_strcpy: \"%s\"\n", dest2);

        // Comparaison des résultats
        if (strcmp(dest1, dest2) == 0) {
            printf("Result: OK\n");
        } else {
            printf("Result: Mismatch!\n");
        }
        printf("--------------------------\n");
    }

    const char *test_cases[][2] = {
        {"", ""},                                // Cas de chaînes vides
        {"Hello", "Hello"},                      // Chaînes égales
        {"Hello", "Hell"},                       // Chaîne 1 plus longue
        {"Hell", "Hello"},                       // Chaîne 2 plus longue
        {"abcd", "abce"},                        // Différence sur le dernier caractère
        {"short", "shorter"},                    // Une chaîne plus longue
        {"This is a test", "This is a test"},    // Chaînes égales plus longues
        {"123", "1234"},                         // Différence de longueur
        {NULL, NULL}                             // Fin des tests
    };

    // Itérer sur les cas de test
    for (int i = 0; test_cases[i][0] != NULL; i++) {
        const char *s1 = test_cases[i][0];
        const char *s2 = test_cases[i][1];

        // Comparaison avec strcmp
        int res_std = strcmp(s1, s2);
        // Comparaison avec votre ft_strcmp
        int res_ft = ft_strcmp(s1, s2);

        // Affichage des résultats
        printf("Test %d: \"%s\" vs \"%s\"\n", i + 1, s1, s2);
        printf("strcmp   : %d\n", res_std);
        printf("ft_strcmp: %d\n", res_ft);

        // Vérification si les résultats sont identiques
        if (res_std == res_ft) {
            printf("Result: OK\n");
        } else {
            printf("Result: Mismatch!\n");
        }
        printf("--------------------------\n");
    }
    return 0;
}