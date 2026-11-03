# Övningar dag 9 - Testning, debugging och felsökning

Arbeta självständigt med egen kod i egen mapp/kopia. Förutsäg före körning. Övningarna är träning, ingen examinerande inlämning. C++23 är redan valt.

## Delövning 1 - Gränser innan kod

Skriv en tabell för 0,79,80,100,-1 och 101. Implementera is_alarm och jämför med tabellen. Ogiltiga värden avvisas.

**Klart när:** Fyra giltiga resultat och två avvisade värden.

**Lösningsförslag:** skriv först själv. Jämför sedan med del 1 under Lösningsförslag till delövningarna och [01_boundary.cpp](01_boundary.cpp).

## Delövning 2 - Hitta loopfelet

Kör 02_debug.cpp i Debug. Stanna i total_values, följ index och total. Rätta din kopia utan att hårdkoda summan.

**Klart när:** 60 efter rättning och en förklaring av loopfelet.

**Lösningsförslag:** skriv först själv. Jämför sedan med del 2 under Lösningsförslag till delövningarna och [02_debug.cpp](02_debug.cpp).

## Delövning 3 - Gör ett rött test grönt

Kör 03_failing_test.cpp och kontrollera felstatus. Rätta faulty_alarm och lägg till kontroll för 79.

**Klart när:** Felaktig version upptäcks; rättad version ger status 0.

**Lösningsförslag:** skriv först själv. Jämför sedan med del 3 under Lösningsförslag till delövningarna och [03_failing_test.cpp](03_failing_test.cpp).

## Delövning 4 - Utöka kontrollerna

Skriv separata testprogram för parserns formatfel, tom statistik och en avvisad statistikuppdatering. Kontrollera tom rad, 1+20 och 1 20x. Kontrollera att add(101) lämnar tidigare count och sum oförändrade. Registrera varje program med eget namn i CTest och kör dem efter bygge. Kör därefter bara formatkontrollen med -R.

**Klart när:** Felen avvisas och tidigare statistik bevaras.

**Lösningsförslag:** skriv först själv. Jämför sedan med del 4 under Lösningsförslag till delövningarna och [testöversikten](tests/README.md).

## Avslutande uppgift - återskapa main.cpp

Skriv egen main.cpp och is_alarm. Giltiga värden är 0-100; larmgränsen är 80 inklusive. Kör 0,79,80,100 i denna ordning och skriv värde samt Normal eller Alarm. Prova sedan 101, fånga out_of_range och skriv Rejected. Lägg dessutom gränsfallen i ett separat testprogram som returnerar 1 vid fel. Materialets main.cpp visar applikationen och tests/ visar separata testprogram och deras CTest-namn.

Förväntad utskrift med angiven indata:

```text
0: Normal
79: Normal
80: Alarm
100: Alarm
Rejected
```

**Klart när:** du kan förklara flödet och få angivna resultat med egen kod. Studera sedan [main.cpp](main.cpp) som ett lösningsförslag, inte enda tillåtna lösning.

## Visa gärna för en klasskamrat

Visa egen lösning, ett gränsfall och varför du valt arbetssättet. Be om en fråga eller förbättring. Återkoppling är frivillig; utan kamrat gör du egen kontroll och antecknar vad som fungerar och vad du vill fråga läraren.

## Lösningsförslag till delövningarna

Använd efter eget försök. Filerna visar principen; anpassa till övningens indata.

### Del 1 - Gränser innan kod

Validera 0-100 först, därefter value >= 80. -1 och 101 kastar out_of_range; fånga dem i provprogrammet.

Jämför med [01_boundary.cpp](01_boundary.cpp) och bygg egen variant.

### Del 2 - Hitta loopfelet

Ersätt den ursprungliga loopen med en intervallbaserad loop. values är en rå array och har ingen medlemsfunktion size(). Alla tre värden 10, 20 och 30 ska läggas till.

```cpp
for (int value : values) {
    total += value;
}
```

Jämför med [02_debug.cpp](02_debug.cpp) och bygg egen variant.

### Del 3 - Gör ett rött test grönt

Byt > till >= och kontrollera att 79 ger false. Förväntan kommer från kravet, inte samma uttryck som implementationen.

Jämför med [03_failing_test.cpp](03_failing_test.cpp) och bygg egen variant.

### Del 4 - Utöka kontrollerna

Tom rad/tokenfel ger invalid_argument. mean på tom statistik ger logic_error. Spara count/sum efter add(20), fånga out_of_range från add(101) och jämför med sparade värden.

Jämför med [testöversikten](tests/README.md) och bygg egen variant.

### Den avslutande uppgiften

[main.cpp](main.cpp) är ett komplett lösningsförslag. Jämför ansvar, livstid, felhantering och resultat; alternativa lösningar kan vara lika korrekta.
