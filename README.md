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
## Aprašymas apie perdengtus metodus (v1.2)
### Įvesties perdengimo metodai
- Duomenų įvestis rankiniu ir automatinių būdu įvyksta, kai duomenų skaitymui yra naudojamas `istream` objektas (šios programos atveju `std::cin`) t.y. programos eigos pasirinkimas - `"1" - Įvedimas ranka` ir `"2" - Generavimas`
- Duomenų įvestis iš failo įvyksta, kai duomenų skaitymui naudojamas `istringstream` objektas. t.y. programos eigos pasirinkimas - `"3" - Skaitymas iš failo`

### Išvesties perdengimo metodai
- Duomenų išvedimas per konsolę įvyksta, kai duomenų išvedimui yra naudojamas `ostream` objektas (šios programos atveju `std::cout`) t.y. programos eigos pasirinkimas - `"6" - Rezultatu išvedimas`
- Duomenų išvedimas į failą įvyksta, kai duomenų išvedimui yra naudojamas `ofstream` objektas t.y. programos eigos pasirinkimas - `"5" - Atrinkti studentus`

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
- Release v1.1 (2024-04-12)
Pilnas kodo peržiūrėjimas. Perėjimas nuo struct į class strukturą.
- Release v1.2 (2024-04-19)
Realizuotas "Rule of five" ir aprašyti įvesties ir išvesties operatoriai paprastesniam kodo rašymui