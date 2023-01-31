# Sprawozdanie z projektu Pentago w jezyku C

Autor: Borys Adamiak

Data: \today

## Wprowadzenie 
Projekt polega na implementacji bestsellerowej gry Pentago w jezyku C. Polega ona na ułożeniu pięciu kulek tego samego koloru pod rząd pionowo, poziomo lub na skos.  
Plansza do gry podzielona jest na cztery plansze jak do gry kółko i krzyżyk. Ruch gracza polega na położeniu kulki w wolnym miejscu na planszy oraz obrócenie jednej z plansz o 90 stopni.

## Uzyte biblioteki
W kodzie użyłem standardowych bibliotek C takich jak stdio.h, stdlib.h, limits.h oraz string.h.  
Dodatkowo do stworzenia interfejsu graficznego użyłem biblioteki ncurses.h która pozwala operować terminalem.  

## Jak zagrać po raz pierwszy
Aby zagrać w grę Pentago należy miec pobraną bibliotekę ncurses. Jest ona dostepna na systemach operayjnych MacOS oraz Linux.  
W systemie Linux w terminal starczy wpisać komende:  
*sudo apt-get install ncurses-dev*  
W systemie MacOS natomiast:  
*brew install ncurses*  
