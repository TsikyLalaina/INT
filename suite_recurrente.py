# Initialisation des premiers termes
u0 = 1
u1 = -4

# On place les deux premiers termes dans la somme
somme_30 = u0 + u1

# Variables pour la boucle
prev1 = u0
prev2 = u1
current = 0

# Calcul de U2 jusqu'à U70
for i in range(2, 71): # range(2, 71) va de 2 à 70
    current = 2 * prev1 + 3 * prev2
    
    # Calcul de la somme des 30 premiers (de U0 à U29)
    if i < 30:
        somme_30 += current
        
    # Mise à jour des termes pour le prochain tour
    prev1 = prev2
    prev2 = current
    
    # Optionnel : Afficher chaque étape pour comparer avec le C
    print(f"U{i}: {current}")

print("-" * 30)
print(f"La valeur de U70 est : {current}")
print(f"La somme des 30 premiers éléments est : {somme_30}")
