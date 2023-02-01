#!/bin/bash
gcc backend.c frontend.c bot.c main.c -lncurses -o pentago

./pentago