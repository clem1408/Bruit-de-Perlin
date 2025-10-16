#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>

#define NB_PARAM 2

using namespace std;


int main(int argc, char* argv[]) {

    if(argc != NB_PARAM +1){
        cerr << "Paramètre : taille iamge w & h" << endl;
        exit(EXIT_FAILURE);
    }

    int img_width=1, img_height=1;
    int grid_width=2, grid_height=2;

    img_width = atoi(argv[1]);
    img_height = atoi(argv[2]);

    grid_width = img_width +1;
    grid_height = img_height +1;

    // Création image
    cv::Mat img(img_width, img_height, CV_8UC1, cv::Scalar(0));


    // Création de la grille de vecteur
    double*** grid = (double***)malloc(sizeof(double**)*grid_width);
    for(int i=0; i<grid_width; i++){
        grid[i] = (double**)malloc(sizeof(double*)*grid_height);
    }

    for(int i=0; i<grid_width; i++){
        for(int j=0; j<grid_height; j++){
            grid[i][j] = (double*)malloc(sizeof(double)*2);
        }
    }


    // Générateur de nombres aléatoires
    cv::RNG rng(cv::getTickCount());


    // Remplir la grille de vecteur
    for (int y = 0; y < grid_height; y++) {
        for (int x = 0; x < grid_width; x++) {
            double theta = rng.uniform(0.0, 2 * CV_PI); // Génération d'un angle aléatoire

            grid[y][x][0] = std::cos(theta); // x
            grid[y][x][1] = std::sin(theta); // y
        }
    }



    if (img.empty()) { // Vérification de si l'image existe
        cerr << "Erreur de lecture de l'image!" << endl;
        exit(EXIT_FAILURE);
    }


    for (int y = 0; y < img.rows; y++) {
        for (int x = 0; x < img.cols; x++) {
            
            uchar& pixel = img.at<uchar>(y, x); // Accéder aux valeurs RGB de chaque pixel

            // Si la valeur de R, G ou B est supérieur à 128, elle passe à 255 sinon 0
            pixel = pixel > 128?255:0;

        }
    }


    string fichier = "images/img.png";

    cv::imwrite(fichier.c_str(), img); // Sauvearde en fichier
    


    return EXIT_SUCCESS;
}
