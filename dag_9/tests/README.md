# Tester för dag 9

Varje källfil är ett separat testprogram med en egen main. Programmet returnerar 0 när alla kontroller i just det testet lyckas och 1 när en kontroll misslyckas. Ett oväntat, ohanterat undantag får också testet att misslyckas. Inget externt testramverk används.

| CTest-namn | Källfil | Kontrollerar |
|---|---|---|
| day9_alarm_boundaries | [test_alarm_boundaries.cpp](test_alarm_boundaries.cpp) | Larm vid 80 inklusive och giltiga gränser |
| day9_alarm_invalid | [test_alarm_invalid.cpp](test_alarm_invalid.cpp) | Avvisning av -1 och 101 |
| day9_parser_valid | [test_parser_valid.cpp](test_parser_valid.cpp) | Korrekt tolkning med och utan omgivande blanksteg |
| day9_parser_format | [test_parser_format.cpp](test_parser_format.cpp) | Felaktigt format, extra text och tom rad |
| day9_parser_range | [test_parser_range.cpp](test_parser_range.cpp) | Otillåtna ID och mätvärden |
| day9_statistics_values | [test_statistics_values.cpp](test_statistics_values.cpp) | Antal, summa, minimum, maximum och medelvärde |
| day9_statistics_rejected_update | [test_statistics_rejected_update.cpp](test_statistics_rejected_update.cpp) | Undantag och oförändrat tillstånd efter add(101) |
| day9_statistics_empty | [test_statistics_empty.cpp](test_statistics_empty.cpp) | Undantag vid medelvärde utan mätvärden |

## Bygg och kör

Kör från dag_9. Konfigurera om efter att testregistreringen ändrats, bygg därefter och kör alla tester:

```sh
cmake -S . -B build -G Ninja -DCMAKE_BUILD_TYPE=Debug
cmake --build build
ctest --test-dir build --output-on-failure
```

Visa de registrerade testerna utan att köra dem:

```sh
ctest --test-dir build -N
```

Kör ett test med namnfilter. -R tolkar filtret som ett reguljärt uttryck; citattecknen bevarar uttrycket och ^/$ avgränsar hela testnamnet:

```sh
ctest --test-dir build -R "^day9_parser_format$" --output-on-failure
```

Kör enbart tester som misslyckades vid senaste körningen:

```sh
ctest --test-dir build --rerun-failed --output-on-failure
```

Den avsiktliga felversionen i 03_failing_test.cpp är en separat undervisningsdemo och ingår inte i denna testregistrering. Varje körfil byggs separat, men CTest samlar deras resultat i en rapport. Ett test kan innehålla flera närliggande indatafall; exempelvis testar parser_format flera formatfel. Programmen är oberoende och förutsätter ingen viss körordning.
