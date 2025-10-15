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

    img_width = atoi(argv[1]);
    img_height = atoi(argv[2]);

    // Lire l'image
    // cv::Mat image = cv::imread(argv[1], cv::IMREAD_GRAYSCALE);

    cv::Mat img(img_width, img_height, CV_8UC1, cv::Scalar(70));

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
