#include <iostream>
#include <fstream>
#include <vector>
#include "ipud.h"


bool resuelveCaso() {
    iPud miPud;
    cancion s;
    artista a;
    int d;

    std::string orden;
    std::cin >> orden;

    if (!std::cin) return false;

    while (orden != "FIN") {
        try {
            if (orden == "addSong") {
                std::cin >> s >> a >> d;
                miPud.addSong(s, a, d);
            }
            else if (orden == "addToPlaylist") {
                std::cin >> s;
                miPud.addToPlaylist(s);
            }
            else if (orden == "play")
                miPud.play();
            else if (orden == "deleteSong") {
                std::cin >> s;
                miPud.deleteSong(s);
            }
            else if (orden == "totalTime")
                std::cout << "Tiempo total " << miPud.totalTime() << "\n";
            else if (orden == "recent") {
                std::cin >> d;
                std::list<cancion> lista = miPud.recent(d);
                if (!lista.empty()) {
                    std::cout << "Las " << lista.size() << " mas recientes\n";
                    for (auto const& c : lista)
                        std::cout << "    " << c << "\n";
                }
                else std::cout << "No hay canciones recientes\n";
            }
            else if (orden == "current")
                miPud.current();
        }
        catch (std::domain_error e) {
            std::cout << "ERROR " << e.what() << "\n";
        }
        std::cin >> orden;
    }
    std::cout << "----\n";

    return true;

}

int main() {

    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

    while (resuelveCaso());

    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    //system("PAUSE");
#endif

}