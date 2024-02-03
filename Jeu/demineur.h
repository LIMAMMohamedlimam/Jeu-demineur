#ifndef __DEMINEUR_H_
#define __DEMINEUR_H__

#define M 0
#define fac 8
#define dif 16

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * @file demineur.h
 * @brief Fichier d'en-tête pour l'implémentation du jeu du démineur.
 */

/**
 * @brief Structure représentant une cellule de jeu.
 */
typedef struct {
    bool est_mine; ///< Indique si la cellule contient une mine.
    int nbre_mine_voisin; ///< Nombre de mines voisines.
    bool ete_decouverte; ///< Indique si la cellule a été découverte.
    bool est_marqué_drap; ///< Indique si la cellule est marquée d'un drapeau.
    int case_number; ///< Numéro attribué à la cellule.
} case_de_jeu;

/**
 * @brief Fonction pour afficher le tableau de fin de partie.
 *
 * @param tableau_de_jeu Tableau 2D représentant le plateau de jeu.
 * @param grid Taille du plateau de jeu.
 */
void affichage_fin(case_de_jeu** tableau_de_jeu, int grid);

/**
 * @brief Fonction pour configurer le jeu du démineur.
 *
 * @param tableau_de_jeu Tableau 2D représentant le plateau de jeu.
 * @param grid Taille du plateau de jeu.
 */
void lencement(case_de_jeu** tableau_de_jeu, int grid);

/**
 * @brief Fonction pour initialiser le plateau de jeu.
 *
 * @param tableau_de_jeu Tableau 2D représentant le plateau de jeu.
 * @param grid Taille du plateau de jeu.
 */
void initialisation(case_de_jeu** tableau_de_jeu, int grid);

/**
 * @brief Fonction pour le tour d'un joueur dans le jeu.
 *
 * @param tableau_de_jeu Tableau 2D représentant le plateau de jeu.
 * @param grid Taille du plateau de jeu.
 * @param action Action choisie par le joueur (1 pour découvrir, 2 pour marquer).
 */
void tour_de_jeu(case_de_jeu** tableau_de_jeu, int grid, int action);

/**
 * @brief Fonction pour vérifier si le jeu est terminé.
 *
 * @param tableau_de_jeu Tableau 2D représentant le plateau de jeu.
 * @param grid Taille du plateau de jeu.
 * @return 1 si le jeu est gagné, 0 sinon.
 */
int CheckAvencement(case_de_jeu** tableau_de_jeu, int grid);

/**
 * @brief Fonction pour vérifier si le joueur a gagné le jeu.
 *
 * @param tableau_de_jeu Tableau 2D représentant le plateau de jeu.
 * @param grid Taille du plateau de jeu.
 * @return 1 si le joueur a gagné, 0 sinon.
 */
int win(case_de_jeu** tableau_de_jeu, int grid);

/**
 * @brief Fonction pour afficher le plateau de jeu.
 *
 * @param tableau_de_jeu Tableau 2D représentant le plateau de jeu.
 * @param grid Taille du plateau de jeu.
 */
void affichage(case_de_jeu** tableau_de_jeu, int grid);

/**
 * @brief Fonction pour vérifier si un nombre existe déjà dans un tableau.
 *
 * @param num Nombre à vérifier.
 * @param arr Tableau dans lequel effectuer la vérification.
 * @param size Taille du tableau.
 * @return 0 si le nombre existe déjà, 1 sinon.
 */
int checkNumber(int num, int arr[], int size);

/**
 * @brief Fonction pour obtenir l'action du joueur et le choix de la cellule.
 *
 * @param action Action choisie par le joueur (1 pour découvrir, 2 pour marquer).
 * @param tableau_de_jeu Tableau 2D représentant le plateau de jeu.
 * @param grid Taille du plateau de jeu.
 */
void where_and_play(int action, case_de_jeu** tableau_de_jeu, int grid);

/**
 * @brief Fonction pour afficher les actions disponibles pour le joueur.
 */
void next_move();

#endif  // __DEMINEUR_H__
