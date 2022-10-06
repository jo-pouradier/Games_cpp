mini projet en c++ avec la SFML :
    auteur : Joseph Pouradier Duteil


command linux pour executer le code:
    g++ <nom fichier>.cpp [autres fichier .cpp]  -o <chemin><nom executable> -I include -L lib -l 
    sfml-graphics -l sfml-window -l sfml-system

    "main_copie_test.cpp" : nom du fichier a compiler
    "/Users/.../executable/main" : directory de l'executable avec son nom
    "-I" : mise en place des include avec le nom du dossier correspondant
    "-L" : mise en place des lib avec le nom du dossier correspondant
    "-working-directory" : repertoire de travail (en vrai jsp a quoi ca sert)

    *** on peut ajouter "-w" pour ne pas afficher les warnings ***
    *** on peut ajouter "std=c++XX" pour changer la version de c++ utiliser ( XX = 98, 11, 14, 17, 20) ***
    *** pour executer un fichier avec des headers il faut ajouter les .cpp et l'options "-Wall" ***

command pour executer:
    ./executable/main

    le '.' permet de dire qu'on execute un fichier, ensuite on a le chemin du dit fichier.

erreur execution:
    "Undefined symbols for architecture x86_64"
        du au manque d'un fichier cpp dans la command pour creer l'executable

