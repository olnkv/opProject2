
# Objektinio Programavimo Projektas
Ši programa skirta studentų duomenų nuskaitymui - vardas, pavardė, namų darbų rezultatai ir egzamino rezultatas, ir galutinio balo apskaičiavimas pagal nurodytus kriterijus.

## Įdiegimas (Mac)
1. Atidarykite sistemos terminalą
2. Įdiekite "Brew" (https://brew.sh/)
3. Įdiekite g++ kompiliatorių, įvesdami "brew install gcc"
4. Įdiekite makefile, įvesdami "brew install make"
5. Eikite į "code" katalogą, pavyzdžiui, įvedę "cd Desktop/User/opProject/code"
6. Įveskite "make", kad sukurtumėte išvesties failus
7. Įveskite "./output", kad paleistumėte programą
8. Jei norite ištrinti išvesties failus, įveskite “make clean”
## Įdiegimas (Windows)
1. Atsisiųskite ir įdiekite Msys2 (https://www.msys2.org/)
2. Atidarykite Msys2 terminalą
3. Įdiekite g++ kompiliatorių, įvesdami “pacman -S g++”
4. Įdiekite makefile, įvesdami “pacman -S make”
5. Eikite į “code” katalogą, pavyzdžiui, įvedę: “cd /c/Users/Name/Desktop/opProject/code”
6. Įveskite “make”, kad sukurtumėte išvesties failus
7. Įveskite “./output”, kad paleistumėte programą
8. Jei norite ištrinti išvesties failus, įveskite “make clean”
## Naudojimas
1. Paleiskite programą.
2. Pasirinkite programos eigos būdą įvesdami atitinkamus skaitmenys
3. Mielo naudojimosi!
## Autorius
Šį programinį produktą sukūrė Edvin Olenkovič
## Programos eigos testavimai
### Skaitymas iš failų
Testuojama tokiu būdu:
![alt text](https://github.com/olnkv/opProject/blob/v1.0/sc1.png)

Rezultatai:
![alt text](https://github.com/olnkv/opProject/blob/v1.0/sc2.png)
### Studentų rūšiavimas didėjimo tvarką pagal vidurkį
Testuojama tokiu būdu:
![alt text](https://github.com/olnkv/opProject/blob/v1.0/sc3.png)

Rezultatai:
![alt text](https://github.com/olnkv/opProject/blob/v1.0/sc4.png)
### Studentų skirtstymas į dvi kategorijas
Testuojama tokiu būdu:
![alt text](https://github.com/olnkv/opProject/blob/v1.0/sc5.png)

Rezultatai:
![alt text](https://github.com/olnkv/opProject/blob/v1.0/sc6.png)
## Changelog
- Pirmasis pre-release v.pradinė (2024-02-16)
Vartotojas gali įvesti duomenys pagal kuriuos atliekami galutinio balo skaičiavimai ir išvedami ant ekrano.
- Pre-release v0.1 (2024-02-16)
Namų darbų ir įrašų skaičiai neturi būti žinomi, tik įvedimo metu vartotojas nusprendžia kuomet jis jau įvedė visų namų darbų rezultatus ir kada jis baigią žmonių įvedimą.
- Pre-release v0.2 (2024-02-23)
Duomenys galima nuskaityti iš failo, bei įvesti ranka.
- Pre-release v0.3 (2024-02-29)
Atliktas kodo reorganizavimas (refactoring). Programa tikrina duomenų tikslumą, valdo išimtis.
- Pre-release v0.4 (2024-03-08)
Pridėtos failų generavimo, bei studentų paskirstymo ir rušiavimo funkcijos.
- Release v1.0 (2024-03-22)
Pridėtas konteinerio (vector, list, deque) pasirinkimas duomenų apdorojimui.