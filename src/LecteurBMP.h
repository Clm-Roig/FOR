#ifndef DEF_LecteurBMP
#define DEF_LecteurBMP

// EN-TETE ReconnaissanceV.h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

// ---- CONSTANTES ---- //
const char* CHEMIN_IMAGES_ALIMENTS = "data/images_aliments/";

// ---- STRUCTURE ---- //
/** @struct ImageBMP
 *  @brief Structure définissant une image au format Bitmap
 *  @var Couleur** couleurs, l'image représentée par un tableau de pixels R-G-B (objet Couleur)
 *  @var int taille_image, la taille de l'image (sans l'en-tête)
 *  @var int taille_fichier, la taille totale du fichier
 *  @var unsigned char* entete, l'en-tête du fichier bitmap
 */
typedef struct ImageBMP {
    Couleur** couleurs;
    int taille_image;
    int taille_fichier;
    int largeur;
    int hauteur;
    unsigned char* entete;
} ImageBMP;

// ---- FONCTIONS ---- //

/**
	@brief Constructeur de ImageBMP
	@param FILE* fichier, le fichier .bmp que l'on veut transformer en ImageBMP
	@return ImageBMP*
*/
ImageBMP* initImageBMP(FILE* fichier);

/**
	@brief Destructeur de ImageBMP (libère mémoire)
	@param ImageBMP* image, l'image à détruire
*/
void destroyImageBMP(ImageBMP* image);

// STRUCTURE D'UN FICHIER BITMAP : http://sitelec.org/cours/abati/bmp.htm
/**
	@brief Récupère l'en-tête d'un fichier .bmp
	@param FILE* image, l'image à charger
	@return un tableau de char contenant l'en-tête du fichier
*/
unsigned char* getEnTete(FILE* image);

/**
	@brief Renseigne sur la largeur de l'image
	@param FILE* image, l'image à analyser
	@return bool, 1 si l'image a une largeur (en pxl) multiple de 4, sinon 0
*/
int getLargeurBMP(FILE* image);

/**
	@brief Retourne la taille de l'image
	@param FILE* image, l'image à analyser
	@return long, la taille de l'image
*/
long getTailleImage(FILE* image);

/**
	@brief Retourne la taille du fichier BMP
	@param FILE* image, l'image à analyser
	@return long, la taille du fichier BMP
*/
long getTailleFichier(FILE* image);

/**
	@brief Charge les données d'une image BITMAP (.bmp) dans un tableau de Couleurs
	@param FILE* image, l'image à charger
	@return Couleur**, un tableau de Couleur* représentant l'image pixel par pixel
*/
Couleur** getDonnees(FILE* image);


#endif
