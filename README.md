# Sprawozdanie z projektu Pentago w jezyku C

Autor: Borys Adamiak

Data: 31.01.2023

## Wprowadzenie 
Projekt polega na implementacji bestsellerowej gry Pentago w jezyku C. Polega ona na ułożeniu pięciu kulek tego samego koloru pod rząd pionowo, poziomo lub na skos.  
Plansza (6x6) do gry podzielona jest na cztery plansze jak do gry kółko i krzyżyk (3x3). Ruch gracza polega na położeniu kulki w wolnym miejscu na planszy oraz obrócenie jednej z plansz o 90 stopni.

## Uzyte biblioteki
W kodzie użyłem standardowych bibliotek C takich jak stdio.h, stdlib.h, limits.h oraz string.h.  
Dodatkowo do stworzenia interfejsu graficznego użyłem biblioteki ncurses.h która pozwala operować terminalem.  

## Jak zagrać po raz pierwszy
Aby zagrać w grę Pentago należy miec pobraną bibliotekę ncurses. Jest ona dostepna na systemach operayjnych MacOS oraz Linux.  
W systemie Linux w terminal wystarczy wpisać komende:  
*sudo apt-get install ncurses-dev*  
W systemie MacOS natomiast:  
*brew install ncurses*  
  
Aby odpalić grę należy użyć pliku make.sh a konkretnie wpisać polecenie  
*./make.sh*  

## Przed rozgrywką

Interfejs daje nam wybór pomiędzy trzema opcjami: gra samodzielna (vs Bot), gra 1vs1 kontra znajomy oraz zakończenie programu. Wybór jest dokonywany przy użyciu strzałek na klawiaturze i zatwierdzany przy pomocy ENTER.

## Sterowanie

Sterowanie w grze Pentago jest intuicyjne. Wybieramy wolne pole na planszy, pole aktualne bedzie podświetlone, strzałkami na klawiaturze. Zatwierdzamy swój wybór przyciskiem ENTER. Nastepnie gra każe nam wybrać którą planszę chcemy obrócić. Po dokonaniu wyboru strzałkami i zatwierdzeniu ENTEREM wybieramy strzałkę w lewo bądź w prawo by określić, w którą stronę chcemy obrócić planszę.  

